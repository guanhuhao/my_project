// 2018-9-7  B. Non-Coprime Partition.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin >> a;
	int ans;
	if (a <= 2) cout << "No" << endl;
	else {
		if (a % 2 == 0)ans = a / 2;
		else ans = (a + 1) / 2;
		cout << "Yes" << endl;
		cout << "1 " << ans << endl;
		cout << a - 1 <<" ";
		for (int i = 1; i <= a; i++) {
			if (i == ans)continue;
			cout << i << " ";
		}
		cout << endl;
 	}

    return 0;
}

