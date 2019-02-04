// 2019-1-19 Connections in Galaxy War.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <stack>
#include <vector>
using namespace std;
const int maxn = 1e4 + 10;
typedef pair<int, int> P;
struct Q {
	int flag, a;
};
int fat[maxn];
int power[maxn];
P p[maxn*2];
vector<P> edge;
vector<Q> question;
vector<int> ans;
map<P,int> check;
int n, m, q;

int findf(int x) {
	if (x == fat[x]) return x;
	return fat[x]=findf(fat[x]);
}
void uni(int a, int b) {
	int aa = findf(a),
		bb = findf(b);	
	if (aa == bb) return;
	if (power[aa] > power[bb] || (power[aa] == power[bb] && aa < bb))  fat[b] = aa;
	else fat[a] = bb;
	
}
void init() {
	for (int i = 0; i < maxn; i++) fat[i] = i;
	ans.clear();
	question.clear();
	edge.clear();
	check.clear();
}
int main()
{
	freopen("in.txt", "r", stdin);
	std::iostream::sync_with_stdio(false);
	int flag = 0;
	while (cin >> n) {
		if (flag) printf("\n");
		init();
		for (int i = 0; i < n; i++) cin >> power[i];
		cin >> m;
		for (int i = 0; i < m; i++) cin >> p[i].first >> p[i].second;
	
		cin >> q;
		for (int i = 0; i < q; i++) {
			string a;
			int b, c;
			cin >> a;
			if (a == "query") {
				cin >> b;
				question.push_back(Q{ 0,b });
			}
			else if (a == "destroy") {
				cin >> b >> c;
				question.push_back(Q{ 1,0 });
				check[P{ b,c }] = 1;
				edge.push_back(P{ b,c });
			}
		}
		for (int i = 0; i < m; i++) {
			if (check[p[i]]) continue;
			uni(p[i].first, p[i].second);
		}
		for (int i = question.size()-1; i >=0; i--) {
			if (question[i].flag == 0) ans.push_back(findf(question[i].a)==question[i].a?-1: findf(question[i].a));
			else {
				P topp = edge.back();
				edge.pop_back();
				uni(topp.first, topp.second);
			}
		}
		for(int i=ans.size()-1;i>=0;i--){
			if (ans[i] == 0) printf("-1\n");
			else printf("%d\n", ans[i]);
		}
		flag = 1;
	}
    return 0;
}

