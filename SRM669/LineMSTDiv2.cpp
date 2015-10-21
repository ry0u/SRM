// BEGIN CUT HERE

// END CUT HERE
#line 5 "LineMSTDiv2.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

class LineMSTDiv2 {
	public:
	int count(int N) {
		
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 15; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 16; int Arg1 = 682141922; verify_case(2, Arg1, count(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main() {
  LineMSTDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
