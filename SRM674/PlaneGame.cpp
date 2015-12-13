// BEGIN CUT HERE

// END CUT HERE
#line 5 "PlaneGame.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define equals(a,b) fabs((a) - (b)) < EPS
#define EPS 1e-8


using namespace std;
typedef long long ll;

struct Point {
	double x, y;

	Point(double x=0, double y=0) : x(x), y(y) {}

	Point operator+(const Point &o) const { return Point(x+o.x, y+o.y); }

	Point operator-(const Point &o) const { return Point(x-o.x, y-o.y); }

	Point operator*(const double m) const { return Point(x*m, y*m); }

	Point operator/(const double d) const { return Point(x/d, y/d); }

	bool operator<(const Point &o) const { return x != o.x ? x < o.x : y < o.y; }

	bool operator==(const Point &o) const { return fabs(x-o.x) < EPS && fabs(y-o.y) < EPS; }

	double cross(const Point &o) const { return x * o.y - y * o.x; }

	double dot(const Point &o) const { return x * o.x + y * o.y; }

	double atan() const { return atan2(y, x); }

	double norm() const { return sqrt(dot(*this)); }

	double distance(const Point &o) const { return (o - (*this)).norm(); }

	double area(const Point &a,const Point &b) {
		Point p = a - (*this), p2 = b - (*this); 
		return p.cross(p2);
	}

	//線分abが自身に含まれているのかどうか判断する
	int between(const Point &a,const Point &b) {
		if(area(a,b) != 0) return 0;

		if(a.x != b.x)  return (((a.x <= x) && (x <= b.x)) || ((a.x >= x) && (x >= b.x)));
		else return (((a.y <= y) && (y <= b.y)) || ((a.y >= y) && (y >= b.y)));
	}      

	void print() {
		cout << "(" << x << "," << y << ")";
	}
};

class PlaneGame {
	public:
	int bestShot(vector <int> x, vector <int> y) {
		int n = x.size();
		vector<Point> p(n);
		rep(i, n) {
			p[i].x = x[i];
			p[i].y = y[i];
		}

		int ans = 0;
		bool used[55];
		memset(used, 0, sizeof(used));

		if(n == 1) return 1;

		rep(i, 5) {
			rep(j, 5) {
				if(i == j) continue;
				memset(used, 0, sizeof(used));

				used[i] = true;
				used[j] = true;

				Point a = (p[i] - p[j]);

				while(a.norm() < 100000) a = a * 2;
				Point b = (p[j] - p[i]);
				while(b.norm() < 100000) b = b * 2;

				Point sa = p[i] + a;
				Point sb = p[j] + b;

				cout << p[i].x << " " << p[i].y << " " << p[j].x << " " << p[j].y << endl;
				cout << sa.x << " " << sa.y << " " << sb.x << " " << sb.y << endl;

				int aa = 0;
				rep(k, n) {
					if(p[k].between(sa, sb)) {
						used[k] = true;
						aa++;
					}
				}

				cout << aa << " " << 0 << " " << 0 << " " << 0 << endl;
				rep(k, n) {
					if(used[k]) {
						cout << p[k].x << " " << p[k].y << " " << 0 << " " << 0 << endl;
					}
				}

				int ret = 0;
				int N[1000] = {0};
				rep(k, n) {
					int cnt = 0;
					rep(o, n) {
						if(equals((p[k]-p[o]).dot(sa-sb), 0.0) && !used[o]) {
							cnt++;
							N[k]++;
						}
						N[k]++;
					}

					ret = max(ret, cnt);
				}

				rep(k, n) {
					cout << N[k] << " " << 0 << " " << 0 << " " << 0 << endl;
					rep(o, n) {
						cout << p[k].x << " " << p[k].y << " " << p[o].x << " " << p[o].y << endl;
						if(equals((p[k]-p[o]).dot(sa-sb), 0.0) && !used[o]) {
							cout << p[o].x << " " << p[o].y << " " << 0 << " " << 0 << endl;
						}
					}
				}

				rep(k, n) {
					if(used[k]) ret++;
				}

				ans = max(ans ,ret);
			}
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, bestShot(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, -1, 1, 1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -1, -1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, bestShot(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 0, 1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, -1, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, bestShot(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, -3, 3, 3, -3, 0, 0, 3, -3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -3, -3, 3, 3, 3, -3, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(3, Arg2, bestShot(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(4, Arg2, bestShot(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {-1000000, -1, 999998, 1, -1001, 1000000, -999999, 999999, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000, 1, 1000000, -1, -999, 1000000, 0, 0, -999999, 999999}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(5, Arg2, bestShot(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PlaneGame ___test;

	// cout << fixed;
	// cout.precision(0);
    // ___test.run_test(-1);

	vector<int> x = {734, -411, -927, -752, -207, -424, -296, -295, 790, -158, 963, 309, -349, 39, -543, -899, 466, -875, 18, 417, 558, -142, -499, -809, 529, 964, 691, 280, -275, 98, -424, -350, 832, -879, 711, 98, -867, -1, 904, -426, -320, 3, 373, 286, 868, -184, -647, -39, 892, 841};
	vector<int> y = {-398, -726, -623, 925, -755, -60, 441, 83, 442, -72, -325, -858, -59, 873, -171, 471, -464, -727, 567, 120, 524, 600, 819, 827, 838, 834, -371, 778, -928, 187, 801, -77, -881, 85, 157, -654, 560, -579, 63, -212, -300, 831, 358, 289, -960, -312, 707, 620, 277, -260};
	//
	// // ans = 3;
	// //
	___test.bestShot(x, y);

	cout << x.size() << " " << y.size() << endl;
	
	// rep(i, x.size()) {
	// 	cout << x[i] << " " << y[i] << endl;
	// }
	return 0;
}
// END CUT HERE


