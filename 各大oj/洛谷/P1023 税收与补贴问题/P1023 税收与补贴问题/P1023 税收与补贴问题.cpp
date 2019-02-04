// P1023 税收与补贴问题.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 10;
int tar;
int init=0;
int _max;
int money[maxn] = {0};
int main()
{
	ios::sync_with_stdio(false);
	cin >> tar;
	int i = 0;
	int tem1, tem2;
	while (cin >> tem1 >> tem2)
	{
		if (!init) init = tem1;
		if (tem1 == -1 && tem2 == tem1) break;
		_max = tem1;
		money[tem1] = tem2;
		if (tem1 != init&&money[tem1 - 1] == 0)
		{
			int j;
			for (j = 0; money[tem1 - j - 1] == 0; j++);
			for (int k = 0; k < j; k++) money[tem1 - k - 1] = money[tem1] - (k + 1)*(money[tem1] - money[tem1 - j - 1]) / (j + 1);
		}
	}
	cin >> tem1;
	money[_max + 1] = money[_max] - tem1;
	_max++;
	int ans=0;
	int flag = 0;
	money[init - 1] = 1;
	while ((tar - ans-init)*money[tar] > (tar - ans + 1-init)*money[tar + 1] || (tar + ans-init)*money[tar] > (tar + ans - 1-init)*money[tar - 1])
	{
		//cout << "hahah" << endl;
		flag = 0;
		//cout << (tar - ans - init)*money[tar] << "   " << (tar - ans + 1 - init)*money[tar + 1] << "     " << (tar + ans - init)*money[tar] << "     " << (tar + ans - 1 - init)*money[tar - 1] << endl;
		if((tar - ans-init)*money[tar] > (tar - ans + 1-init)*money[tar + 1])
			for(int j=init;j<=_max;j++)
				if ((j - init - ans)*money[j] > (tar - ans - init)*money[tar]) {
					flag = 1;
					break;
					//cout << "1     " << j << "     " << (j - init - ans)*money[j] << "       " << (tar - ans - init)*money[tar] << endl;
				}
		if (flag == 0) break;
		if((tar + ans - init)*money[tar] > (tar + ans - 1 - init)*money[tar - 1]||(tar+ans-init==0))
			for(int j=init;j<=_max;j++)
				if ((j + ans - init)*money[j] > ((tar + ans - init)*money[tar])){
					flag = 1;
				//	cout << "2     " << j << "     " << (j + ans - init)*money[j] << "       " << (tar + ans - init)*money[tar] << endl;

					break;
				}

		if (flag == 0) break;
		ans++;
	}
	if (flag == 0&& (tar - ans - init)*money[tar] > (tar - ans + 1 - init)*money[tar + 1]) cout << -ans << endl;
	else if(flag==0&&(tar + ans - init)*money[tar] > (tar + ans - 1 - init)*money[tar - 1])cout << ans << endl;
	else cout << "NO SOLUTION" << endl;
}

