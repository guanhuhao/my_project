// 2018-8-23 A - Area.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
struct EDGE {
	double x1, y1, x2, y2;
}edge[2000];
struct vec {
	double x, y;
	vec operator - (vec a) {
		return vec{ x - a.x,y - a.y };
	}
};
double cross(vec a, vec b) {
	return a.x*b.y - a.y*b.x;
}
bool check(EDGE a, EDGE b) {
	vec p1 = { a.x1,a.y1 };
	vec p2 = { a.x2,a.y2 };
	vec q1 = { b.x1,b.y1 };
	vec q2 = { b.x2,b.y2 };
	double d1 = cross((p2 - p1),(q1 - p1));
	double d2 = cross((p2 - p1),(q2 - p1));
	double d3 = cross((q2 - q1),(p1 - q1));
	double d4 = cross((q2 - q1), (p2 - q1));
	return !(d1*d2<=0&&d3*d4<=0);
}
int main()
{
	int n;
	int k = 1;
	while (cin >> n&&n) {
		cin >> edge[0].x1 >> edge[0].y1;
		for (int i = 1; i < n; i++) {
			cin >> edge[i].x1 >> edge[i].y1;
			edge[i - 1].x2 = edge[i].x1;
			edge[i - 1].y2 = edge[i].y1;
		}
		edge[n - 1].x2 = edge[0].x1;
		edge[n - 1].y2 = edge[0].y1;
		int flag = 1;
		for (int i = 0; i < n; i++) {
		
			for (int j = i + 1; j < n; j++) {
				if ((j - i) % n == 1||(i==0&&j==n-1)) continue;	
				if (check(edge[i], edge[j]) == false) {
					//cout << "hahah" << endl;
					flag = 0;
					i = n + 1;
					break;
				}
			}
		}			
		double ans = 0;
		for (int i = 0; i < n; i++) {
			//cout << "text:" << edge[i].x1 << " " << edge[i].y1 << " " << edge[i].x2 << " " << edge[i].y2 << endl;
			vec a = { edge[i].x1,edge[i].y1 };
			vec b = { edge[i].x2,edge[i].y2 };
			ans += cross(a, b)/2.0;
		}
		ans = fabs(ans);
		cout << "Figure " << k++ << ": ";
		if (flag == 0||n<=2||ans<0.0000001) cout << "Impossible" << endl<<endl;
		else  printf("%.2lf\n\n", ans);
	}
    return 0;
}

