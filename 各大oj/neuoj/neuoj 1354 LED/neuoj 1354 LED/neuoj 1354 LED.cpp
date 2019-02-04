// neuoj 1354 LED.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
map<string, int> a;
void init()
{
	a["11101010101010101110"] = 0;
	a["00100010001000100010"] = 1;
	a["11100010111010001110"] = 2;
	a["11100010111000101110"] = 3;
	a["10101010111000100010"] = 4;
	a["11101000111000101110"] = 5;
	a["11101000111010101110"] = 6;
	a["11100010001000100010"] = 7;
	a["11101010111010101110"] = 8;
	a["11101010111000101110"] = 9;

	a["01000100111001000100"] = 10;
	a["00000000111000000000"] = 11;
	a["10101010010010101010"] = 12;
	a["01000000111000000100"] = 13;
	a["00001110000011100000"] = 14;
}
int main()
{
	int T;
	char tu[5][1010];
	int num[500], fuhao[500];
	scanf("%d", &T);
	while (T--)
	{
		int n;
		int count=0;
		fuhao[0] = 0;
		scanf("%d", &n);
		for (int i = 0; i < 5; i++) scanf("%s",tu[i]);
		for (int i = 0; i < n; i+=4)
		{
			init();
			char tem[21];
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 4; k++)
					tem[j * 4 + k] = tu[j][i + k];
			tem[20] = '\0';
			int temn =0;
			while (a[tem]< 10)
			{
				//printf("%d\n", a[tem]);
				temn = temn * 10 + a[tem];
				i += 4;
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 4; k++)
						tem[j * 4 + k] = tu[j][i + k];
				//printf("%s\n",tem);
			}
			num[count++] = temn;
			fuhao[count] = a[tem]-10;
		}
		//for (int i = 0; i < count; i++) printf("%d  %d\n", num[i], fuhao[i]);
		int ans=0;
		for (int i = 0; i < count; i++)
		{
			int flag;
			if (fuhao[i] == 0) flag = 0;
			else if (fuhao[i] == 1) flag = 1;
			int tem = num[i];
			while (fuhao[i + 1] == 2 || fuhao[i + 1] == 3)
			{
				i++;
				if (fuhao[i] == 2) tem = tem*num[i];
				else tem = tem / num[i];
			}
			ans = (flag == 0) ? ans + tem : ans - tem;
		}
		printf("%d\n", ans);
	}
    return 0;
}

