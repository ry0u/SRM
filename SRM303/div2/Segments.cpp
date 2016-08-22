// BEGIN CUT HERE

// END CUT HERE
#line 5 "Segments.cpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair
#define EPS 1e-8
#define equals(a,b) fabs((a) - (b)) < EPS

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct Point {
	double x, y;

	Point(double x=0, double y=0) : x(x), y(y) {}

	Point operator+(const Point &o) const { return Point(x+o.x, y+o.y); }

	Point operator-(const Point &o) const { return Point(x-o.x, y-o.y); }

	Point operator*(const double m) const { return Point(x*m, y*m); }

	Point operator/(const double d) const { return Point(x/d, y/d); }

	bool operator<(const Point &o) const { return x != o.x ? x < o.x : y < o.y; }

	bool operator==(const Point &o) const { return fabs(x-o.x) < EPS && fabs(y-o.y) < EPS; }
};

ostream& operator << (ostream& os, const Point& p) {
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}

double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
double atan(Point p) { return atan2(p.y, p.x); }
double norm(Point p) { return p.x * p.x + p.y * p.y; }
double abs(Point p) { return sqrt(norm(p)); }
double distancePP(Point p, Point o) { return sqrt(norm(o - p)); }

int ccw(Point a, Point b, Point c) {
	b = b-a;
	c = c-a;

	if(cross(b, c) > 0.0) return +1;	//conter clockwise
	if(cross(b, c) < 0.0) return -1;	//clockwise
	if(dot(b, c) < 0.0) return +2;	//a on Seg(b,c)
	if(norm(b) < norm(c)) return -2;	//b on Seg(a,c)
	return 0;	//c on Seg(a,b)
}

struct Seg {
	Point a,b;

	Seg() : a(Point(0, 0)), b(Point(0, 0)) {}

	Seg (Point a, Point b) : a(a),b(b) {}
};

bool isIntersectSS(Seg s1, Seg s2) { 
	return ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b) <= 0 
		&& ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b) <= 0;
}

class Segments {
	public:
	string intersection(vector <int> s1, vector <int> s2) {
		Point a(s1[0], s1[1]), b(s1[2], s1[3]);
		Point c(s2[0], s2[1]), d(s2[2], s2[3]);

		if(a == b) {
			if(ccw(c, d, a) == 0) return "POINT";
			else return "NO";
		}

		if(c == d) {
			if(ccw(a, b, c) == 0) return "POINT";
			else return "NO";
		}

		Seg v(a, b), v2(c, d);
		if(isIntersectSS(v, v2)) {
			int cnt = 0;

			if(ccw(a, b, c) == 0) cnt++;
			if(ccw(a, b, d) == 0) cnt++;
			if(ccw(c, d, a) == 0) cnt++;
			if(ccw(c, d, b) == 0) cnt++;

			if(cnt <= 1 || ((a == c || a == d || b == c || b == d) && cnt == 2)) return "POINT";
			else return "SEGMENT";
		} else {
			return "NO";
		}
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 0, 1}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(0, Arg2, intersection(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 0, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POINT"; verify_case(1, Arg2, intersection(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, -1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, 0, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POINT"; verify_case(2, Arg2, intersection(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 0, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 10, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "SEGMENT"; verify_case(3, Arg2, intersection(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {5, 5, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 6, 6, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO"; verify_case(4, Arg2, intersection(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {10, 0, -10, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 0, -5, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "SEGMENT"; verify_case(5, Arg2, intersection(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    Segments ___test;

    ___test.run_test(-1);
}

// END CUT HERE
