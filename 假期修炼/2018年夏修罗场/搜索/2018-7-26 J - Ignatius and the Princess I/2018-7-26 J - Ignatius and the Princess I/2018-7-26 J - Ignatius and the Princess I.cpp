// 2018-7-26 J - Ignatius and the Princess I.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
int n, m;
char a[110][110];
int ans[110][110];
struct cmp{
	bool operator ()(pair<int, int> a, pair<int, int> b) {
		return ans[a.first][a.second] > ans[b.first][b.second];
	}
};
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> que;
bool ok(int x, int y) {
	return x < n&&y < m&&x >= 0 && y >= 0;
}
void bfs() {
	int temx[4] = { 0,0,-1,1 };
	int temy[4] = { 1,-1,0,0 };
	while (!que.empty()) {
		int x = que.top().first, y = que.top().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + temx[i], ny = y + temy[i];
			if (ok(nx, ny) && a[nx][ny] != 'X'&&ans[nx][ny]==-1) {
				if (a[nx][ny] <= '9'&&a[nx][ny] >= '1') {
					ans[nx][ny] = ans[x][y] + a[nx][ny] - '0' + 1;
					que.push(pair<int, int>(nx, ny));
				}
				else if (a[nx][ny] == '.') {
					ans[nx][ny] = ans[x][y] + 1;
					que.push(pair<int, int>(nx, ny));
				}
			}
		}
	}
}
int main()
{
	stack<pair<int, int> >sta;
	while (cin >> n >> m) {
		while (!sta.empty()) sta.pop();
		memset(ans, -1, sizeof(ans));
		for (int i = 0; i < n; i++) cin >> a[i];
		que.push(pair<int, int>(0, 0));
		ans[0][0] = 0;

		bfs();
		/*cout << endl << endl;;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << ans[i][j] << "  ";
			cout << endl;
		}*/
		sta.push(pair<int, int>(n - 1, m - 1));

		if (ans[n - 1][m - 1] == -1) cout << "God please help our poor hero.\n";
		else {
			while(ans[sta.top().first][sta.top().second]){
				int temx[4] = { 0,0,1,-1 };
				int temy[4] = { 1,-1,0,0 };
				int recx, recy,mini=1000000;
				for (int i = 0; i < 4; i++) {
					int x = sta.top().first+temx[i], y = sta.top().second+temy[i];
					if (ok(x, y) && ans[x][y] != -1) {
						if (ans[x][y] < mini) {
							recx = x, recy = y,mini=ans[x][y];
						}
					}
				}
				sta.push(pair<int, int>(recx, recy));
				//cout << recx << "  " << recy << endl;
			}
			printf("It takes %d seconds to reach the target position, let me show you the way.\n", ans[n - 1][m - 1]);
			for (int i = 1; i <= ans[n - 1][m - 1]; i++) {
				int tema = ans[sta.top().first][sta.top().second];
				printf("%ds:(%d,%d)->", i, sta.top().first, sta.top().second);
				sta.pop();
				int temb = ans[sta.top().first][sta.top().second];
				printf("(%d,%d)\n", sta.top().first, sta.top().second);
				if (temb - tema > 1) {
					for (int j = 0; j < temb - 1-tema; j++) {
						i++;
						printf("%ds:FIGHT AT (%d,%d)\n", i, sta.top().first, sta.top().second);
					}
				}
			}
		}
		cout << "FINISH" << endl;
	}
    return 0;
}

