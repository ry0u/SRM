// BEGIN CUT HERE

// END CUT HERE
#line 5 "LengthUnitCalculator.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

class LengthUnitCalculator {
	public:
	double calc(int a, string s, string t) {
		double b = a;
		if(s == t) {
			return b;
		} else if(s == "in") {
			if(t == "ft") return b / (12);
			if(t == "yd") return b / (12 * 3);
			if(t == "mi") return b / (12 * 3 * 1760);
		} else if(s == "ft") {
			if(t == "in") return b * 12;
			if(t == "yd") return b / (3.0);
			if(t == "mi") return b / (3.0 * 1760);
		} else if(s == "yd") {
			if(t == "in") return b * (12 * 3.0);
			if(t == "ft") return b * (3.0);
			if(t == "mi") return b / 1760.0;
		} else if(s == "mi") {
			if(t == "in") return b * 12 * 3.0 * 1760;
			if(t == "ft") return b * 3.0 * 1760;
			if(t == "yd") return b * 1760.0;
		}

		return a;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "mi"; string Arg2 = "ft"; double Arg3 = 5280.0; verify_case(0, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; string Arg1 = "ft"; string Arg2 = "mi"; double Arg3 = 1.893939393939394E-4; verify_case(1, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 123; string Arg1 = "ft"; string Arg2 = "yd"; double Arg3 = 41.0; verify_case(2, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000; string Arg1 = "mi"; string Arg2 = "in"; double Arg3 = 6.336E7; verify_case(3, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; string Arg1 = "in"; string Arg2 = "mi"; double Arg3 = 1.5782828282828283E-5; verify_case(4, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 47; string Arg1 = "mi"; string Arg2 = "mi"; double Arg3 = 47.0; verify_case(5, Arg3, calc(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    LengthUnitCalculator ___test;
    ___test.run_test(-1);
}
// END CUT HERE
