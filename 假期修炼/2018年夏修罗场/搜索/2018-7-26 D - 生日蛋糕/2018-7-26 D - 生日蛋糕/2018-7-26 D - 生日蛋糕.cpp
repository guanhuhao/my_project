// 2018-7-26 D - 生日蛋糕.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int biao[101];
int mini = 1e9;	
int n, m;
/*void dfs(int ren,int rem,int v,int max) {
	for (int i = max; i >= 1; i--) {
		if (i == 1 && rem >= 2) return;
		for (int h = 0;; h++) {
			if (ren - biao[i] * h < 0) break;
			if (h != 0 && rem == m) v = biao[i];
			if (v + 2 * i*h > mini) break;	
			if (rem == 0) {
				if (ren - biao[i] * h == 0) mini = min(mini, v + 2 * i*h);
				break;
			}
			if (i - 1 < 1) break;
			cout << ren - biao[i] * h<<"  "<<(h == 0 ? rem : rem - 1)<<" "<< v + 2 * i*h<<" "<< i - 1 << endl;
			//cout << mini<<"  "<< v + 2 * i*h << endl;
			//cout << h <<"  "<<biao[i]<< endl;

			dfs(ren - biao[i] * h, h == 0 ? rem : rem - 1, v + 2 * i*h, i - 1);
		}
	}
}*/
void dfs(int ren, int rem, int v, int max) {
	if (ren == 0 && rem == 0)mini = min(v, mini);
	for (int r = max; r >= 1; r--) {
		for (int h = 0;ren-r*r*h>=0; h++) {
			if (h == 0) dfs(ren, rem, v, r - 1);
			else {
				if (rem == m) v = r*r;
				//cout << mini << "  " << v + 2 * r*h << endl;
				cout << ren - biao[r] * h << "  " << (h == 0 ? rem : rem - 1) << " " << v + 2 * r*h << " " << r - 1 << endl;
				if(r!=1)dfs(ren - r*r*h, rem - 1, v + 2 * r*h,r-1);
			}
		}
	}
}
int main()
{
	for (int i = 1; i <= 100; i++) biao[i] = i*i;
	cin >> n >> m;
	dfs(n, m, 0, 100);
	cout << mini << endl;
    return 0;
}

