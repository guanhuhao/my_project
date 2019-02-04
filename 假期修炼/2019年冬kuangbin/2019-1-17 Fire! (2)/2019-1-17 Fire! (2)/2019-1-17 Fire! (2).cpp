// 2019-1-17 Fire! (2).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
int n, m;
char mapp[1010][1010];
int disf[1010][1010];
int disp[1010][1010];
int dx[4] = { 0,0,-1,1 },
	dy[4] = { 1,-1,0,0 };
struct P {
	int x, y;
};
bool check(P a) {
	return a.x >= 0 && a.x < n&&a.y >= 0 && a.y < m && mapp[a.x][a.y]!='#';
}
void dfsf() {
	queue<P> que;
	memset(disf, -1, sizeof(disf));
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++) {
			if(mapp[i][j]=='F'){
				disf[i][j] = 0;
				que.push(P{ i,j });
			}
		}
	while (!que.empty()) {
		P p = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int xx = p.x + dx[i],
				yy = p.y + dy[i];
			if (xx<0 || xx >= n || yy<0 || yy >= m) //地图之外 
				continue;
			if (disf[xx][yy] != -1)                   //火之前已经烧到 
				continue;
			if (mapp[xx][yy] == '#')                   //是墙 
				continue;

			disf[xx][yy] = disf[p.x][p.y] + 1;
			que.push(P{ xx,yy });

		}

	}
}
int dfsp() {
	queue < P>que;	
	memset(disp, -1, sizeof(disp));
	for (int i = 0; i < n; i++) {
		for(int j=0;j<m;j++)
			if (mapp[i][j] == 'J') {
				que.push(P{ i,j });
				disp[i][j] = 0;
			}
	}
	while (!que.empty()) {
		P p = que.front();
		que.pop();
		if (p.x == 0 || p.x == n - 1 || p.y == 0 || p.y == m - 1) return disp[p.x][p.y]+1;
		for (int i = 0; i < 4; i++) {
			int xx = p.x + dx[i],
				yy = p.y + dy[i];

			if (disp[xx][yy] != -1)      //之前已经搜索过 
				continue;
			if (xx<0 || xx >= n || yy<0 || yy >= m)   //下一步在规定范围之外 
				continue;
			if (mapp[xx][yy] == '#')                //下一步是墙 
				continue;
			if (disf[xx][yy] != -1 && disp[p.x][p.y] + 1 >= disf[xx][yy])  //人最小到达的时间比火烧到的时间大 
				continue;


			disp[xx][yy] = disp[p.x][p.y] + 1;
			que.push(P{ xx,yy });
			
		}

	}
	return -1;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%s", mapp[i]);
		dfsf();
		int ans=dfsp();
		if (ans == -1) printf("IMPOSSIBLE\n");
		else printf("%d\n", ans);
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << disp[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << disf[i][j] << " ";
			cout << endl;
		}*/
	}
    return 0;
}

