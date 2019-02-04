// 11292 the dragon of loowater.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 20000 + 10;
int head[maxn], man[maxn];
int main()
{
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && n == m) break;
		for (int i = 0; i < n; i++) cin >> head[i];
		for (int i = 0; i < m; i++) cin >> man[i];
		sort(head, head + n);
		sort(man, man + m);
		//for (int i = 0; i < n; i++) cout << head[i] << "  ";
		//cout << endl;
		//for (int i = 0; i < m; i++) cout << man[i] << "  ";
		//cout << endl;
		int j=0, k=0;
		int ans=0;
		int flag = 0;
		for (; j < n; j++) {
			for (; k < m; k++){
				if (head[j] <= man[k]){
					ans = man[k] + ans;
					k++;
					flag = j;
					break;
				}
			}
		}
		if (flag == n - 1) cout << ans << endl;
		else cout << "Loowater is doomed!"<< endl;
	}
    return 0;
}

