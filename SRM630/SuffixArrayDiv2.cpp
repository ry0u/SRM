// BEGIN CUT HERE

// END CUT HERE
#line 5 "SuffixArrayDiv2.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <sstream>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

class SuffixArrayDiv2 {
	public:
	string smallerOne(string s) {
		return s;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abca"; string Arg1 = "Exists"; verify_case(0, Arg1, smallerOne(Arg0)); }
	void test_case_1() { string Arg0 = "bbbb"; string Arg1 = "Exists"; verify_case(1, Arg1, smallerOne(Arg0)); }
	void test_case_2() { string Arg0 = "aaaa"; string Arg1 = "Does not exist"; verify_case(2, Arg1, smallerOne(Arg0)); }
	void test_case_3() { string Arg0 = "examplesareveryweakthinktwicebeforesubmit"; string Arg1 = "Exists"; verify_case(3, Arg1, smallerOne(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    SuffixArrayDiv2 ___test;
    ___test.run_test(-1);
}
// END CUT HERE
