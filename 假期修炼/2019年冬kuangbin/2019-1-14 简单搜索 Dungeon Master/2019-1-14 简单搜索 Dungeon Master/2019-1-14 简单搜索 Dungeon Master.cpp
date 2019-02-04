// 2019-1-14 简单搜索 Dungeon Master.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct P {
	int l, r, c;
};
queue<P> que;
char mapp[35][35][35];
int t[35][35][35];
int l, r, c;
int check(P a) {
	return a.l < l&&a.l >= 0 && a.c < c&&a.c >= 0 && a.r >= 0 && a.r < r&&mapp[a.l][a.r][a.c] != '#'&&t[a.l][a.r][a.c]==-1;
}
void bfs(int sl, int sx, int sy) {
	t[sl][sx][sy] = 0;
	que.push(P{ sl,sx,sy });
	while (!que.empty()) {
		P top = que.front();
		que.pop();
		int temx[6] = { 0,0,0,0,1,-1 };
		int temy[6] = { 0,0,1,-1,0,0 };
		int temz[6] = { 1,-1,0,0,0,0 };
		for (int i = 0; i < 6; i++) {
			int xx = top.r + temx[i],
				yy = top.c + temy[i],
				zz = top.l + temz[i];
			if (check(P{ zz,xx,yy })) {
				que.push(P{ zz,xx,yy });
				t[zz][xx][yy] = t[top.l][top.r][top.c] + 1;
			}
		}
	}
}
int main()
{
	while (cin >> l >> r >> c&&l) {
		memset(t, -1, sizeof(t));
		int sl, sx, sy;
		int el, ex, ey;
		for (int i = 0; i < l; i++)
			for (int j = 0; j < r; j++)
				cin >> mapp[i][j];
		for (int i = 0; i < l; i++) 
			for(int j=0;j<r;j++)
				for(int k=0;k<c;k++)
					if (mapp[i][j][k] == 'S') {
						sl = i;
						sx = j;
						sy = k;
					}
					else if (mapp[i][j][k] == 'E') {
						el = i;
						ex = j;
						ey = k;
					}
		bfs(sl, sx, sy);
		if (t[el][ex][ey] == -1) cout << "Trapped!" << endl;
		else cout << "Escaped in " << t[el][ex][ey] << " minute(s)." << endl;
	}
    return 0;
}

