// BEGIN CUT HERE

// END CUT HERE
#line 5 "BearPermutations2.cpp"
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

class BearPermutations2 {
	public:
	int getSum(int N, int MOD) {
		ll dp[105];
		memset(dp, 0, sizeof(dp));

		dp[0] = 0;
		dp[1] = 0;
		dp[2] = 0;

		rep(i, N-1) {

		}

		return dp[n] % MOD;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 502739849; int Arg2 = 4; verify_case(0, Arg2, getSum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1000003; int Arg2 = 0; verify_case(1, Arg2, getSum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 973412327; int Arg2 = 38; verify_case(2, Arg2, getSum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 89; int Arg2 = 49; verify_case(3, Arg2, getSum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    BearPermutations2 ___test;
    ___test.run_test(-1);
}
// END CUT HERE
