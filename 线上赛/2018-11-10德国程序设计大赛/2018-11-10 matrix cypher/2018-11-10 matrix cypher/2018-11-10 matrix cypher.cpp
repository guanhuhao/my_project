// 2018-11-10 matrix cypher.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
//typedef  long long __128int;
void scan(__int128 &x)//输入
{
	x = 0; int f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-')f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - 48; ch = getchar(); }
	x *= f;
}
int main()
{
	string ans;
	long long a, b, c, d;
	scan(a);
	scan(b);
	scan(c);
	scan(d);
	while (a != 1||d!=1||b!=0||c!=0) {
		if (a > b) {
			a -= b;
			c -= d;
			ans.push_back('0');
		}
		else {
			b -= a;
			d -= c;
			ans.push_back('1');
		}
	}
	//cout << "text:" << a << " " << b << " " << c << " " << d<<endl;
	for (int i = ans.size() - 1; i >-1; i--)
		cout << ans[i];
	cout << endl;
    return 0;
}

