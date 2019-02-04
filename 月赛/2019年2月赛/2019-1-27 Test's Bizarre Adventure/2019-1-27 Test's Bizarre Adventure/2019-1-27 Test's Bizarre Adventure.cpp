// 2019-1-27 Test's Bizarre Adventure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct P {
	int num1, time1;
	int num2, time2;
}p[505];
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int ans1, ans2;
		ans1 = ans2 = 1;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >>p[i].num1  >> p[i].time1;
			p[i].num2 = p[i].num1;
			p[i].time2 = p[i].time1;
			int k;
			cin >> k;
			for (int j = 0; j < k; j++) {
				int time, num;
				p[i].num2++;
				cin >> time >> num;
				p[i].time2 += time + (num - 1) * 20;
			}
		}
		int mynum, mytime;
		cin >> mynum >> mytime;
		for (int i = 0; i < n; i++) {
			if (p[i].num1 > mynum || (p[i].num1 == mynum && p[i].time1 < mytime)) ans1++;
			if (p[i].num2 > mynum || (p[i].num2 == mynum && p[i].time2 < mytime)) ans2++;
		}
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
