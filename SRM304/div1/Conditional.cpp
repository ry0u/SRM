#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

// maxSideまであるサイコロをnDice個振った時, 必ず1つがv出て，theSumを超える確率

double dp[55][55 * 55][2];

class Conditional {

    public:

    double probability(int nDice, int maxSide, int v, int theSum) {
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1.0;

		rep(i, nDice) {
			rep(j, 55 * 55) {
				REP(k, 1, maxSide + 1) {
					if(j + k >= 55 * 55) continue;
					dp[i+1][j + k][1] += dp[i][j][1] * (1.0 / maxSide);

					if(k == v) {
						dp[i+1][j + k][1] += dp[i][j][0] * (1.0 / maxSide);
					} else {
						dp[i+1][j + k][0] += dp[i][j][0] * (1.0 / maxSide);
					}
				}
			}
		}

		double ans = 0.0;
		REP(i, theSum, 55 * 55) {
			ans += dp[nDice][i][1];
		}

		double t = 1.0;
		rep(i, nDice) {
			t *= double(maxSide - 1) / maxSide;
		}

		return ans / (1 - t);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 6; int Arg3 = 12; double Arg4 = 0.09090909090909091; verify_case(0, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 6; int Arg3 = 6; double Arg4 = 1.0; verify_case(1, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 9; int Arg2 = 3; int Arg3 = 3; double Arg4 = 1.0; verify_case(2, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 2; int Arg3 = 4; double Arg4 = 0.6; verify_case(3, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    Conditional ___test;

    ___test.run_test(-1);

}

// END CUT HERE
