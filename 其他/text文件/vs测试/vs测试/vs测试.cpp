#include"stdafx.h"
#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a[4] = { 1.23,35.36,635.7,4358.23 };
	int b[4] = { 1,2,100,10 };
	int i;
	cout.fill('*');
	for (int i = 0; i < 4; i++) {
		cout << setiosflags(ios_base::left)<<setw(10)
			<<a[i]<<endl<<cout<<setw(6)<<b[i]<<endl;
	}
	return 0;
}