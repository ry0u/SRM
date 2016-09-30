#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define EPS 1e-9
#define equals(a,b) fabs((a) - (b)) < EPS
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

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

struct Line {
	Point a, b;

	Line() : a(Point(0, 0)), b(Point(0, 0)) {}

	Line(Point a, Point b) : a(a), b(b) {}
};

ostream& operator << (ostream& os, const Line& l) {
	os << "(" << l.a.x << ", " << l.a.y << ")-(" << l.b.x << "," << l.b.y << ")";
	return os;
}

struct Seg {
	Point a,b;

	Seg() : a(Point(0, 0)), b(Point(0, 0)) {}

	Seg (Point a, Point b) : a(a),b(b) {}
};

ostream& operator << (ostream& os, const Seg& s) {
	os << "(" << s.a.x << ", " << s.a.y << ")-(" << s.b.x << "," << s.b.y << ")";
	return os;
}

bool isOrthogonal(Line l1, Line l2) { return equals(dot((l1.b - l1.a), (l2.b - l2.a)), 0.0); }

bool isParallel(Line l1, Line l2) { return equals(cross((l1.b - l1.a), (l2.b - l2.a)), 0.0); }

bool sameLine(Line l1, Line l2) { return abs(cross(l1.b - l1.a, l2.b - l2.a)) < EPS; }

bool isIntersectLL(Line l1, Line l2) { return !isParallel(l1, l2) || sameLine(l1, l2); }

bool isIntersectLS(Line l, Seg s) {
	return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < 0;
}

bool isIntersectSS(Seg s1, Seg s2) { 
	return ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b) <= 0 
		&& ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b) <= 0;
}

double distanceLP(Line l, Point p) {
	return abs(cross(l.b - l.a, p - l.a)) / abs(l.b - l.a);
}

double distanceLS(Line l, Seg s) {
	if (isIntersectLS(l, s)) return 0.0;
	return min(distanceLP(l, s.a), distanceLP(l, s.b));
}

double distanceSP(Seg s, Point p) {
	if (dot(s.b - s.a, p - s.a) < 0.0) return abs(p - s.a);
	if (dot(s.a - s.b, p - s.b) < 0.0) return abs(p - s.b);
	return distanceLP(Line(s.a, s.b) , p);
}

double distanceSS(Seg s1, Seg s2) {
	if (isIntersectSS(s1, s2)) return 0.0;
	return min( min(distanceSP(s1, s2.a), distanceSP(s1, s2.b)), min(distanceSP(s2, s1.a), distanceSP(s2, s1.b)) );
}

// if isIntersectLL(l1, l2)
Point crossPointLL(Line l1, Line l2) {
	Point v = l1.b - l1.a;
	Point v2 = l2.b - l2.a;
	return l1.a + v * cross(v2, l2.a - l1.a) / cross(v2, v);
}

// if isIntersectLS(l, s)
Point crossPointLS(Line l, Seg s) { return crossPointLL(l, Line(s.a, s.b)); }

// if isIntersectSS(s1, s2)
Point crossPointSS(Seg s1, Seg s2) { return crossPointLL(Line(s1.a, s1.b), Line(s2.a, s2.b)); }

Point project(Line l, Point p) {
	Point base = l.b - l.a;
	double t = dot(base, p-l.a) / dot(base, base);
	return l.a + base * t;
}

Point reflect(Line l, Point p) {
	return p + (project(l, p) - p) * 2.0;
}

vector<string> split(const string &str, char delim) {
	vector<string> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos) {
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}

vector<Line> uniqueLine(vector<Line> lines) {
	vector<Line> ret;
	rep(i, lines.size()) {
		bool flag = true;
		REP(j, i+1, lines.size()) {
			if(sameLine(lines[i], lines[j])) {
				flag = false;
			}
		}

		if(flag) ret.push_back(lines[i]);
	}

	return ret;
}

class PizzaDivision {

    public:

    int howMany(vector <string> toppings) {
		int n = toppings.size();

		vector<Point> v(n);
		rep(i, n) {
			vector<string> ret = split(toppings[i], ' ');
			double x, y;
			stringstream ss1(ret[0]);
			stringstream ss2(ret[1]);

			ss1 >> x;
			ss2 >> y;

			v[i].x = x;
			v[i].y = y;
		}

		if(n == 1 && equals(v[0].x, 0.0) && equals(v[0].y, 0.0)) return -1;

		vector<Line> lines;
		rep(i, n) {
			if(equals(v[i].x, 0) && equals(v[i].y, 0)) continue;
			Line l;
			l.a = v[i];
			l.b.x = 0.0;
			l.b.y = 0.0;
		
			lines.push_back(l);
		}

		rep(i, n) {
			REP(j, i + 1, n) {
				Line l;
				double x = (v[j].x + v[i].x) / 2;
				double y = (v[j].y + v[i].y) / 2;

				l.a.x = x;
				l.a.y = y;
				l.b.x = 0.0;
				l.b.y = 0.0;

				if(equals(x, 0.0) && equals(y, 0.0)) {
					Point vec = v[i] - l.a;
					x = vec.x * 0 - vec.y * 1;
					y = vec.x * 1 + vec.y * 0;

					l.b.x += x;
					l.b.y += y;
				}

				lines.push_back(l);
			}
		}

		lines = uniqueLine(lines);

		int cnt = 0;
		rep(i, lines.size()) {
			bool flag = true;
			rep(j, n) {
				if(equals(distanceLP(lines[i], v[j]), 0.0)) continue;

				bool ch = false;
				rep(k, n) {
					if(k == j) continue;

					Line l(v[j], v[k]);

					if(isOrthogonal(lines[i], l)) {
						Point p = crossPointLL(lines[i], l);
						double dist1 = distancePP(v[j], p);
						double dist2 = distancePP(v[k], p);
						if(equals(dist1, dist2)) {
							ch = true;
						}
					}
				}

				if(ch) continue;
				flag = false;
			}

			if(flag) cnt++;
		}

		return cnt;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 110", "0 70", "-75 20", "75 20", "-25 -50", "25 -50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { string Arr0[] = {"0 70", "70 0", "0 -70", "-70 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { string Arr0[] = {"0 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { string Arr0[] = {"3 -4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { string Arr0[] = {"3 -4", "-3 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, howMany(Arg0)); }
	void test_case_5() { string Arr0[] = {"1 2", "3 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, howMany(Arg0)); }
	void test_case_6() { string Arr0[] = {"-300 100", "-200 100", "-100 100", "100 100", 
"200 100", "300 100", "-300 -100", "-200 -100", 
"-100 -100", "100 -100", "200 -100", "300 -100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(6, Arg1, howMany(Arg0)); }
	void test_case_7() { string Arr0[] = {"-54 -83", "-46 54", "-5 -44", "-1 -31", "-14 47", 
"7 -5", "-45 -63", "-88 47", "-17 -9", "-26 -66", 
"40 56", "-67 69", "-49 -2", "2 62", "61 78", 
"-81 -32", "87 33", "-22 -53", "-43 -38", "57 28", 
"35 12", "-53 -15", "52 -16", "32 -44", "-73 68", 
"79 44", "3 56", "-66 26", "-87 41", "4 87", 
"22 53", "59 16", "-3 55", "3 19", "-26 8", 
"43 38", "54 46", "-16 22", "-3 -93", "45 63", 
"0 -37", "-7 5", "-40 -56", "40 19", "-8 -63", 
"-16 -89", "29 11", "-52 -21", "-58 -22", "4 -61"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(7, Arg1, howMany(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    PizzaDivision ___test;

    ___test.run_test(-1);

}

// END CUT HERE
