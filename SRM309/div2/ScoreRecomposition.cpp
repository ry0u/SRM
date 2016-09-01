// BEGIN CUT HERE

// END CUT HERE
#line 5 "ScoreRecomposition.cpp"

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

class ScoreRecomposition {
	public:
	int minError(string questions, int score) {
		int n = questions.size();
		vector<int> id;
		rep(i, n) id.push_back(i + 1);

		int ans = INF;
		do {
			int sum = 0, res = 0;
			rep(i, n) {
				if(questions[i] == 'C') {
					sum += id[i];
				}
				res = max(res, abs(i + 1 - id[i]));
			}

			if(sum == score) {
				ans = min(ans, res);
			}

		} while(next_permutation(id.begin(), id.end()));

		if(ans == INF) return -1;
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "CCC"; int Arg1 = 5; int Arg2 = -1; verify_case(0, Arg2, minError(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "WCWW"; int Arg1 = 4; int Arg2 = 2; verify_case(1, Arg2, minError(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "CWW"; int Arg1 = 1; int Arg2 = 0; verify_case(2, Arg2, minError(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "CWCC"; int Arg1 = 6; int Arg2 = 2; verify_case(3, Arg2, minError(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "WWCC"; int Arg1 = 3; int Arg2 = 2; verify_case(4, Arg2, minError(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "CWCCWWCWCC"; int Arg1 = 55; int Arg2 = -1; verify_case(5, Arg2, minError(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "CWWCWCCWWC"; int Arg1 = 37; int Arg2 = 3; verify_case(6, Arg2, minError(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    ScoreRecomposition ___test;

    ___test.run_test(-1);

}

// END CUT HERE
