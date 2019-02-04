// 2018-9-23 D. Vasya and Triangle.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
bool cmp(ll a, ll b) {
	return a > b;
}
ll maximum = 1;
void dfs(ll deep, ll cur,ll maxi) {
	if (cur > maxi) return ;	
	maximum = max(maximum, cur);
//	cout << "text:" << deep << " " << cur << " " << endl;
	if (deep >= v.size()||maximum==maxi) return;
	dfs(deep + 1, cur*v[deep], maxi);
	dfs(deep + 1, cur, maxi);


	return;
}
int main()
{
	ll n, m, k;
	cin >> n >> m >> k;
	if (2 * n*m%k != 0) {
		cout << "NO" << endl;
		return 0;
	}
	ll tem = 2 * n*m/k;
	ll temn = n,temm=m;
	for (int i = 2; i <= sqrt(temn); i++) {
		while (temn%i == 0) {
			v.push_back(i);
			temn /= i;
		}
	}

	v.push_back(temn);
	int cntn = v.size();
	for (int i = 2; i <= sqrt(temm); i++) {
		while (temm%i == 0) {
			//cout << "text:" << temm << " " << i << endl;
			v.push_back(i);
			temm /= i;
		}
	}	//cout << "hahha" << endl;
	v.push_back(temm);	
	v.push_back(2);
	//cout << " hahah" << endl;
	for (int i = 0; i < v.size(); i++) {
		if (k%v[i] == 0) {
			k /= v[i];
			v[i] = 1;
		}
	}

	sort(v.begin(), v.end(),cmp);
	while (v.size() >= 1 && v[v.size() - 1] == 1) {
		v.pop_back();
		//cout << "hahha" << endl;
	}
	
	ll maxi = max(m, n), mini = min(m, n);
	dfs(0, 1, maxi);
	ll mul=1;
	for (int i = 0; i < v.size(); i++) mul *= v[i];
	//for (int i = 0; i < v.size(); i++) cout << "text:" << v[i] <<  endl;
	//cout << "text:" << mul << endl;
	if (maxi < maximum || mini < mul / maxi) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		cout << "0 0" << endl;
		if (n > m) cout << maximum << " " << 0 << endl << 0 << " " << mul/maximum << endl;
		else cout << mul/maximum << " " << 0 << endl << 0 << " " << maximum << endl;
	}
    return 0;
}

