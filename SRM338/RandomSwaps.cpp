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

double dp[100005][2];

class RandomSwaps {

    public:

    double getProbability(int arrayLength, int swapCount, int a, int b) {
		int n = arrayLength;
		int cnt = swapCount;

		memset(dp, 0, sizeof(dp));
		
		dp[0][a == b] = 1;

		double N = (n * (n - 1)) / 2;
		rep(i, cnt) {
			dp[i+1][1] = dp[i][1] * (1 - (n - 1) / N) + dp[i][0] * (1.0 / N);
			dp[i+1][0] = dp[i][1] * ((n - 1) / N) + dp[i][0] * (1 - 1.0 / N);
		}

		return dp[cnt][1];
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 0; int Arg3 = 0; double Arg4 = 0.6; verify_case(0, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 0; int Arg3 = 3; double Arg4 = 0.1; verify_case(1, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 0; int Arg3 = 0; double Arg4 = 0.4; verify_case(2, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 500; int Arg2 = 3; int Arg3 = 3; double Arg4 = 0.010036635745123007; verify_case(3, Arg4, getProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    RandomSwaps ___test;

    ___test.run_test(-1);

}

// END CUT HERE
