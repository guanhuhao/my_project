// 2018-8-18 D - 生日蛋糕.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#define min(a,b) (a<b?a:b)
using namespace std;
int ans = 1e9+7;	
int n, k;
int pin[105];
int mins[22], minv[22];
void dfs(int ceng, int r1, int remain,int v,int h) {
	if (ceng == k) {
		if (remain == 0) {	
			//cout << "text:" << ans << " " << v << endl;
			ans = min(ans, v);

		}
		return;
	}	
	//cout << "hahah" << endl;
	if (r1==0||h==0||v + 2 * remain / r1 > ans) return;
	if (remain<minv[k - ceng] || mins[k - ceng] + v>ans) return;
	r1 = min(r1, (int)sqrt(remain));
	for (int i = r1; i >=1 ; i--) {
		for (int j = min(remain/pin[i],h); j>=1; j--)
			dfs(ceng + 1, i - 1, remain - j*pin[i], v + j * 2 * i,j-1);
	}

}
int main()
{
	for (int i = 0; i < 105; i++) pin[i] = i*i;
	mins[0] = minv[0] = 0;
	for (int i = 1; i <= 20; i++) {
		mins[i] = mins[i - 1] + 2*i*i;
		minv[i] = minv[i - 1] + pin[i]*i;
	}
	cin >> n >> k;
	for (int i = 100; i >=1; i--)
		for (int j = n/pin[i]; j>=1; j--)
		{
			dfs(1, i - 1, n - j*pin[i], pin[i] + 2 * i*j,j-1);
			//cout << "text:" << ans << " " << i << " " << j << endl;
		}
	if (ans == 1e9 + 7)cout << 0 << endl;
	else cout << ans << endl;
    return 0;
}

