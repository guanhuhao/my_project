// 2019-1-29 An Easy Problem.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double eps = 1e-8;
struct Point {
	double x, y;
	Point(double a, double b) {
		x = a, y = b;
	}
	Point operator -(Point a) {
		return Point( x - a.x,y - a.y );
	};
	double operator *(Point a) {              //向量点乘
		return x * a.x + y * a.y;
	};
	Point() {};
}p[4];
struct Edge {
	double x1, x2, y1, y2;
	Edge(Point a, Point b) {
		x1 = a.x, y1 = a.y, x2 = b.x, y2 = b.y;
	}
};
bool zero(double a) {
	return a<eps&&a>-eps;
}
double cross(Point a, Point b) {              //向量叉乘
	return a.x*b.y - a.y*b.x;
}
bool IsIntersect(Edge a, Edge b) {          //是否相交  相交返回true
	Point
		a1 ( a.x1,a.y1 ),
		a2 ( a.x2,a.y2 ),
		b1 ( b.x1,b.y1 ),
		b2 ( b.x2,b.y2 );
	double
		d1 = cross(a1 - a2, b1 - a2),
		d2 = cross(a1 - a2, b2 - a2),
		d3 = cross(b1 - b2, a1 - b2),
		d4 = cross(b1 - b2, a2 - b2);
	//cout << "text:" << d1 << " " << d2 << " " << d3 << " " << d4 << endl;
	return (d1*d2 < eps && d3*d4 < eps);
}
Point cal_cross(Edge a, Edge b) {
	double
		x1 = a.x1, x2 = a.x2, x3 = b.x1, x4 = b.x2,
		y1 = a.y1, y2 = a.y2, y3 = b.y1, y4 = b.y2;
	double x = ((x3 - x4)*(y1 - y2)*x1 - (x1 - x2)*(y3 - y4)*x3 + (x1 - x2)*(x3 - x4)*(y3-y1)) / ((x3 - x4)*(y1 - y2) - (x1 - x2)*(y3 - y4));
	double y = y1 + (y1 - y2) / (x1 - x2)*(x - x1);
	if (zero(x - x1)) y = y3 + (y3 - y4) / (x3 - x4)*(x - x3);
	return Point(x, y);
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y >> p[3].x >> p[3].y;
		if (p[0].y < p[1].y) swap(p[0], p[1]);
		if (p[2].y < p[3].y) swap(p[2], p[3]);
		Edge a(p[0], p[1]),
			 b(p[2], p[3]);
		double k1 = (a.y1 - a.y2) / (a.x1 - a.x2);
		double k2 = (b.y1 - b.y2) / (b.x1 - b.x2);
		if (!IsIntersect(a, b)||zero(a.y1-a.y2)||zero(b.y1-b.y2)||zero(k1-k2)) {
			cout << "0.00" << endl;
		}
		else {
			Point crossp=cal_cross(a, b);
			//cout << "text:" << crossp.x << " "<<crossp.y << endl;
			/*if (k1*k2 > 0) {
				int flag = 0;
				if (k1 < 0) {
					if (k1 < k2&&min(a.x1, a.x2) < min(b.x1, b.x2)) flag = 1;
					else if (k2 < k1&&min(b.x1, b.x2) < min(a.x1, a.x2))flag = 1;
				}
				else {
					if (k1 > k2&&max(a.x1, a.x2) > max(b.x1, b.x2)) flag = 1;
					else if (k2 > k1&&max(b.x1, b.x2) > max(a.x1, a.x2)) flag = 1;
				}
				if(flag==1) {
					cout << "0.00" << endl;
					continue;
				}
			}*/
			if (IsIntersect(a, Edge(Point(b.x1, b.y1), Point(b.x1, 100000))) || IsIntersect(b, Edge(Point(a.x1, a.y1), Point(a.x1, 100000)))) {
				cout << "0.00" << endl;
				continue;
			}

			double ha = max(a.y1, a.y2),
				   hb = max(b.y1, b.y2);
			double h = min(ha, hb);
			
			double x1 = (h - a.y1)*(a.x1 - a.x2) / (a.y1 - a.y2) + a.x1,
				   x2 = (h - b.y1)*(b.x1 - b.x2) / (b.y1 - b.y2) + b.x1;
			//cout << "text:" << x1 << " " << x2 << " " << h << endl;


			double ans = fabs(x1 - x2)*(h - crossp.y) / 2;
			printf("%.2f\n", ans+eps);

		}

	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
