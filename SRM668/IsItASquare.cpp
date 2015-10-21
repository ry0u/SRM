// BEGIN CUT HERE

// END CUT HERE
#line 5 "IsItASquare.cpp"
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
#define EPS 1e-8
#define equals(a,b) fabs((a) - (b)) < EPS

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
};

class IsItASquare {
	public:
	string isSquare(vector <int> x, vector <int> y) {
        vector<Point> v(4);
        rep(i,4) {
            v[i].x = x[i];
            v[i].y = y[i];
        }

        double len1 = 0, len2 = 0, len3 = 0;
        bool flag = true;
        rep(i,4) {
            vector<double> d;
            rep(j,4) {
                if(i == j) continue;
                d.push_back(v[i].distance(v[j]));
            }

            sort(d.begin(),d.end());


            if(i == 0) {
                len1 = d[0];
                len2 = d[1];
                len3 = d[2];
            } else {

                if(!equals(len1,d[0])) {
                    flag = false;
                }
                if(!equals(len2,d[1])) {
                    flag = false;
                }
                if(!equals(len3,d[2])) {
                    flag = false;
                } 
                if(!equals(len1,len2)) flag = false;

                if(!flag) break;
            }
        }

        if(flag) return "It's a square";
        else return "Not a square";
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 0, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "It's a square"; verify_case(0, Arg2, isSquare(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 1, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 6, 0, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "It's a square"; verify_case(1, Arg2, isSquare(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 7, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 3, 0, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not a square"; verify_case(2, Arg2, isSquare(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 5000, 5000, 10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5000, 0, 10000, 5000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "It's a square"; verify_case(3, Arg2, isSquare(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 3, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not a square"; verify_case(4, Arg2, isSquare(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0, 5, 3, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not a square"; verify_case(5, Arg2, isSquare(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    IsItASquare ___test;
    ___test.run_test(-1);
}
// END CUT HERE
