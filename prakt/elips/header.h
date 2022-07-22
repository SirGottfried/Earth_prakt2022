#ifndef _LAB_H_
#define _LAB_H_
#include<string.h>
#include<time.h>
extern double elipsX(double x, double a, double b);
extern double elipsY(double x, double a, double b);
extern double line1(double k, double x);
extern double length(double x, double y, double h1);
extern double pointsX1(double x0, double y0, double k, double c, double l);
extern double pointsX2(double x0, double y0, double k, double c, double l);
extern void push_back(double*& arr, int& size, double value);
#endif