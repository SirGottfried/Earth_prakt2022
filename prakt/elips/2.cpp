#include<iostream>
#include<math.h>
#include"header.h"
using namespace std;
double elipsX(double x, double a, double b) {
	double y = sqrt((a*b)/(b + a*(x*x)));
	return y;
}
double elipsY(double x, double a, double b) {
	double y = sqrt(b * (1 - (x * x) / a));
	return y;
}
double line1(double k, double x) { //пр€ма€, перпендикул€рна€ к высоте
	double c = (k*k*x + x)/k;
	return c;
}
double length(double x, double y, double h1) {
	double a = sqrt((x * x) + (y * y));
	double b = h1 - a;
	return b;
}
double pointsX1(double x0, double y0, double k, double c, double l) {//точки пересечени€ перпендикул€ра и пр€мых, проведенных с точки
	double k1 = 1 + (k * k);
	double k2 = (2 * x0) + (2 * y0 * k) - (2 * k * c);
	double k3 = (2 * y0 * c) - (c * c) - (x0 * x0) - (y0 * y0) + (l * l);
	double D = sqrt((k2 * k2) + (4 * k1 * k3));
	double x1 = (k2 + D) / (2 * k1);
	return x1;
}
double pointsX2(double x0, double y0, double k, double c, double l) {//точки пересечени€ перпендикул€ра и пр€мых, проведенных с точки
	double k1 = 1 + (k * k);
	double k2 = (2 * x0) + (2 * y0 * k) - (2 * k * c);
	double k3 = (2 * y0 * c) - (c * c) - (x0 * x0) - (y0 * y0) + (l * l);
	double D = sqrt((k2 * k2) + (4 * k1 * k3));
	double x2 = (k2 - D) / (2 * k1);
	return x2;
}
void push_back(double *&arr, int& size, double value) {//функци€ дл€ добавлени€ в массив последнего элемента и изменени€ размера 
	double* newArray = new double[size + 1];
	for (int i = 0; i < size; i++) {
		newArray[i] = arr[i];
	}
	newArray[size] = value;
	size++;
	delete[] arr;
	arr = newArray;
}