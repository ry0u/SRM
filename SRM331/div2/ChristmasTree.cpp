// BEGIN CUT HERE

// END CUT HERE
#line 5 "ChristmasTree.cpp"

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
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int n;
ll dp[12][51][51][51];

ll C[2005][2005];
void combination(int size) {
	for (int i = 0; i < size; i++) C[i][0] = 1LL;
	for (int i = 1; i < size; i++) {
		for (int j = 1; j <= i; j++) {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
		}
	}
}

ll dfs(int dep, int r, int g, int b) {
	if(dp[dep][r][g][b] != -1) return dp[dep][r][g][b];
	if(dep == n + 1) {
		return dp[dep][r][g][b] = 1;
	}

	ll ret = 0;
	if(r - dep >= 0) {
		ret += dfs(dep + 1, r - dep, g, b);
	}
	if(g - dep >= 0) {
		ret += dfs(dep + 1, r, g - dep, b);
	}
	if(b - dep >= 0) {
		ret += dfs(dep + 1, r, g, b - dep);
	}

	if(dep % 2 == 0) {
		if(r - dep / 2 >= 0 && g - dep / 2 >= 0) {
			ret += dfs(dep + 1, r - dep / 2, g - dep / 2, b) * C[dep][dep/2];
		}
		if(g - dep / 2 >= 0 && b - dep / 2 >= 0) {
			ret += dfs(dep + 1, r, g - dep / 2, b - dep / 2) * C[dep][dep/2];
		}
		if(r - dep / 2 >= 0 && b - dep / 2 >= 0) {
			ret += dfs(dep + 1, r - dep / 2, g, b - dep / 2) * C[dep][dep/2];
		}
	}

	if(dep % 3 == 0) {
		if(r - dep / 3 >= 0 && g - dep / 3 >= 0 && b - dep / 3 >= 0) {
			ret += dfs(dep + 1, r - dep / 3, g - dep / 3, b - dep / 3) * C[dep][dep/3] * C[dep - dep / 3][dep/3];
		}
	}

	return dp[dep][r][g][b] = ret;
}

class ChristmasTree {
	public:
	long long decorationWays(int N, int red, int green, int blue) {
		n = N;
		combination(55);
		memset(dp, -1, sizeof(dp));

		return dfs(1, red, green, blue);
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; long long Arg4 = 6LL; verify_case(0, Arg4, decorationWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 0; long long Arg4 = 3LL; verify_case(1, Arg4, decorationWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; long long Arg4 = 0LL; verify_case(2, Arg4, decorationWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; long long Arg4 = 36LL; verify_case(3, Arg4, decorationWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 8; int Arg1 = 1; int Arg2 = 15; int Arg3 = 20; long long Arg4 = 197121LL; verify_case(4, Arg4, decorationWays(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    ChristmasTree ___test;

    ___test.run_test(-1);
	cout << ___test.decorationWays(10, 50, 50, 50) << endl;
	cout << ___test.decorationWays(10, 3, 3, 49) << endl; // 3906
}

// END CUT HERE
