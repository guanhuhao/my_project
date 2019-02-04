// 2018-8-24 C - Wall.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
struct Point {
	double x, y;
	Point operator - (Point a) {
		return Point{ x - a.x,y - a.y };
	}
}p[10000];
double cross(Point a, Point b) {
	return a.x*b.y - a.y*b.x;
}
bool cmp(Point a, Point b) {
	return a.x < b.x || (a.x == b.x&&a.y < b.y);
}
vector<Point> sta;
int main()
{
	int n, l;
	ios::sync_with_stdio(false);	
	cin >> n >> l;
	for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
	sort(p, p + n, cmp);
	sta.push_back(p[0]);
	sta.push_back(p[1]);
	for (int i = 2; i < n; i++) {
		while (sta.size() > 1) {
			Point p2 = *(sta.end() - 1);
			Point p1 = *(sta.end() - 2);
			if (cross(p2 - p1, p[i] - p2) < 0) sta.pop_back();
			else break;
		}
		sta.push_back(p[i]);
	}
	int size = sta.size();
	sta.push_back(p[n - 2]);
	for (int i = n - 3; i >= 0; i--) {
		while (sta.size() > size) {
			Point p2 = *(sta.end() - 1);
			Point p1 = *(sta.end() - 2);
			if (cross(p2 - p1, p[i] - p2) < 0) sta.pop_back();
			else break;
		}
		sta.push_back(p[i]);
	}
	sta.pop_back();
	size = sta.size();
	double ans = 0;
	for (int i = 0; i < size; i++) {
		double x = (sta[i].x - sta[(i + 1) % size].x);
		double y = (sta[i].y - sta[(i + 1) % size].y);
		ans += sqrt(x*x + y*y);
	}
	ans += 3.1415926*l * 2;
	cout << fixed << setprecision(0) << ans << endl;
	return 0;
}

