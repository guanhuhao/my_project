// 2018-10-11 C. Make It Equal.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
map<ll, ll> check;
vector<P> v;
bool cmp(P a, P b) {
	return a.first > b.first;
}
int main()
{
	ios::sync_with_stdio(false);
	ll n,k;
	ll mini = (ll)1e9 + 7;
	ll maxi = -1;
	cin >> n >> k;
	for (ll i = 0; i < n; i++) {
		ll tem;
		cin >> tem;
		maxi = max(maxi, tem);
		mini = min(mini, tem);
		check[tem]++;
	}
	for (auto i = check.begin(); i != check.end(); i++) {
		v.push_back(P{ i->first,i->second });
	}
	sort(v.begin(),v.end(),cmp);
	int size = v.size();
	for (int i = 1; i < size; i++) {
		v[i].second += v[i - 1].second;
	}
	ll ans = 0;
	for (int i = 0; i < size; i++) {
		if (v[i].second == n) break;
		ll once = k / v[i].second;		
		ll add = (v[i].first - v[i + 1].first) / once;
		ans += add;
		ll cnt = k-(v[i].first-v[i+1].first)*v[i].second;
		if (add*once==v[i].first-v[i+1].first) continue;
		while (cnt >= v[i + 1].second) {
			//cout << "text2:" << cnt << " "<<v[i+1].second << endl;
			if (v[i + 1].second == n) break;
			ll tem = cnt / v[i + 1].second;
			if (tem == 0) break;
			if (tem >= v[i + 1].first - v[i + 2].first) {
				cnt -= (v[i + 1].first - v[i + 2].first)*v[i + 1].second;
				i++;
				continue;
			}
			else {
				v[i + 1].first -= tem;
				break;
			}
		}
		ans++;
		//cout << "text:" << ans << endl;
	}
	cout << ans << endl;
    return 0;
}

