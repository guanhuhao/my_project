// 2018-10-4 A. Pieces of Parentheses.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
struct str {
	string ori;
	string aft;
	int l, r;
	int val;
};	
const int inf = -1e9;
str a[305];
int n;
int dp[305][90000 + 10];
int recl[305][90000 + 10];
bool cmp(str a, str b) {
	return a.r < b.r || (a.r == b.r&&a.l > b.l);
}
void init() {
	for (int i = 0; i < 305; i++) {
		a[i].ori.clear(); 
		a[i].aft.clear();
		a[i].l = 0; 
		a[i].r = 0;
	}
	memset(dp, -1, sizeof(dp));
	memset(recl, 0, sizeof(recl));
}
int fundp(int cnt,int remain) {		
	if (dp[cnt][remain] >= 0|| (dp[cnt][remain]<inf/2)) return dp[cnt][remain];
	if (n == cnt) {
		if (remain == 0)return 0;
		else return inf;
	}

	dp[cnt][remain] = max(fundp(cnt + 1, remain), fundp(cnt + 1, remain - a[cnt].val)+(int)a[cnt].ori.size());
	cout << "text:" <<dp[cnt][remain]<<" "<< cnt << " " << remain << " " << fundp(cnt + 1, remain) << " " << fundp(cnt + 1, remain - a[cnt].val) + (int)a[cnt].ori.size() << endl;
	return dp[cnt][remain];
	//recl[cnt + 1][remain - a[cnt].val] += recl[cnt][remain] + a[cnt].l - a[cnt].r;

}
int main()
{

	while (cin >> n) {
		init();
		for (int i = 0; i < n; i++) {
			cin >> a[i].ori;
			//cout << a[i].ori << endl;
			string &tem = a[i].ori;
			string &aft = a[i].aft;
			for (int j = 0; j <tem.size(); j++) {
				if (tem[j] == '(') aft.push_back('(');
				else if (aft.empty() || aft[aft.size() - 1] == ')') aft.push_back(')');
				else aft.pop_back();
			}
			for (int j = 0; j < aft.size(); j++) {
				if (aft[j] == ')') a[i].r = j + 1;
				else break;
			}
			a[i].l = aft.size() - a[i].r;
			a[i].val = a[i].l - a[i].r+300;	
		}
		sort(a, a + n, cmp);
		cout << "text:" << endl;
		for (int i = 0; i < n; i++) {
			cout << a[i].ori << " " << a[i].aft << " " << a[i].l << " " << a[i].r << " " <<a[i].val<< endl;
		}

		int ans = 1;
		for (int i = 1; i <= n; i++) {
			memset(dp, -1, sizeof(dp));
			fundp(0, i * 300);
			ans = max(ans, dp[0][i * 300]);
			cout << "text:" << i << endl;
		}
		cout << ans << endl;
	}

    return 0;
}

