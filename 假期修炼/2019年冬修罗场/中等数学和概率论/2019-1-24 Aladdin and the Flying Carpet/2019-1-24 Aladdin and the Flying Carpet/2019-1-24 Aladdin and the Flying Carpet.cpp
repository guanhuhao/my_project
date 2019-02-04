// 2019-1-24 Aladdin and the Flying Carpet.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;	
typedef pair<int, int> P;
const int maxn = 1e6 + 7;
int T,t=1;
ll a, b,rec;
vector<int> pri;
void prime() {
	pri.push_back(2);
	for (int i = 2; i < maxn; i++) {
		int flag = 0;
		for (int j = 2; j < sqrt(i) + 1; j++) {
			if (i%j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag) continue;
		pri.push_back(i);
	}
}

int main()
{	
	//freopen("in.txt", "r", stdin);
	prime();
	cin >> T;
	while (T--) {
		ll ans=1;
		cin >> a >> b;
		rec = a;
		for (int i = 0;i<pri.size()&& pri[i] <= a; i++) {
			int tem=0;
			while (a%pri[i] == 0) {
				tem++;
				a /= pri[i];
			}
			ans *= tem + 1;
		}
		if (a > 1) ans *= 2;
		//cout << "text:" << ans << endl;
		//if ((long long)sqrt(rec)*sqrt(rec) == rec) ans++;
		ans /= 2;
		if (rec < b*b) {
			printf("Case %d: 0\n", t++);
			continue;
		}
		for (int i = 1; i < b; i++) if (rec%i == 0) {
			ans--;
			//cout << i << endl;
		}
		printf("Case %d: %d\n", t++,ans);
	}
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
