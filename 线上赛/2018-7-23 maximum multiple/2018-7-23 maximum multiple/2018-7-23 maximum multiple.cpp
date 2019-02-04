// 2018-7-23 maximum multiple.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000;

int gcd(int a, int b) {
	if (a%b == 0) return b;
	return gcd(b, a%b);
}
int main()
{
	for (int i = 1; i <= maxn; i++) {
		int low1 = i / 3;
		low1 = max(low1, 1);
		for (int j = i / 2; j >= low1; j--) {
			if (gcd(i, j) == j) {
				int low2 = i / 8;
				low2 = max(low2, 1);
				for (int k = j; k >= low2; k--) {
					if (i - k - j == 0) continue;
					if (i%k == 0 && i % (i - k - j) == 0) {
						long long xyz = (long long)i*i*i;
						
					//	printf("%d  %d  %d  %d  %lld  %lld  %lld\n", i, j, k, i - j - k,xyz%27,xyz%32,xyz%36);
						cout << i << " " << j << " " << k << " " << i - j - k <<" "<< xyz % (long long)27 <<" "<< xyz % (long long)32 << " " << xyz % (long long)36 << " " << endl;
						k = low2 - 1;
						j = low1 - 1;
					}
				}
			}
		}
	}
	system("pause");
    return 0;
}

