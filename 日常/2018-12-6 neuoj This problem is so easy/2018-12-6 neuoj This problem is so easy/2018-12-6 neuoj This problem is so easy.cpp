// 2018-12-6 neuoj This problem is so easy.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> fac;
int main()
{
	ll tem = 1080000002052;
	int factor = 2;
	cout << 20000000036 % 97 << endl;
	cout << ((long long)(1e10 + 19)%97)<< endl;
	while (factor*factor < tem) {
		if (tem%factor == 0) {
			cout << factor << " " << tem << endl;
			tem /= factor;
			fac.push_back(factor);
		}
		else factor++;
	}
	for (int i = 0; i < fac.size(); i++) cout << fac[i] << " ";
	cout << endl;
    return 0;
}

