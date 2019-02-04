// 2018-8-23 D - Cows.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct P {
	double x, y;
	P operator - (P a) {
		return P{ x - a.x,y - a.y };
	}
}p[10010];	
int n;
bool cmp(P a, P b) {
	return a.x < b.x || (a.x == b.x&&a.y < b.y);
}
vector<P> sta;
double cross(P a, P b) {
	return a.x*b.y - a.y*b.x;
}

void graham() {
	sta.clear();
	if (n <= 2) return ;
	sort(p, p + n, cmp);
	sta.push_back(p[0]);
	sta.push_back(p[1]);
	for (int i = 2; i < n; i++) {
		while (sta.size() > 1) {
			P p2 = *(sta.end() - 1);
			P p1 = *(sta.end() - 2);
			if (cross(p2 - p1, p[i] - p2) < 0) {
				sta.pop_back();
			}
			else break;
		}

		sta.push_back(p[i]);
	}
	int size = sta.size();
	sta.push_back(p[n - 2]);
	for (int i = n - 3; i >= 0; i--) {
		while (sta.size() > size) {
			P p2 = *(sta.end() - 1);
			P p1 = *(sta.end() - 2);
			if (cross(p2 - p1, p[i] - p2) < 0) {
				sta.pop_back();
			}
			else break;
		}
		sta.push_back(p[i]);
	}
	sta.pop_back();
}
int main()
{
	double ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
	graham();		

	for (int i = 0; i < sta.size()-1; i++) {
		ans += cross(sta[i], sta[i + 1]) / 2;
		//cout <<"text:"<< p[i].x <<" "<< p[i].y <<" "<<p[i+1].x<<" "<<p[i+1].y<< endl;
		//cout << "text:" << cross(p[i],p[i+1]) / 2 << endl;
	}
	ans += cross(sta[sta.size() - 1], sta[0]) / 2;
	cout << (int)(fabs(ans) / 50) << endl;
    return 0;
}

