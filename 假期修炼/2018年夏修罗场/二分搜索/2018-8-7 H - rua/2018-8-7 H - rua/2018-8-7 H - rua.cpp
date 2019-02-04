// 2018-8-7 H - rua.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const double  mini = 1e-13;
typedef pair<int, int> P;
typedef long double lb;
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		lb tem;
		int num=0;
		cin >> tem;
		tem = pow(tem, 2 / (lb)3);
		while (tem + mini > 1) {
			tem -= 1;
			num+=1;
		}
		P l,r;
		l = P(0, 1); r = P(1, 1);
		
		while (l.second + r.second <= 100000) {
			lb mid = (lb)(l.first + r.first) / (l.second + r.second);

			if (tem < mid) {
				r.first = l.first+r.first;
				r.second = l.second+r.second;
			}
			else {
				l.first = r.first+l.first;
				l.second = r.second+l.second;
			}	

		}
		lb ll = (lb)l.first / l.second;
		lb rr = (lb)r.first / r.second;

		if (fabs(ll - tem) < fabs(rr - tem)) {
			int fenzi = l.first + num*l.second;
			int fenmu = l.second;
			fenzi = fenzi / (gcd(fenzi, fenmu));
			fenmu = fenmu / (gcd(fenzi, fenmu));
			cout << fenzi<< "/" << fenmu << endl;
		}
		else {
			int fenzi = r.first + num*r.second;
			int fenmu = r.second;
			fenzi = fenzi / (gcd(fenzi, fenmu));
			fenmu = fenmu / (gcd(fenzi, fenmu));
			cout << fenzi<< "/" << fenmu << endl;
		}
	}
    return 0;
}

