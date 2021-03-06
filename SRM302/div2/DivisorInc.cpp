// BEGIN CUT HERE

// END CUT HERE
#line 5 "DivisorInc.cpp"

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

int dp[100005];

vector<ll> divisor(ll n) {
	vector<ll> res;
	for(ll i = 2; i*i <= n; i++) {
		if(n % i == 0) {
			res.push_back(i);
			if(i != n/i) res.push_back(n/i);
		}
	}
	return res;
}

class DivisorInc {
	public:
	int countOperations(int N, int M) {
		rep(i, M + 5) dp[i] = INF;

		dp[N] = 0;
		REP(i, N, M) {
			vector<ll> ret = divisor(i);
			rep(j, ret.size()) {
				if(i + ret[j] <= 100005) {
					dp[i + ret[j]] = min(dp[i + ret[j]], dp[i] + 1);
				}
			}
		}

		if(dp[M] == INF) return -1;
		return dp[M];
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 24; int Arg2 = 5; verify_case(0, Arg2, countOperations(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 576; int Arg2 = 14; verify_case(1, Arg2, countOperations(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 8748; int Arg1 = 83462; int Arg2 = 10; verify_case(2, Arg2, countOperations(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 235; int Arg1 = 98234; int Arg2 = 21; verify_case(3, Arg2, countOperations(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 99991; int Arg2 = -1; verify_case(4, Arg2, countOperations(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 82736; int Arg1 = 82736; int Arg2 = 0; verify_case(5, Arg2, countOperations(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    DivisorInc ___test;

    ___test.run_test(-1);

}

// END CUT HERE
