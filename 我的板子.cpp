//Kmp：求字符串出现次数
namespace KMP {
	string s, p;
	int nex[300005];
	void makeNext()
	{
		int q, k;
		int m = p.size();
		nex[0] = 0;
		for (q = 1, k = 0; q < m; ++q) {
			while (k > 0 && p[q] != p[k]) k = nex[k - 1];
			if (p[q] == p[k]) k++;
			nex[q] = k;
		}
	}

	int kmp()
	{
		int ans = 0;
		int n, m;
		int i, q;
		n = s.size();
		m = p.size();
		makeNext();
		for (i = 0, q = 0; i < n; ++i) {
			while (q > 0 && p[q] != s[i]) q = nex[q - 1];
			if (p[q] == s[i]) q++;
			if (q == m) {
				++ans;
				q = 0;
			}
		}
		return ans;
	}
}

namespace Tarjan{
	int DFN[maxn], LOW[maxn],fat[maxn];
	int belong;
	bool vis[maxn];	
	vector<int> S;
	//Tarjan: 联通分量计数, 缩点
	void tarjan(int s) {
		int i, p;
		DFN[s] = LOW[s] = ++index;
		S.push_back(s);
		vis[s] = 1;
		for (i = 0; i < edge[s].size(); i++) {
			int v = edge[s][i];
			if (!DFN[v]) {
				tarjan(v);
				LOW[s] = min(LOW[s], LOW[v]);
			}
			else if (vis[v]) LOW[s] = min(LOW[s], DFN[v]);
		}
		if (DFN[s] == LOW[s]) {
			int cnt = 0;
			belong++;
			do {
				p = S.back();
				S.pop_back();
				vis[p] = 0;
				fat[p] = belong;
				cnt++;

			} while (s != p);
			if (cnt)ans.push_back(cnt);
		}
		return;
	}
}

namespace GCD {
	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a%b);
	}
	int exgcd(int a, int b, int &x, int &y) {  //返回值为gcd（a，b）
		int d, x1, y1;
		if (b == 0) {
			d = a;
			x = 1;
			y = 0;
		}
		else {
			d = exgcd(b, a % b, &x1, &y1);
			x = y1;
			y = x1 - a / b * y1;
		}
		return d;
	}
}

namespace shai {
	linear_sieve() {                       //欧拉线性筛
		int prime[MAXN];
		int check[MAXL];
		int tot = 0;
		memset(check, 0, sizeof(check));
		for (int i = 2; i < MAXL; ++i) {
			if (!check[i]) prime[tot++] = i;
			for (int j = 0; j < tot; ++j) {
				if (i * prime[j] > MAXL) break;
				check[i*prime[j]] = 1;
				if (i % prime[j] == 0)break;
			}
		}
	}
}

namespace gauss {
	int  gauss(int n, int m) {
		int col, i, mxr, j, row;
		for (row = col = 1; row <= n && col <= m; row++, col++) {
			mxr = row;
			for (i = row + 1; i <= n; i++)
				if (fabs(a[i][col]) > fabs(a[mxr][col]))
					mxr = i;
			if (mxr != row) swap(a[row], a[mxr]);
			if (fabs(a[row][col]) < eps) {
				row--;
				continue;
			}
			for (i = 1; i <= n; i++)///消成上三角矩阵
				if (i != row && fabs(a[i][col]) > eps)
					for (j = m; j >= col; j--)
						a[i][j] -= a[row][j] / a[row][col] * a[i][col];
		}
		row--;
		for (int i = row; i >= 1; i--) {///回代成对角矩阵
			for (int j = i + 1; j <= row; j++) {
				a[i][m] -= a[j][m] * a[i][j];
			}
			a[i][m] /= a[i][i];
		}
		return row;
	}
}

namespace cal {
	double eps = 1e-6;
	bool zero(double a) {           //判零
		return a<eps&&a>-eps;
	}
	struct Point {
		double x, y;
		Point operator -(Point a) {
			return Point{ x - a.x,y - a.y };
		}
		Point operator +(Point a) {
			return Point{ x + a.x,y + a.y };
		}
		double operator *(Point a) {              //向量点乘
			return x * a.x + y * a.y;
		}
	};
	struct Edge {
		double x1, x2, y1, y2;
		Edge(Point a, Point b) {
			x1 = a.x, y1 = a.y, x2 = b.x, y2 = b.y;
		}
	};


	double cross(Point a, Point b) {              //向量叉乘
		return a.x*b.y - a.y*b.x;
	}

	bool IsIntersect(Edge a, Edge b) {          //线段相交  相交返回true  不判断交端点(可能)
		if (max(a.x1, a.x2) < min(b.x1, b.x2)) return false;        //快速排斥实验
		if (min(a.x1, a.y1) < max(b.x1, b.x2)) return false;
		if (max(a.y1, a.y2) < min(b.y1, b.y2)) return false;
		if (min(a.y1, a.y2) < max(b.y1, b.y2)) return false;
		
		Point                                     //跨立实验
			a1 = { a.x1,a.y1 },
			a2 = { a.x2,a.y2 },
			b1 = { b.x1,b.y1 },
			b2 = { b.x2,b.y2 };
		double
			d1 = cross(a1 - a2, b1 - a2),
			d2 = cross(a1 - a2, b2 - a2),
			d3 = cross(b1 - b2, a1 - b2),
			d4 = cross(b1 - b2, a2 - b2);
		return (d1*d2 <= eps && d3*d4 <= eps);	
	}

	Point cal_cross(Edge a, Edge b) {            //计算两线段交点
		double
			x1 = a.x1, x2 = a.x2, x3 = b.x1, x4 = b.x2,
			y1 = a.y1, y2 = a.y2, y3 = b.y1, y4 = b.y2;
		double x = ((x3 - x4)*(y1 - y2)*x1 - (x1 - x2)*(y3 - y4)*x3 + (x1 - x2)*(x3 - x4)*(y3 - y1)) / ((x3 - x4)*(y1 - y2) - (x1 - x2)*(y3 - y4));
		double y = y1 + (y1 - y2) / (x1 - x2)*(x - x1);
		if (zero(x - x1)) y = y3 + (y3 - y4) / (x3 - x4)*(x - x3);
		return Point(x, y);
	}

	namespace Graham{          //凸包扫描法
		int multi(Point p0, Point p1, Point p2)
		{
			return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
		}
		int cmp(Point p1, Point p2)               //极角排序sort的cmp原理还没看懂先放放
		{
			int x = multi(p1, p2, p[0]);
			if (x > 0 || (x == 0 && dis(p1, p[0]) < dis(p2, p[0]))) return 1;
			return 0;
		}
		void graham() {
			int s = 0;
			int d = 0;;
			for (int i = 1; i < n; i++)if (p[i].y < p[s].y || (p[i].y == p[s].y&&p[i].x < p[s].x)) s = i;
			swap(p[s], p[0]);
			ans.push_back(p[0]);
			sort(p + 1, p + n, cmp);
			for (int i = 1; i < n; i++) {
				while (ans.size() > 1) {
					Point b = *(ans.end() - 1);
					Point a = *(ans.end() - 2);
					if (cross(b - a, p[i] - a) < 0) ans.pop_back();
					else break;
				}
				ans.push_back(p[i]);
			}			
		}
	}
}