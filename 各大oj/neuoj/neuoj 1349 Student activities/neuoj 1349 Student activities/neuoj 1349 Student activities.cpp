// neuoj 1349 Student activities.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)111111 + 10;
int T, M, N;
int dis[maxn],head[maxn];
struct EDGE
{
	int u, v, next;
	EDGE(int uu = 0, int vv = 0, int nnext=0) { u = uu; v = vv; next = nnext; }
	EDGE(const EDGE& a) { u = a.u; v = a.v; next = a.next; }
}edge[maxn];
bool cmp(const EDGE& a, const EDGE&b)
{
	return a.v < b.v;
}
int dfs(int subor)   //找最近的上司
{
	if (dis[subor] != -1) return dis[subor];
	for (int i = head[subor]; i != -1; i = edge[i].next)
	{
		//printf("%d  %d\n", edge[i].u, dis[subor]);
		if (dfs(edge[i].u) >= dis[subor])
		{
			dis[subor] = dfs(edge[i].u) + 1;
		}
	}
	return dis[subor];
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		//memset(super, -1, sizeof(super));
		memset(head, -1, sizeof(head));
		memset(dis, -1, sizeof(dis));
		scanf("%d%d", &N, &M);
		for (int i = 0; i < M; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			edge[i] = EDGE(u, v,-1);
		}
		sort(edge, edge + M,cmp);
		//for (int i = 0; i < M; i++) cout << edge[i].u << "  " << edge[i].v << "  " << edge[i].next << endl<<endl;
		head[edge[0].v] = 0;
		for (int i = 1; i < M; i++)
		{
			if (edge[i].v == edge[i - 1].v) {
				edge[i - 1].next = i; 
				continue;
			}
			head[edge[i].v] = i;
		}		
		dis[0] = 1;
		//for (int i = 0; i < M; i++) cout << edge[i].u << "  " << edge[i].v <<"  "<<edge[i].next<< endl;
		int ans = -1;
		for (int i = 0; i < N; i++) {  ans = max(dfs(i), ans);}
		printf("%d\n", ans);
	}
    return 0;
}

