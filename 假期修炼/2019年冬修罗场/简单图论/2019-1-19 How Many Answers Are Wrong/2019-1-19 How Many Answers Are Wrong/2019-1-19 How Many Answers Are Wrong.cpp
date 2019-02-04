// 2019-1-19 How Many Answers Are Wrong.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int fat[maxn], dis[maxn];
int n,m;
void init() {
	for (int i = 0; i < maxn; i++) fat[i] = i;
	memset(dis, 0, sizeof(dis));
}
int findf(int x) {
	if (x == fat[x]) return x;
	int t = fat[x];
	fat[x] = findf(fat[x]);
	dis[x] += dis[t];           //虽说没借鉴模板类但是这句的确是看博客才理解的
	return fat[x];
}
void uni(int a,int b,int c){
	int fa = findf(a), 
		fb = findf(b);
	if (fa > fb) {
		fat[fb] = fa;
		dis[fb] = dis[a]-dis[b] - c;            //同上
	}
	else {
		fat[fa] = fb;
		dis[fa] = dis[b]-dis[a] + c;           //同上
	}
}
int main()
{
	while (cin >> n >> m) {
		init();
		int ans = 0;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			b++;
			if (findf(a) == findf(b)) {
				if (dis[a] != dis[b] + c) ans++;
			}
			else uni(a,b,c);
		}
		cout << ans << endl;
	}
    return 0;
}

