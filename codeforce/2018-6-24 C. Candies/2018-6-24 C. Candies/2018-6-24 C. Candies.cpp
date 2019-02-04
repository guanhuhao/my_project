// 2018-6-24 C. Candies.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
/*int main()                      //before 
{
	long long n;

	cin >> n;
	while (n < 100) {
		long long ans = 0;
		int flag = 0;
		long long _count = 0;
		while (flag == 0) {
			ans++;
			long long tem = n;
			_count = 0;
			while (tem > 0) {
				tem = tem - ans;
				if ((long long)(tem*0.1) == 1) {

				}
				_count += (long long)(tem*0.1) - ans;
				if (_count > 10) break;
				tem -= (long long)(tem*0.1);
			}
		}
		cout << n<<endl<<ans << endl<<endl;
		n++;
	}
    return 0;
}*/
bool check(long long n, long long k) {
	long long tem = n;
	long long a = 0;
	while (tem) {
		a += min(k, tem);
		tem -= min(k, tem);
		tem = tem - tem / 10;
	}
	return 2*a >= n ;
}
int main() {
	long long n;
	long long ans;
	cin >> n;
	ans = n;
	long long l = 1, r = n;
	while (l <= r) {
		//cout << l << " " << r << endl;
		long long k = (l + r) / 2;
		if (check(n, k)) {
			ans = k;
			r = k-1;
		}
		else l = k+1;
	}
	cout << ans << endl;
}
