#include <bits/stdc++.h>

using namespace std;
string pile;
int cnt;
int ghh[16], mxl[16], dzc[16];
int cntghh, cntmxl, cntdzc;
int haha = 3;
int mapp(char a) {
	if (a - 'A' < 0&&a>='0') return a - '0';
	if (a == 'J') return 10;
	if (a == 'Q') return 11;
	if (a == 'K') return 12;
	if (a == 'A') return 13;
	if (a < 15) {
		if (a < 10) return a + '0';
		else {
			if (a == 10) return 'J';
			if (a == 11) return 'Q';
			if (a == 12) return 'K';
			if (a == 13) return 'A';
		}
	}
}
void init() {
	cnt = 0;
	cntghh = cntmxl = cntdzc = 5;
	memset(ghh, 0, sizeof(ghh));
	memset(mxl, 0, sizeof(mxl));
	memset(dzc, 0, sizeof(dzc));
	for (int i = 0; i < 5; i++) ghh[mapp(pile[cnt++])]++;
	for (int i = 0; i < 5; i++) dzc[mapp(pile[cnt++])]++;
	for (int i = 0; i < 5; i++) mxl[mapp(pile[cnt++])]++;


}
int freeghh(){
	for (int i = 0; i <= 13; i++) {
		if (ghh[i] != 0) {
			ghh[i]--;
			cntghh--;
			if (cntghh == 0) return -1;
			return i;
		}
	}
}
int freemxl() {
	int ans = 0;
	if (mxl[11] != 0) ans = 11;
	else if (mxl[12] != 0) ans = 12;
	else if (mxl[10] != 0) ans = 10;
	else if (mxl[13] != 0) ans = 13;
	else {
		for (int i = 10; i >= 0; i--){
			if (mxl[i] != 0) {
				ans = i;
				break;
			}
		}
	}
	cntmxl--;
	mxl[ans]--;
	if (cnt == 0) return -1;
	return ans;
}
int freedzc() {
	int tem[14] = { 0,1,2,3,4,5,6,7,8,9,13,10,12,11 };
	int maxi = 0;
	for (int i = 0; i < 14; i++)
		if (dzc[maxi] < dzc[tem[i]]) maxi = tem[i];
	cntdzc--;
	dzc[maxi]--;
	if (cntdzc == 0) return -1;
	return maxi;
}
int main()
{
	//freopen("uno.in", "r", stdin);
	//freopen("check.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> pile;
	//while(cin>>pile){
		int flag = 0;
		int who = 1;
		init();
		flag = freeghh();

		while (cnt != 84 && flag != -1) {

			if (who == 0) {
				if (flag == 13) {
					flag = freeghh();
					cout <<haha++<<"   "<< "text:" << "ghh出了" << (char)mapp(flag) ;
					cout << "     手牌剩余： ";
					for (int i = 0; i <= 13; i++) if (ghh[i]) 		for (int j = 0; j<ghh[i]; j++)cout << (char)mapp(i);// << ":" << ghh[i] << " ";
					cout << endl;
				}
				else if (ghh[flag + 1] != 0) {
					ghh[flag + 1]--;
					cntghh--;
					flag++;
					cout << haha++ << "   " << "text:" << "ghh出了" << (char)mapp(flag);
					cout << "     手牌剩余： ";
					for (int i = 0; i <= 13; i++) if (ghh[i])		for (int j = 0; j<ghh[i]; j++)cout << (char)mapp(i);// << ":" << ghh[i] << " ";
					cout << endl;
					if (cntghh == 0) flag = -1;
				}
				else {
					cout << haha++ << "   " << "text:" << "ghh抽牌获得" << pile[cnt];// << "  cnt为：" << cnt;
					ghh[mapp(pile[cnt])]++;
					cntghh++;
					cnt++;
					cout << "     手牌剩余： ";
					for (int i = 0; i <= 13; i++)if (ghh[i]) 		for (int j = 0; j<ghh[i]; j++)cout << (char)mapp(i);// << ":" << ghh[i] << " ";
					cout << endl;
				}
			}
			else if (who == 1) {
				if (flag == 13) {
					flag = freedzc();
					cout << haha++ << "   " << "text:" << "dzc出了" << (char)mapp(flag);
					cout << "     手牌剩余： ";
					for (int i = 0; i <= 13; i++) if (dzc[i])		for (int j = 0; j<dzc[i]; j++)cout << (char)mapp(i);// << ":" << dzc[i] << " ";
					cout << endl;
				}else if (dzc[flag + 1] != 0) {
					dzc[flag + 1]--;
					cntdzc--;
					flag++;
					if (cntdzc == 0) flag = -1;
					cout << haha++ << "   " << "text:" << "dzc出了" << (char)mapp(flag) ;
					cout << "     手牌剩余： ";
					for (int i = 0; i <= 13; i++)if (dzc[i])		for (int j = 0; j<dzc[i]; j++) cout << (char)mapp(i);// << ":" << dzc[i] << " ";
					cout << endl;
				}
				else {
					dzc[mapp(pile[cnt])]++;
					cout << haha++ << "   " << "text:" << "dac抽牌获得" << pile[cnt]; //<< "  cnt为：" << cnt;
					cntdzc++;
					cnt++;

					cout << "     手牌剩余： ";
					for (int i = 0; i <= 13; i++)if (dzc[i]) 		for (int j = 0; j<dzc[i]; j++)cout << (char)mapp(i);// << ":" << dzc[i] << " ";
					cout << endl;
				}
			}
			else {
				if (flag == 13) {
					flag = freemxl();
					cout << haha++ << "   " << "text:" << "mxl出了" << (char)mapp(flag);
					cout << "     手牌剩余： ";
					for (int i = 0; i <= 13; i++)if (mxl[i]) 		for (int j = 0; j<mxl[i]; j++)cout << (char)mapp(i);// << ":" << mxl[i] << " ";
					cout << endl;
				}else if (mxl[flag + 1] != 0) {
					mxl[flag + 1]--;
					cntmxl--;
					flag++;
					if (cntmxl == 0) flag = -1;
					cout << haha++ << "   " << "text:" << "mxl出了" << (char)mapp(flag) ;
					cout << "     手牌剩余： ";
					for (int i = 0; i <= 13; i++) if (mxl[i])		for (int j = 0; j<mxl[i]; j++)cout << (char)mapp(i);// << ":" << mxl[i] << " ";
					cout << endl;
				}
				else {
					mxl[mapp(pile[cnt])]++;
					cntmxl++;
					cnt++;

					cout << "     手牌剩余： ";
					for (int i = 0; i <= 13; i++) if (mxl[i])		for (int j = 0; j<mxl[i]; j++)cout << (char)mapp(i);// << ":" << mxl[i] << " ";
					cout << endl;
				}
			}
			who = (who + 1) % 3;
		}
		if (flag == -1) {
			if (cntghh == 0) cout << 0 << endl;
			else if (cntdzc == 0) cout << 1 << endl;
			else cout << 2 << endl;
		}
		else {
			int sum[3] = {0};
			for (int i = 0; i <= 13; i++) sum[0] += ghh[i] * mapp(i);
			for (int i = 0; i <= 13; i++) sum[1] += dzc[i] * mapp(i);
			for (int i = 0; i <= 13; i++) sum[2] += mxl[i] * mapp(i);
			int mini = min(min(sum[0], sum[1]), sum[2]);
			for (int i = 2; i >= 0; i--) if (sum[i] == mini) cout << i << endl;
			//for (int i = 0; i < 3; i++) cout << sum[i] << "   ";
		}
	}
    return 0;
}
