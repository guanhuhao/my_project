// 2018-7-22 B.Set（递归）.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[201];
//ll b[201];
struct BIG{
	ll num[201];
	void check() {
		for (int i = 200; i >= 1; i--) {
			num[i - 1] += num[i] / 10;
			num[i] = num[i] % 10;
		}
	}
	BIG(ll a = 0) {
		memset(num, 0, sizeof(num));
		num[200] = a;
		check();
	}
	void change(BIG &a) {
		for (int i = 0; i <= 200; i++) num[i] = a.num[i];
	}
	void print() {
		check();
		int flag = 0;
		for (int i = 0; i <= 200; i++) {
			if (num[i] == 0 && flag == 0) continue;
			else {
				flag = 1;
				//cout << i << "  ";
				printf("%lld", num[i]);
			}
		}
		printf("\n");
	}
	void change(ll a) {
		memset(num, 0, sizeof(num));
		num[200] = a;
		check();
	}
	void add(BIG b) {
		for (int i = 0; i <= 200; i++) num[i] += b.num[i];
		check();
	}
	void mul(int a) {
		for (int i = 0; i <= 200; i++) num[i] *= a;
		check();
	}
}b[201];
int main()
{
	for (int i = 1; i <= 100; i++) a[i] = i*i;
	ll n;
	while (cin >> n) {
		 BIG ans (0);
		b[n].change(a[n]);
		b[n - 1].change( a[n - 1]);
		for (int i = n-2; i >= 1; i--) {
			BIG tem (0);
			//tem.print();
			for (int j = i + 2; j <= n; j++) {
				tem.add(b[j]);
			}
			tem.add(BIG(1));
			tem.mul(i*i);
			b[i].change(tem);
		}
	  //  for (int i = 1; i <= n; i++) b[i].print();
		for (int i = 1; i <= n; i++) ans.add(b[i]);
		ans.print();
	}
    return 0;
}

