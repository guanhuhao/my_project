// 2018-11-10 formula.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> P;
double pow(double a) {
	return a*a;
}
double distant(P a, P b) {
	return pow(a.first - b.first)+pow(a.second - b.second);
}
double area1(double x, double y, double z) {
	return 0.25*sqrt(4 * x*y - pow(x + y - z));
}
int main()
{
	P p[3];
	double r;
	for (int i = 0; i < 3; i++) cin >> p[i].first >> p[i].second;
	cin >> r;
	double a = distant(p[0], p[1]);
	double b = distant(p[1], p[2]);
	double c = distant(p[0], p[2]);
	printf("%.3lf\n", (1 - area1(a, b, c) * 2 / (double)(sqrt(a) + sqrt(b) + sqrt(c)) / r)*-100);
    return 0;
}

