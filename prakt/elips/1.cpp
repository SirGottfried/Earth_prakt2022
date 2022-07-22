#include<iostream>
#include<math.h>
#include"header.h"
using namespace std;
int main(int argc, char* argv[]) {
	double n;
	double b;
	double l;
	double c;
	double m;
	double k;
	double pi = 3.14159;
	clock_t bg = clock();
	time_t en = clock();
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-?") == 0) {
			printf("[-?] - This application show difference between elips and a certain point of the plane.\nValues of parameters user selects.\n-f focus(mm) -p pixel(mm) -h height(km) -u angle(gradus)(km) -a elips(a^2)(km) -b elips(b^2)(km)");
			return 1;
		}
		if (strcmp(argv[i], "-v") == 0) {
			fprintf(stderr, "Work time: %lld sec", (en - bg) / CLOCKS_PER_SEC);
		}
		if (strcmp(argv[i], "-f") == 0) {//focus
			n = atof(argv[i + 1]);
			i = i + 2;
		}
		else
			return 1;
		if (strcmp(argv[i], "-p") == 0) {//pixel
			b = atof(argv[i + 1]);
			i = i + 2;
		}
		else
			return 1;
		if (strcmp(argv[i], "-h") == 0) {//height
			l = atof(argv[i + 1]);
			i = i + 2;
		}
		else
			return 1;
		if (strcmp(argv[i], "-u") == 0) {//angle
			c = atof(argv[i + 1]);
			i = i + 2;
		}
		else
			return 1;
		if (strcmp(argv[i], "-a") == 0) {//elips(a^2)
			m = atof(argv[i + 1]);
			i = i + 2;
		}
		else
			return 1;
		if (strcmp(argv[i], "-b") == 0) {//elips(b^2)
			k = atof(argv[i + 1]);
			i = i + 2;
		}
		else
			return 1;
	}
	double m0 = sqrt(((elipsX(tan(c * pi / 180), m, k)) * (elipsX(tan(c * pi / 180), m, k))) + ((elipsY(elipsX(tan(c * pi / 180), m, k), m, k)) * (elipsY(elipsX(tan(c * pi / 180), m, k), m, k))));//расстояние от центра к точке пересечения прямой
	double q = ((length(elipsX(tan(c * pi / 180), m, k), elipsY(elipsX(tan(c * pi / 180), m, k), m, k), l)) * b) / n;//расстояние от пересечения эллипса c высотой к спутнику
	double x1 = pointsX1(elipsX(tan(c * pi / 180), m, k), elipsY(elipsX(tan(c * pi / 180), m, k), m, k), (-1 / (tan(c * pi / 180))), line1(tan(c * pi / 180), elipsX(tan(c * pi / 180), m, k)), q);//первая точка(х1)
	double x2 = pointsX2(elipsX(tan(c * pi / 180), m, k), elipsY(elipsX(tan(c * pi / 180), m, k), m, k), (-1 / (tan(c * pi / 180))), line1(tan(c * pi / 180), elipsX(tan(c * pi / 180), m, k)), q);//вторая точка(х1)
	double y1 = ((-1 / (tan(c * pi / 180))) * x1) + line1(tan(c * pi / 180), elipsX(tan(c * pi / 180), m, k));//y1
	double y2 = ((-1 / (tan(c * pi / 180))) * x2) + line1(tan(c * pi / 180), elipsX(tan(c * pi / 180), m, k));//y2
	int size1 = 0;
	double* arr1 = new double[size1];
	if (n <= 0 || n >= 1000000 * q || b <= 0 || l <= 0 || l <= m0 || c < 0 || c > 360 || m <= 0 || k <= 0) {
		printf("Wrong values. See [-?]");
	}
	else {
		for (double g = -sqrt(m); g <= sqrt(m); g = g + 0.1) {
			push_back(arr1, size1, sqrt(((g - x1) * (g - x1)) + ((elipsY(g, m, k) - y1) * (elipsY(g, m, k) - y1))));
			push_back(arr1, size1, sqrt(((g - x1) * (g - x1)) + ((-elipsY(g, m, k) - y1) * (-elipsY(g, m, k) - y1))));
		}
		double min1 = arr1[0];
		for (int r = 1; r < size1; r++) {
			if (min1 > arr1[r]) min1 = arr1[r];
		}
		printf("First(km): %f\n", min1);
		printf("First(m): %f\n", min1*1000);
		printf("First(mm): %f\n", min1*1000000);
		int size2 = 0;
		double* arr2 = new double[size2];
		for (double g = -sqrt(m); g <= sqrt(m); g = g + 0.1) {
			push_back(arr2, size2, sqrt(((g - x2) * (g - x2)) + ((elipsY(g, m, k) - y2) * (elipsY(g, m, k) - y2))));
			push_back(arr2, size2, sqrt(((g - x2) * (g - x2)) + ((-elipsY(g, m, k) - y2) * (-elipsY(g, m, k) - y2))));
		}
		double min2 = arr2[0];
		for (int r = 1; r < size1; r++) {
			if (min2 > arr2[r]) min2 = arr2[r];
		}
		printf("Second(km): %f\n", min2);
		printf("Second(m): %f\n", min2*1000);
		printf("Second(mm): %f\n", min2*1000000);
	}
}