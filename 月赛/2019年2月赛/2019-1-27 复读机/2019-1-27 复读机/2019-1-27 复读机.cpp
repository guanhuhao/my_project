// 2019-1-27 复读机.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	int T;
	char str[110];
	cin >> T;
	getchar();
	while (T--) {
		string tar = { "you lose" };
		fgets(str, 110, stdin);
		str[strlen(str) - 1] = '\0';
		//cout << "text:" << str <<strlen(str)<< endl;
		int flag = 0;
		int flag2 = 0;
		char tem = str[strlen(str) - 1];
		if (tem == ' ' || (tem >= '0'&&tem <= '9') || (tem >= 'a'&&tem <= 'z') || (tem >= 'A' && tem <= 'Z')) {
			flag2 = 1;
			//cout << "text" <<tem<< endl;
		}
		for (int i = 0; i < tar.size(); i++) {
			if (i == 3 && str[3] != ' ') flag = 1;
			if (i != 3) if (str[i] != tar[i] && str[i] != tar[i] - ('a' - 'A')) {
				flag = 1;
			//	cout << str[i] << endl;
			}

		}
		//cout << "text:" << flag << " " << flag2 << endl;
		//cout << "text:" << strlen(str) << " " << tar.size() << endl;
		if ((flag == 0 && strlen(str) == tar.size()) || (flag == 0 && (strlen(str) == tar.size() + 1) && !flag2)) {
			cout << "Bling!" << endl;
		}
		else {
			if (!flag2) str[strlen(str)-1]='?';
			else {
				int cnt = strlen(str);
				str[cnt] = '?';
				str[cnt+1] = '\0';
				//cout << "text:" << str << endl;
			}
			cout << str << endl;
		}

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
