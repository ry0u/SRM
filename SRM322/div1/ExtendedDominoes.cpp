// BEGIN CUT HERE

// END CUT HERE
#line 5 "ExtendedDominoes.cpp"

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

class ExtendedDominoes {
	public:
	long long countCycles(vector <string> pieces) {
		int d[10];
		memset(d, 0, sizeof(d));

		rep(i, pieces.size()) {
			rep(j, 2) {
				d[pieces[i][j]-'0']++;
			}
		}

		rep(i, 10) {
			if(d[i] % 2 == 1) return 0;
		}

		ll  ans = 1;
		rep(i, 10) {
			while(d[i]) {
				ans *= (d[i] - 1);
				d[i] -= 2;
			}
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"12","25","45","24","28","18"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(0, Arg1, countCycles(Arg0)); }
	void test_case_1() { string Arr0[] = {"01","12","23","34","45"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(1, Arg1, countCycles(Arg0)); }
	void test_case_2() { string Arr0[] = {"09","12","24","14","57","79","05"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(2, Arg1, countCycles(Arg0)); }
	void test_case_3() { string Arr0[] = {"34","35","36","37","45","46","47","56","57","67"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 243LL; verify_case(3, Arg1, countCycles(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    ExtendedDominoes ___test;

    ___test.run_test(-1);

}

// END CUT HERE
