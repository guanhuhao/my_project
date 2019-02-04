#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int maxn = 150000 + 10;
int n, k, t[maxn], a[maxn], b[maxn], ans;
int f[maxn];
int getf(int x) { return x == f[x] ? x : f[x] = getf(f[x]); }
void unite(int x, int y)
{
	int a = getf(x), b = getf(y);
	if (a != b)f[b] = a;
	return;
}
int main()
{
	int T;
	cin >> T;
	while (T--) {
		scanf("%d", &n);
		/*for (int i = 0; i < k; i++)
			scanf("%d%d%d", &t[i], &a[i], &b[i]);*/
		for (int i = 0; i < 3 * n; i++)f[i] = i;
		for (int i = 0; i < n; i++)
		{
			string tp;
			int x, y;
			x = i;
			scanf("%d%s", &y, tp);
			if (tp == 'werewolf')
			{
				if (getf(x) == getf(y + n) || getf(x) == getf(y + 2 * n)) ans++;//���ڳԻ򱻳Թ�ϵ
				else
				{
					unite(x, y);
					unite(x + n, y + n);
					unite(x + n * 2, y + n * 2);//���������ϲ�
				}
			}
			else
			{
				if (getf(x) == getf(y) || getf(x) == getf(y + 2 * n)) ans++;//ͬ��򱻳Թ�ϵ
				else
				{
					unite(x, y + n);
					unite(x + n, y + 2 * n);
					unite(x + 2 * n, y);//����������ϲ�����ʾ�ԵĹ�ϵ
				}
			}
		}
		printf("%d\n 0", ans);
	}
	return 0;
}