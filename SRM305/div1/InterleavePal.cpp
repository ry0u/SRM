// BEGIN CUT HERE

// END CUT HERE
#line 5 "InterleavePal.cpp"

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

string s, t;
int dp[55][55][55][55], ans = 0;
bool vis[55][55][55][55];

// void dfs(int a, int b, int c, int d) {
// 	if(vis[a][b][c][d]) return;
// 	vis[a][b][c][d] = true;
//
// 	int len = (b - a) + (d - c);
// 	ans = max(ans, len);
//
// 	if(a > 0) {
// 		if(b < s.size() && s[a-1] == s[b]) dfs(a-1, b+1, c, d);
// 		if(d < t.size() && s[a-1] == t[d]) dfs(a-1, b, c, d+1);
// 	}
//
// 	if(c > 0) {
// 		if(b < s.size() && t[c-1] == s[b]) dfs(a, b+1, c-1, d);
// 		if(d < t.size() && t[c-1] == t[d]) dfs(a, b, c-1, d+1);
// 	}
// }

int dfs(int a, int b, int c, int d) {
	if(dp[a][b][c][d] != -1) return dp[a][b][c][d];
	if(a >= b && c >= d) return 0;

	int ret = 0;

	if(a < b) {
		if(b - 1 >= a && s[a] == s[b-1]) ret = max(ret, 2 + dfs(a+1, b-1, c, d));
		if(d - 1 >= c && s[a] == t[d-1]) ret = max(ret, 2 + dfs(a+1, b, c, d-1));
	}

	if(c < d) {
		if(b - 1 >= a && t[c] == s[b-1]) ret = max(ret, 2 + dfs(a, b-1, c+1, d));
		if(d - 1 >= c && t[c] == t[d-1]) ret = max(ret, 2 + dfs(a, b, c+1, d-1));
	}

	return dp[a][b][c][d] = ret;
}


class InterleavePal {
	public:
	int longestPal(string _s, string _t) {
		s = _s; t = _t;
		memset(dp, -1, sizeof(dp));

		return dfs(0, s.size(), 0, t.size());
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AA"; string Arg1 = "BB"; int Arg2 = 4; verify_case(0, Arg2, longestPal(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = ""; string Arg1 = "JAVA"; int Arg2 = 3; verify_case(1, Arg2, longestPal(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = ""; string Arg1 = ""; int Arg2 = 0; verify_case(2, Arg2, longestPal(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ONCEUPONATIMETHEREWASAYOUNGPROGRAMMERWHOLEARNED"; string Arg1 = "TOPROGRAMJOINEDTOPCODERANDEVENTUALLYBECAMERED"; int Arg2 = 9; verify_case(3, Arg2, longestPal(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    InterleavePal ___test;

    ___test.run_test(-1);

}

// END CUT HERE
