// BEGIN CUT HERE

// END CUT HERE
#line 5 "SimplifiedDarts.cpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

double dp[1005][3005];

class SimplifiedDarts {
	public:
	double tryToWin(int W, int N, int P1, int P2) {
		double p1 = P1 / (100.0);
		double p2 = P2 / (100.0);

		memset(dp, 0, sizeof(dp));
		
		rep(i, N + 1) 
			dp[i][0] = 1.0;
		
		REP(i, 1, N + 1) {
			REP(j, 1, W + 1) {
				if(j - 2 >= 0) {
					dp[i][j] = max(dp[i][j], p1 * dp[i-1][j-2] + (1 - p1) * dp[i-1][j]);
				} else {
					dp[i][j] = max(dp[i][j], p1 + (1 - p1) * dp[i-1][j]);
				}
				if(j - 3 >= 0) {
					dp[i][j] = max(dp[i][j], p2 * dp[i-1][j-3] + (1 - p2) * dp[i-1][j]);
				} else {
					dp[i][j] = max(dp[i][j], p2 + (1 - p2) * dp[i-1][j]);
				}
			}
		}

		return dp[N][W] * 100;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 50; int Arg3 = 25; double Arg4 = 12.5; verify_case(0, Arg4, tryToWin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 90; int Arg3 = 20; double Arg4 = 73.30000000000001; verify_case(1, Arg4, tryToWin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 30; int Arg1 = 384; int Arg2 = 3; int Arg3 = 1; double Arg4 = 18.344490479047746; verify_case(2, Arg4, tryToWin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 999; int Arg1 = 333; int Arg2 = 0; int Arg3 = 100; double Arg4 = 100.0; verify_case(3, Arg4, tryToWin(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 333; int Arg2 = 0; int Arg3 = 100; double Arg4 = 0.0; verify_case(4, Arg4, tryToWin(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    SimplifiedDarts ___test;

    ___test.run_test(-1);

	cout << ___test.tryToWin(341, 332, 1, 62) << endl;

}

// END CUT HERE
