// 2018-9-4 F - Largest Rectangle in a.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct col {
	ll l, r, h;
};
vector<col> v;
stack<col> sta;
void init() {
	v.clear();
	while(!sta.empty())sta.pop();
}
int main()
{
	int n;
	while (cin >> n&&n) {
		init();	
		sta.push(col{ 0,0,-1 });
		for (long long i = 0; i < n; i++) {
			ll hei;
			cin >> hei;

			if (hei >= sta.top().h) sta.push(col{ i,i,hei });
			else {
				while (hei < sta.top().h) {
					col tem = sta.top();
					sta.pop();
					tem.r = i;
					v.push_back(tem);
				}
	
				sta.push(col{sta.top().r,i,hei });
			}
		}
		while (!sta.empty()) {
			col tem = sta.top();
			sta.pop();
			tem.r = n ;
			v.push_back(tem);
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			//cout << "text:" << v[i].l << " " << v[i].r <<" "<< v[i].h << endl;
			ans = max(ans, (v[i].r - v[i].l)*v[i].h);
		}
		cout <<ans<< endl;
	}
    return 0;
}

