// 2018-5-29High School Become Human.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const double mini = 1e-10;
int main()
{
	long long x, y;
	cin >> x >> y;
	double ans = y*log((double)x)-x*log((double)y);
	if (ans > mini) cout << ">" << endl;
	else if (ans < -mini) cout << "<" << endl;
	else cout << "=" << endl;
    return 0;
}

