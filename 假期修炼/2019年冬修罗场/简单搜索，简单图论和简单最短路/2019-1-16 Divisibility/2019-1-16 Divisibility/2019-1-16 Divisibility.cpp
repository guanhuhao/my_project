// 2019-1-16 Divisibility.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
int du[1010];
int edge[1010][1010];
long long int date[1010];
int sum,cnt;
int main()
{
	int T;
	cin >> T;
	while (T--) {
		sum = 0;
		memset(du, 0, sizeof(du));
		memset(edge, 0, sizeof(edge));
		int n;
		cin >> n;
		cnt = n;
		for (int i = 0; i < n; i++) cin >> date[i];
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				if (date[i] % date[j] != 0 && date[j] % date[i] != 0) {
					edge[i][j] = edge[j][i] = 1;
					++du[i];
					++du[j];
					++sum;
				}
	//	for (int i = 0; i < n; i++)cout << "text:" << du[i] << endl;
		while (sum != cnt*(cnt - 1) / 2) {
			//cout << sum << " " << cnt << endl;
			int mini;
			for (int i = 0; i < n; i++) 
				if (du[i] >= 0) {
					mini = i;
					break;
				}
			
			for (int i = mini + 1; i < n; i++) {
				if (du[i]>=0 && du[i] < du[mini])
					mini = i;
			}
			//cout << "text:" << du[mini] << endl;
			cnt--;
			sum -= du[mini];
			du[mini] = -1;
			for (int i = 0; i < n; i++) {
				if (edge[mini][i]) {
					du[i]--;
				}
			}
		}
		cout << cnt << endl;
	}
    return 0;
}

