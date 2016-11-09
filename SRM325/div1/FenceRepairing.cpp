// BEGIN CUT HERE

// END CUT HERE
#line 5 "FenceRepairing.cpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

double dp[2505];

class FenceRepairing {
	public:
	double calculateCost(vector <string> boards) {
		string s = " ";
		rep(i, boards.size()) {
			s += boards[i];
		}

		rep(i, 2505) dp[i] = INF;
		dp[0] = 0;

		rep(i, s.size()) {
			int left = -1, right = -1;
			REP(j, i, s.size()) {
				if(s[j] == 'X') {
					if(left == -1) left = j;
					right = j;
				}

				if(left == -1 || right == -1) {
					dp[j] = min(dp[j], dp[i]);
				} else {
					dp[j] = min(dp[j], dp[i] + sqrt(right - left + 1));
				}
			}
		}

		return dp[s.size()-1];
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X.X...X.X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.0; verify_case(0, Arg1, calculateCost(Arg0)); }
	void test_case_1() { string Arr0[] = {"X.X.....X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.732050807568877; verify_case(1, Arg1, calculateCost(Arg0)); }
	void test_case_2() { string Arr0[] = {"X.......", "......XX", ".X......", ".X...X.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.0; verify_case(2, Arg1, calculateCost(Arg0)); }
	void test_case_3() { string Arr0[] = {".X.......X", "..........", "...X......", "...X..X...", "..........",
 "..........", "..X....XX.", ".........X", "XXX", ".XXX.....X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 9.591663046625438; verify_case(3, Arg1, calculateCost(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    FenceRepairing ___test;

    ___test.run_test(-1);

}

// END CUT HERE
