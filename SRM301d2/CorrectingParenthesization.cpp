// BEGIN CUT HERE

// END CUT HERE
#line 5 "CorrectingParenthesization.cpp"

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

int dp[55][55];
string s = "";

int f(int l, int r) {
	char a = s[l], b = s[r-1];
	if(a == '(' && b == ')') return 0;
	if(a == '{' && b == '}') return 0;
	if(a == '[' && b == ']') return 0;

	if(a == '(' || b == ')') return 1;
	if(a == '{' || b == '}') return 1;
	if(a == '[' || b == ']') return 1;

	return 2;
}

int dfs(int l, int r) {
	if(dp[l][r] != INF) return dp[l][r];
	if(l == r) return 0;
	int ret = INF, x = f(l, r);

	if(x == 0) ret = min(ret, dfs(l+1, r-1));
	else if(x == 1) ret = min(ret, dfs(l+1, r-1) + 1);
	else ret = min(ret, dfs(l+1, r-1) + 2);

	REP(i, l+1, r) {
		if((i - l) % 2 == 0) {
			ret = min(ret, dfs(l, i) + dfs(i, r));
		}
	}

	return dp[l][r] = ret;
}

class CorrectingParenthesization {
	public:
	int getMinErrors(string _s) {
		s = _s;
		int n = s.size();
		rep(i, 55) rep(j, 55) dp[i][j] = INF;

		return dfs(0, n);
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "([{}])()[]{}"; int Arg1 = 0; verify_case(0, Arg1, getMinErrors(Arg0)); }
	void test_case_1() { string Arg0 = "([)]"; int Arg1 = 2; verify_case(1, Arg1, getMinErrors(Arg0)); }
	void test_case_2() { string Arg0 = "([{}[]"; int Arg1 = 1; verify_case(2, Arg1, getMinErrors(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    CorrectingParenthesization ___test;

    ___test.run_test(-1);

}

// END CUT HERE
