// BEGIN CUT HERE

// END CUT HERE
#line 5 "Flee.cpp"
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
#define EPS 1e-9
#define INF 1<<30

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

    double area_abs(const Point &a,const Point &b) const {
        Point p = a - (*this), p2 = b - (*this);
        return fabs(p.cross(p2)) / 2.0;
    }	

    // //線分abが自身に含まれているのかどうか判断する
    // int between(const Point &a,const Point &b) {
    //     if(area(a,b) != 0) return 0;
    //
    //     if(a.x != b.x)  return ((a.x <= x) && (x <= b.x) || (a.x >= x) && (x >= b.x));
    //     else return ((a.y <= y) && (y <= b.y) || (a.y >= y) && (y >= b.y));
    // }      

    double distance_seg(const Point& a,const Point& b) {
        if((b-a).dot(*this-a) < EPS) {
            return (*this-a).norm();
        }
        if((a-b).dot(*this-b) < EPS) {
            return (*this-b).norm();
        }
        return abs((b-a).cross(*this-a)) / (b-a).norm();
    }

    bool hitPolygon(const Point& a,const Point& b,const Point& c) {
        double t = (b-a).cross(*this-b);
        double t2 = (c-b).cross(*this-c);
        double t3 = (a-c).cross(*this-a);	

        if((t > 0 && t2 > 0 && t3 > 0) || ( t < 0 && t2 < 0 && t3 < 0)) {
            return true;
        }

        return false;
    }
};

class Flee {
	public:
	double maximalSafetyLevel(vector <int> x, vector <int> y) {
        int n = x.size();

        vector<Point> v;
        map<pair<int,int>,bool > m;
        rep(i,n) {
            pair<int,int> p = make_pair(x[i],y[i]);
            if(m[p]) continue;

            v.push_back(Point(x[i],y[i]));
            m[p] = true;
        }

        double ans = 0;
    
        if(v.size() == 1) {
            ans = v[0].norm();
        }
        else if(v.size() == 2) {
            ans = min(v[0].norm(),v[1].norm());
        }else {
            vector<int> d;
            int res = INF;
            rep(i,v.size()) {
                res = min(res,(int)(v[i]*2).dot(v[i]*2));
            }

            d.push_back(res);

            Point p(0,0);
            if(p.hitPolygon(v[0],v[1],v[2])) {
                rep(i,v.size()) {
                    rep(j,v.size()) {
                        if(i == j) continue;
                        
                        Point p(v[i]-v[j]);
                        if(p.dot(p) < res) {
                            d.push_back(p.dot(p));
                        }
                    }
                }

                sort(d.begin(),d.end(),greater<double>());
                d.erase(unique(d.begin(),d.end()),d.end());

                rep(k,d.size()) {
                    int len = d[k];
                    bool flag = false;
                    Point p1(v[0].x-v[1].x, v[0].y-v[1].y);
                    Point p2(v[0].x-v[2].x, v[0].y-v[2].y);
                    Point p3(v[1].x-v[2].x, v[1].y-v[2].y);

                    int r = (int)p1.x*p1.x + p1.y*p1.y;
                    int r2 = (int)p2.x*p2.x + p2.y*p2.y;
                    int r3 = (int)p3.x*p3.x + p3.y*p3.y;

                    if(r >= len) {
                        flag = true;
                    }
                    if(r2 >= len) {
                        flag = true;
                    }
                    if(r3 >= len) {
                        flag = true;
                    }

                    if(flag) {
                        ans = sqrt(d[k])/2.0;
                        break;
                    }
                }
            }else {
                sort(d.begin(),d.end());
                ans = sqrt(d[0])/2.0;
            }
        }

        return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,-7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,-5,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 5.0; verify_case(0, Arg2, maximalSafetyLevel(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-5,-5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 5.0990195135927845; verify_case(1, Arg2, maximalSafetyLevel(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,-8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,-5,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 5.0990195135927845; verify_case(2, Arg2, maximalSafetyLevel(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {232,312,-432}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {498,-374,24}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 432.6661530556787; verify_case(3, Arg2, maximalSafetyLevel(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(4, Arg2, maximalSafetyLevel(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    Flee ___test;
    ___test.run_test(-1);
    vector<int> v(3);
    v[0] = -177;
    v[1] = -325;
    v[2] = 525;

    vector<int> t(3);
    t[0] = 677;
    t[1] = 433;
    t[2] = -719;
    
    cout << ___test.maximalSafetyLevel(v,t) << endl;
}
// END CUT HERE
