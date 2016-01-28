// BEGIN CUT HERE

// END CUT HERE
#line 5 "TreeAndPathLength2.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int dp[55][1005];

int dfs(int p, int s) {
	if(s == 0) {
		if(p == 0) return 1;
		return 0;
	}

	if(p == 0) return 0;
	int &res = dp[p][s];

	if(res != -1) return res;

	res = 0;

	REP(i, 1, p+1) {
		if(s >= (i * (i+1) / 2)) {
			res = max(res, dfs(p-i, s - (i*(i+1)  ) / 2) );
		}
	}

	return res;
}

bool memo[55][1005];

bool dfs2(int p, int s) {
	cout << "in dfs " << p << " " << s << endl;
	if(s == 0) {
		if(p == 0) return true;
		return false;
	}

	if(p == 0) return false;
	if(memo[p][s]) return memo[p][s];

	bool flag = false;
	REP(i, 1, p+1) {
		if(s >= (i * (i+1) / 2)) {
			// flag |= dfs2(p-i, s - (i * (i+1)) / 2);
			memo[p][s] |= dfs2(p-i, s - (i*(i+1)) / 2);
		}
	}

	return memo[p][s];
}


class TreeAndPathLength2 {
	public:
	string possible(int n, int s) {
		if(s == 0 && n < 3) return "Possible";

		if(n < 3) return "Impossible";

		rep(i, 55) {
			rep(j, 1005) {
				dp[i][j] = -1;
			}
		}

		// if(dfs(n-2, s) == 1) return "Possible";
		// else return "Impossible";
		memset(memo, 0, sizeof(memo));
		
		if(dfs2(n-2, s) == true) return "Possible";
		else return "Impossible";
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 3; string Arg2 = "Possible"; verify_case(0, Arg2, possible(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2; string Arg2 = "Possible"; verify_case(1, Arg2, possible(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; string Arg2 = "Impossible"; verify_case(2, Arg2, possible(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 4; string Arg2 = "Possible"; verify_case(3, Arg2, possible(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 999; string Arg2 = "Impossible"; verify_case(4, Arg2, possible(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 1000; string Arg2 = "Possible"; verify_case(5, Arg2, possible(Arg0, Arg1)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main() {
  TreeAndPathLength2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
