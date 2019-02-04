// 2018-8-7 D - rua.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> P;	
P a, b, c, d,e,f;
double sa, sb, sc;
const double eps = 1e-9;
double dis(P a, P b) {
	return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}
double solve2(double tem) {
	f.first = c.first + (d.first-c.first)*tem;
	f.second = c.second + (d.second-c.second)*tem;
	return dis(e,f) / sc + dis(f,d)/sb;
}
double solve(double tem) {
	double ans ;
	e.first = a.first + (b.first-a.first)*tem;
	e.second = a.second + (b.second-a.second)*tem;
	double t1 = dis(a,e) / sa;
	//cout << "text:" << endl;
	double l = 0, r = 1;
	while (r - l > eps) {
		double mid = (r + l) / 2;
		double midd = (mid + r)/2;
		ans = solve2(mid);
		//cout << "text:" <<ans<< endl;
		if (ans <= solve2(midd)) {
			r = midd;
		}
		else l = mid;
	}
	return ans+t1;
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		double ans;
		cin >> a.first >> a.second >> b.first >> b.second;
		cin >> c.first >> c.second >> d.first >> d.second;
		cin >> sa >> sb >> sc;
		double l = 0.0,r=1.0;
		while (r - l > eps) {
			double mid = (r + l) / 2;
			double midd = (mid + r) / 2;
			//cout << "text:" << r << " " << l << endl;
			ans = solve(mid);
			//cout << "text:" << ans << endl;
			if (ans <= solve(midd)) {
				r = midd;
			}
			else l = mid;
		}
		cout <<fixed<<setprecision(2)<<ans << endl;
	}
    return 0;
}
