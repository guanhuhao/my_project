// 2018-7-14 C. Annoying Present.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	long long n, m;
	cin >> n >> m;
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		long long a, b;
		cin >> a >> b;
		ans += a*n;
		if (b < 0) {
			ans += ((n - 1) / 2 * ((n - 1) / 2 + 1))*b;
			if (n % 2 == 0) ans += b*n / 2;
		}
		else ans += b*n*(n - 1) / 2;
	}
	cout << setprecision(15) << fixed << (double)ans/n << endl;
	/*double n, m;
	double ans = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		double a, b;
		cin >> a >> b;
		ans = ans + a;
		if (b > 0) {
			double num = n - 1;
			ans +=n*b*(n - 1) / 2;
		}
		else if (b < 0) {
			long long tem = n;
			long long sum=0;
			sum = ((n-1)/ 2 * ((n-1) / 2 + 1))*b;

			if (tem % 2 == 0) sum = sum + tem / 2;
			ans += n*b*((double)sum) / n;
		}
	}
	cout <<setprecision(15)<<fixed<< ans << endl;*/
    return 0;
}

