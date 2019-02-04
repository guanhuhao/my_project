// 2018-8-3 E. Best Rational Approximation.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <queue>
using namespace std;

typedef pair<double, double> P;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main()
{
	int n;
	cin >> n;
	vector<P> v;
	

	for (int i = 1; i <= n; i++) {
		int k, num;
		double pi;
		int reci = 0;
		int recj = 0;
		cin >> k >> num >> pi;
		int j = 0;
		double mini = 1;
		for (int i = 1; i <= num; i++) {
			//cout << i << endl;
			for (;; j++) {
				if (abs((double)j / (double)i - pi) < abs((double)(j + 1) / (double)i - pi)) {
					//printf("%lf     %lf\n", (double)j / (double)i - pi, mini);
					if (abs((double)j / (double)i - pi) < mini) {
						mini = abs((double)j / (double)i - pi);
						if (mini <= 0.00000000001) {
							i = num + 1;
							break;
						}
						reci = i;
						recj = j;
						//v.push_back(P(j / (gcd(j, i)), i / (gcd(j, i))));
						//cout <<j << "  " << i << endl;
						//cout << (j / (gcd(j, i))) <<"  " << (i/(gcd(j, i))) << endl;
						if (j != (j / (gcd(j, i))))cout << j << " " << j / (gcd(j, i)) << endl;
						break;
					}
					while ((double)j / (double)i - pi > 0)j--;
					break;
				}
			}
		}
		v.push_back(P(1000000100, 100000100));
		for (int i = 0; i < v.size(); i++) {
			if (v[i].second > num) {
				cout << k << " " <<recj << "/" << reci << endl;
				break;
			}
		}
	}
    return 0;
}

