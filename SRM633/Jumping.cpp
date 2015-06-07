// BEGIN CUT HERE

// END CUT HERE
#line 5 "Jumping.cpp"
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

using namespace std;
typedef long long ll;

class Jumping {
	public:
	string ableToGet(int x, int y, vector<int> v) {
        x = abs(x);
        y = abs(y);
        
        double D = sqrt(x*x + y*y);
        int vmax = 0;
        int sum = 0;
        rep(i,v.size()) {
            sum += v[i];
            vmax = max(vmax,v[i]);
        }

        if(v.size() == 1) {
            if(D == sum) return "Able";
            else return "Not able";
        }
        else if(D <= sum) {
            int d = sum - vmax;
            int d2 = vmax - d;

            if(d2 <= D) return "Able";
            else return "Not able";
        }
        else return "Not able";
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; int Arr2[] = {2, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Able"; verify_case(0, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 4; int Arr2[] = {4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Not able"; verify_case(1, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; int Arr2[] = {6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Not able"; verify_case(2, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 1; int Arr2[] = {100, 100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Able"; verify_case(3, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 300; int Arg1 = 400; int Arr2[] = {500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Able"; verify_case(4, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 11; int Arg1 = 12; int Arr2[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Able"; verify_case(5, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 11; int Arg1 = 12; int Arr2[] = {1,2,3,4,5,6,7,8,9,100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Not able"; verify_case(6, Arg3, ableToGet(Arg0, Arg1, Arg2)); }


// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    Jumping ___test;
    ___test.run_test(-1);
    vector<int> v(2);
    v[0] = 100;
    v[1] = 101;
    cout << ___test.ableToGet(1,0,v) << endl;
}
// END CUT HERE
