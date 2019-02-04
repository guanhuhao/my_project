// 2019-1-20 Zuhair and Strings.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <string>
using namespace std;
const int maxn = 2e5 + 10;
int findChildCnt(char* str1, char* str2)
{
	int len = strlen(str2);
	int cnt = 0;
	while (str1 = strstr(str1, str2)) // 如果查找到,则执行循环，否则为空退出循环
	{
		cnt++; // 统计次数
		str1 += len; // 加上偏移量，即移除str2
	}
	return cnt;
}
string s, p;
int nex[300005];
void makeNext()
{
	int q, k;
	int m = p.size();
	nex[0] = 0;
	for (q = 1, k = 0; q < m; ++q)
	{
		while (k > 0 && p[q] != p[k])
			k = nex[k - 1];
		if (p[q] == p[k])
		{
			k++;
		}
		nex[q] = k;
	}
}

int kmp()
{
	int ans = 0;
	int n, m;
	int i, q;
	n = s.size();
	m = p.size();
	makeNext();
	for (i = 0, q = 0; i < n; ++i)
	{
		while (q > 0 && p[q] != s[i])
			q = nex[q - 1];
		if (p[q] == s[i])
		{
			q++;
		}
		if (q == m)
		{
			++ans;
			q = 0;
		}
	}
	return ans;
}

int main()
{
	int n, m;
	int ans = 0;
	cin >> n >> m;
	cin >> s;
	for (int i = 'a'; i  <= 'z'; i++) {
		p.clear();
		for(int j=0;j<m;j++) p.push_back(i);
		ans=max(ans,kmp());
		//cout << cnt << endl;
		
	}
	cout << ans << endl;
    return 0;
}

