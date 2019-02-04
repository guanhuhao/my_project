// 各种排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <time.h>
using namespace std;	
int n;
void insert_sort(int(&a)[110],int n) {
	for (int i = 1; i < n; i++) {
		int tem = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > tem) {
			a[j + 1] = a[j];
			j--;
		}
		a[j+1] = tem;
	}
}

void merge_sort(int (&a)[110],int l,int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	merge_sort(a,l, mid);
	merge_sort(a,mid + 1, r);
	int ll = l, rr = mid + 1;
	vector<int> ans;	
	while (ll <= mid || rr <= r) {
		if ((a[ll] < a[rr]&&ll<=mid)||rr>r) ans.push_back(a[ll++]);  //这一句条件是个坑
		else ans.push_back(a[rr++]);
	}
	for (int i = 0; i <= r - l; i++)	a[i + l] = ans[i];

}

void quick_sort(int(&a)[110], int l, int  r) {
	if (l >= r) return;
	int low = l, high = r;
	int tem = a[low++];
	while (low < high) {
		while (a[high] >= tem&&low<high) high--;		
		while (a[low] < tem &&low < high)low++;
		swap(a[high], a[low]);
	}
	if (a[low] < tem) swap(a[low], a[l]);  //因为这两句我快调了2个小时（？） 这句作用应该是判断极限条件即最大值为初始值
	else low--;   //这个是判断极限条件即选取值是最小值

	quick_sort(a, l, low-1);
	quick_sort(a, low + 1, r);
}

void shell_sort(int(&a)[110], int len) {
	int n=len/2;
	while (n) {
		for (int i =0; i<n; i++) {
			for (int j = n; i + j < len; j+=n) {
				int tem = a[j];
				int k = j - n;
				while (k>=0&&a[k] > tem) {
					a[k + n] = a[k];
					k -= n;
				}
				a[k + n] = tem;
			}
		}
		n /= 2;
	}
}

void check(int a[],int n) {
	for (int i = 1; i < n; i++)
		if (a[i] < a[i - 1]) {
			cout << "wrong" << endl;
			return;
		}
	 
	cout << "accepted" << endl;
}

void check2(int a[], int b[],int n) {
	for(int i=0;i<n;i++) 
		if (a[i] != b[i]) {
			cout << "wrong" << endl;	
			for (int i = 0; i < n; i++) cout << a[i] << " ";
			cout << endl;
			for (int i = 0; i < n; i++) cout << b[i] << " ";
			cout << endl;
			return;
		}
	cout << "accepted" << endl;
	
}

int main()
{

	ios::sync_with_stdio(false);
	int a[110];	
	int b[110];
	freopen("in.txt", "r", stdin);
	clock_t t=clock();
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
			//cin >> b[i];
		}
		//shell_sort(a, n);
		//insert_sort(a, n);
		quick_sort(a, 0, n - 1);
		merge_sort(b, 0, n - 1);
		//check(a, n);
		check2(a, b, n);
		//for (int i = 0; i < n; i++) cout << b[i] << " ";
		//cout << endl;
	}
	cout << clock() - t << endl;
    return 0;

}

