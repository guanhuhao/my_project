// Happy Number.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		int flag = 0;
		while (1) {
			int tem;
			if (n == 4) {
				flag = 1;
				break;
			}
			if (n == 1) break;
			tem = n;
			n = 0;
			while (tem != 0) {
				n += (tem % 10)*(tem % 10);
				tem /= 10;
			}
		}
		if (flag == 1) printf("UNHAPPY\n");
		else printf("HAPPY\n");
	}
    return 0;
}

