// BEGIN CUT HERE

// END CUT HERE
#line 5 "MooingCows.cpp"

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

class MooingCows {
	public:
	int dissatisfaction(vector <string> s) {
		int n = s.size();
		int m = s[0].size();

		int ans = INF;
		rep(i, n) {
			rep(j, m) {
				if(s[i][j] != 'C') continue;

				int res = 0;

				rep(x, n) {
					rep(y, m) {
						if(s[x][y] != 'C') continue;
						if(x == i && y == j) continue;
						res += (x - i) * (x - i) + (y - j) * (y - j);
					}
				}

				ans = min(ans, res);
			}
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"C..",
 ".C.",
 ".C."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, dissatisfaction(Arg0)); }
	void test_case_1() { string Arr0[] = {"CCCC",
 "CCCC",
 "CCCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; verify_case(1, Arg1, dissatisfaction(Arg0)); }
	void test_case_2() { string Arr0[] = {"C"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, dissatisfaction(Arg0)); }
	void test_case_3() { string Arr0[] = {"CCC....",
 "C......",
 "....C.C",
 ".C.CC..",
 "C......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 81; verify_case(3, Arg1, dissatisfaction(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    MooingCows ___test;

    ___test.run_test(-1);

}

// END CUT HERE
