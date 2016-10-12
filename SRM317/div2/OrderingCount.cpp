// BEGIN CUT HERE

// END CUT HERE
#line 5 "OrderingCount.cpp"

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

ll dp[1<<21];

class OrderingCount {
	public:
	long long countOrderings(vector <string> req) {
		int n = req.size();

		memset(dp, 0, sizeof(dp));
		dp[0] = 1;

		rep(i, 1<<n) {
			rep(j, n) {
				if(i & (1 << j)) continue;

				bool flag = true;
				rep(k, n) {
					if(i & (1 << k)) continue;
					if(req[j][k] == 'Y') flag = false;
				}

				if(flag) {
					dp[i | (1 << j)] += dp[i];
				}
			}
		}

		return dp[(1<<n)-1];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NNNN",
 "YNNY",
 "NNNN",
 "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(0, Arg1, countOrderings(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYN",
 "NNY",
 "YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(1, Arg1, countOrderings(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 120LL; verify_case(2, Arg1, countOrderings(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNNNN",
 "NNYNNN",
 "NNNYNN",
 "NNNNYN",
 "NNNNNY",
 "NNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(3, Arg1, countOrderings(Arg0)); }
	void test_case_4() { string Arr0[] = {"NNYNNN",
 "YNYNNN",
 "NNNNNN",
 "NNNNNN",
 "NNYYNN",
 "NNYNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 42LL; verify_case(4, Arg1, countOrderings(Arg0)); }
	void test_case_5() { string Arr0[] = {"NNN",
 "NYN",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(5, Arg1, countOrderings(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    OrderingCount ___test;

    ___test.run_test(-1);

}

// END CUT HERE
