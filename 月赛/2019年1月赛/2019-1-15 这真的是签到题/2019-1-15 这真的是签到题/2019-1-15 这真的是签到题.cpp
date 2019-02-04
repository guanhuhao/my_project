// 2019-1-15 这真的是签到题.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
namespace fastIO {
#define BUF_SIZE 100000
	//fread -> read
	bool IOerror = 0;
	inline char nc() {
		static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
		if (p1 == pend) {
			p1 = buf;
			pend = buf + fread(buf, 1, BUF_SIZE, stdin);
			if (pend == p1) {
				IOerror = 1;
				return -1;
			}
		}
		return *p1++;
	}
	inline bool blank(char ch) {
		return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
	}
	inline void read(long long int &x) {
		char ch;
		while (blank(ch = nc()));
		if (IOerror)
			return;
		for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
	}
#undef BUF_SIZE
};
/*map<long long int,int> check;
typedef pair<long long int, int> P;
queue<P> que;


void init() {
	que.push(P{(long long int)1,1});
	long long int tem = (long long int)1 << 61;
	//int size=0;
	while (!que.empty()) {
		//size = max((unsigned int)size, que.size() * sizeof(que.front()));
		P top = que.front();
		que.pop();
		//cout << top.first << endl;
		check[top.first] = 1;
		if (top.first * 2 < tem) que.push(P{ top.first * 2,top.second });
		if (top.first * 2 + 1 < tem&&top.second < 3)que.push(P{ top.first * 2 + 1,top.second + 1 });
	}
	//cout << size << endl;
}*/
int main()
{
	long long int T;
	long long int a;
	//init();

	fastIO::read(T);
	while (T--) {	
		int cnt = 0;
		fastIO::read(a);
		while (a) {
			a &= (a - 1);
			cnt++;
		}
		if (cnt<=3) printf("Yes\n");
		else printf("No\n");
	}

    return 0;
}

