// 2018-7-1 A. Balloons.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
struct ball {
	int num;
	int v;
}a[11];
bool cmp(ball a, ball b) {
	return a.v < b.v;
}
int main()
{
	int n;
	cin >> n;
	int sum=0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].v;
		a[i].num = i;
		sum += a[i].v;
	}
	sort(a, a + n, cmp);
	//for (int i = 0; i < n; i++) cout << a[i].v << endl;
	//cout << sum << endl << 2 * a[0].v << endl;
	if (sum == 2 * a[0].v || sum - a[0].v == 0) printf("-1\n");
	else {
		printf("1\n%d", a[0].num+1);
	}
    return 0;
}

