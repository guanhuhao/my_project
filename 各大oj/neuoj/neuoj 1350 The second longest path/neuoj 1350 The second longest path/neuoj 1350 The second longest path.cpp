#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = (int)1e5 + 10;
int n;
int flag[maxn], dis[maxn],head[maxn];
struct EDGE
{
	int u, v,next;
	EDGE(int uu = 0, int vv = 0, int nnext = -1) { u = uu; v = vv; next = nnext; }
	EDGE(const EDGE& a) { u = a.u; v = a.v; next = a.next; }
}edge[maxn*3];
bool cmp(const EDGE& a, const EDGE& b)
{
	return a.u < b.u;
}
void bfs(int rt)
{
	memset(flag, 0, sizeof(flag));
	memset(dis, 0, sizeof(dis));
	queue<int> q;		
	while (!q.empty())  q.pop(); 
	q.push(rt);
	flag[rt] = 1;
	dis[rt] = 0;
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		for (int i = head[top];i!=-1; i = edge[i].next)
		{
			//cout << edge[i].v <<"  "<<edge[i].next<< endl;
			
			if (flag[edge[i].v] == 1)continue;
			dis[edge[i].v] = dis[edge[i].u] + 1;
			q.push(edge[i].v);
			flag[edge[i].v] = 1;
		}

	}
}
int main()
{
	while (cin >> n)
	{
		memset(head, 0, sizeof(head));
		for (int i = 0; i < 2*(n-1); i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			edge[i++] = EDGE{ u,v,-1};
			edge[i] = EDGE{ v,u,-1 };
		}
		sort(edge, edge + 2*(n-1),cmp);
		//for (int i = 0; i < 2 * (n - 1); i++) cout << edge[i].u << "  " << edge[i].v <<"  "<<edge[i].next<< endl;
		head[edge[0].u] = 0;

		for (int i = 1; i <2*(n-1); i++)
		{
			if (edge[i - 1].u == edge[i].u) { edge[i - 1].next = i; continue; }
			head[edge[i].u] = i;
		}		
		bfs(edge[0].u);
		//for (int i = 0; i <= n; i++) cout <<i<<"  "<< dis[i] << endl;
		int max = -1;
		int rt=1;
		for (int i = 0; i <= n; i++)
		{
			if (max < dis[i])
			{
				max = dis[i];
				rt = i;
			}
		}
		bfs(rt);
		max = -1;
		int count=0;
		for (int i = 0; i <= n; i++)
		{
			if (max < dis[i])
			{
				max = dis[i];
				rt = i;
				count = 1;
			}
			else if (max == dis[i]) { count++; }
		}
		if (count >= 2) {
			printf("%d\n", max); 
			continue;
		}
		bfs(rt);
		max = -1;
		count = 0;
		for (int i = 0; i <= n; i++)
		{
			if (max < dis[i])
			{
				max = dis[i];
				rt = i;
				count = 1;
			}
			else if (max == dis[i]) { count++; }
		}
		if (count >= 2) printf("%d\n", max);
		else printf("%d\n", max - 1);

	}
	return 0;
}