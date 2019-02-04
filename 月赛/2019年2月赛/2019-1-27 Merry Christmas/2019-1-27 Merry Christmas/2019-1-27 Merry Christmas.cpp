// 2019-1-27 Merry Christmas.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

char kuro1[15][15] = { "...........",".....*.....","....*.*....",".***...***.","..*.....*..","...**.**...","..*.....*..","..........." };
char yuki2[15][15] = { ".........","...***...","..*...*..","..*...*..","..*...*..",".*******.","....*....","........." };
char wyj3[15][15] = { ".......",".*.....",".*.....",".*.....",".*.....",".*...*.","..***..","......." };
char def4[15][15] = { "........",".*....*.","..*..*..",".******.","..*..*..",".*....*.","........" };
char hzs5[15][15] = { "......",".****.",".*..*.",".*..*.",".****.","......" };
char lby6[15][15] = { "...........","..*****....",".*.....*...","..*****....","..*...*....","..*...*....","..*....**..","..*......*.","..*******..","..........." };
char block7[15][15] = { "........","..****..",".*....*.",".*....*.","..****..","........" };
char mapp[55][55];
int vis[55][55];
int n, m;
void kuro(int x,int y) {
	int w=11, h=8;
	for (int i = 0; i < m; i++) {
		int flag = 0;
		int xx =(i+y)%m;             //xx=(i+y)%m;
		for (int j = 0; j < w; j++) {
			int ww = (xx + j) % m;       //ww=(xx+j)%k;
			for(int k=0;k<h;k++){
				if (vis[k+x][ww]) {       //vis[k+x][ww];
					flag = 1;
					j = w;
					k = h;
				}
			}
		}

		if (flag == 0) {
			for (int j = 0; j < w; j++) {
				int ww = (xx + j) % m;
				for (int k = 0; k < h; k++) {
					mapp[k+x][ww] = kuro1[j][k]; //mapp[k+x][ww];
					vis[k+x][ww] = 1;         //vis[k+x][ww]
				}
			}
			break;
		}
	}

}
void yuki(int x, int y) {
	int w = 9, h = 8;
	for (int i = 0; i < m; i++) {
		int flag = 0;
		int xx =(i+y)%m;
		for (int j = 0; j < w; j++) {
			int ww = (xx + j) % m;
			for (int k = 0; k < h; k++) {
				if (vis[k+x][ww]) {
					flag = 1;
					j = w;
					k = h;
				}
			}
		}

		if (flag == 0) {
			for (int j = 0; j < w; j++) {
				int ww = (xx + j) % m;
				for (int k = 0; k < h; k++) {
					mapp[k+x][ww] = yuki2[j][k];
					vis[k+x][ww] = 1;
				}
			}
			break;
		}
	}

}
void wyj(int x, int y) {
	int w = 7, h = 8;
	for (int i = 0; i < m; i++) {
		int flag = 0;
		int xx =(i+y)%m;
		for (int j = 0; j < w; j++) {
			int ww = (xx + j) % m;
			for (int k = 0; k < h; k++) {
				if (vis[k+x][ww]) {
					flag = 1;
					j = w;
					k = h;
				}
			}
		}

		if (flag == 0) {
			for (int j = 0; j < w; j++) {
				int ww = (xx + j) % m;
				for (int k = 0; k < h; k++) {
					mapp[k+x][ww] = wyj3[j][k];
					vis[k+x][ww] = 1;
				}
			}
			break;
		}
	}

}
void def(int x, int y) {
	int w = 8, h = 7;
	for (int i = 0; i < m; i++) {
		int flag = 0;
		int xx =(i+y)%m;
		for (int j = 0; j < w; j++) {
			int ww = (xx + j) % m;
			for (int k = 0; k < h; k++) {
				if (vis[k+x][ww]) {
					flag = 1;
					j = w;
					k = h;
				}
			}
		}

		if (flag == 0) {
			for (int j = 0; j < w; j++) {
				int ww = (xx + j) % m;
				for (int k = 0; k < h; k++) {
					mapp[k+x][ww] = def4[j][k];
					vis[k+x][ww] = 1;
				}
			}
			break;
		}
	}

}
void hzs(int x, int y) {
	int w = 6, h = 6;
	for (int i = 0; i < m; i++) {
		int flag = 0;
		int xx =(i+y)%m;
		for (int j = 0; j < w; j++) {
			int ww = (xx + j) % m;
			for (int k = 0; k < h; k++) {
				if (vis[k+x][ww]) {
					flag = 1;
					j = w;
					k = h;
				}
			}
		
		}

		if (flag == 0) {
			for (int j = 0; j < w; j++) {
				int ww = (xx + j) % m;
				for (int k = 0; k < h; k++) {
					mapp[k+x][ww] = hzs5[j][k];
					vis[k+x][ww] = 1;
				}
			}
			break;
		}
	}

}
void lby(int x, int y) {
	int w = 11, h = 10;
	for (int i = 0; i < m; i++) {
		int flag = 0;
		int xx =(i+y)%m;
		for (int j = 0; j < w; j++) {
			int ww = (xx + j) % m;
			for (int k = 0; k < h; k++) {
				if (vis[k+x][ww]) {
					flag = 1;
					j = w;
					k = h;
				}
			}
		}

		if (flag == 0) {
			for (int j = 0; j < w; j++) {
				int ww = (xx + j) % m;
				for (int k = 0; k < h; k++) {
					mapp[k+x][ww] = lby6[j][k];
					vis[k+x][ww] = 1;
				}
			}
			break;
		}
	}

}
void block(int x, int y) {
	int w = 8, h = 6;
	for (int i = 0; i < m; i++) {
		int flag = 0;
		int xx =(i+y)%m;
		for (int j = 0; j < w; j++) {
			int ww = (xx + j) % m;
			for (int k = 0; k < h; k++) {
				if (vis[k+x][ww]) {
					flag = 1;
					j = w;
					k = h;
				}
			}
		}

		if (flag == 0) {
			for (int j = 0; j < w; j++) {
				int ww = (xx + j) % m;
				for (int k = 0; k < h; k++) {
					mapp[k+x][ww] = block7[j][k];
					vis[k+x][ww] = 1;
				}
			}
			break;
		}
	}

}
void init() {
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 55; i++)
		for (int j = 0; j < 66; j++) mapp[i][j] = '.';
}
int main()
{
	freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		init();
		cin >> n >> m;
		int num;
		cin >> num;
		for (int i = 0; i < num; i++) {
			string name;
			int x, y;
			cin >> name >> x >> y;
			if (name == "Kuro/Neko") kuro(x,y);
			else if (name == "yuki") yuki(x, y);
			else if (name == "WYJ") wyj(x,y);
			else if (name == "Asm.Def") def(x, y);
			else if (name == "Haizs")hzs(x, y);
			else if (name == "lby")lby(x, y);
			else if (name == "BlockChanZJ")block(x, y);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				putchar(mapp[i][j]);
			putchar('\n');
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
