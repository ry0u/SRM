// BEGIN CUT HERE

// END CUT HERE
#line 5 "TestBettingStrategy.cpp"
#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,k,n) for(int i=k;i<(int)(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

double dp[55][1005][10];

class TestBettingStrategy {
	public:
	double winProbability(int initSum, int goalSum, int rounds, int prob) {
		memset(dp, 0, sizeof(dp));
		dp[0][initSum][0] = 1;

		double p = prob / 100.0;

		rep(i, rounds) {
			rep(j, goalSum) {
				rep(k, 10) {
					int bet = (1 << k);
					if(j >= bet) {
						dp[i+1][j + bet][0] += dp[i][j][k] * p;
						dp[i+1][j - bet][k+1] += dp[i][j][k] * (1 - p);
					}
				}
			}
		}

		double ans = 0;
		REP(i, 1, rounds + 1) {
			REP(j, goalSum, 1005) {
				rep(k, 10) {
					ans += dp[i][j][k];
				}
			}
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 11; int Arg2 = 4; int Arg3 = 50; double Arg4 = 0.875; verify_case(0, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 20; int Arg3 = 50; double Arg4 = 0.3441343307495117; verify_case(1, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 10; int Arg3 = 90; double Arg4 = 0.34867844010000015; verify_case(2, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 24; int Arg1 = 38; int Arg2 = 24; int Arg3 = 60; double Arg4 = 0.5940784635646947; verify_case(3, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    TestBettingStrategy ___test;

    ___test.run_test(-1);

}

// END CUT HERE
