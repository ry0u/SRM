// BEGIN CUT HERE

// END CUT HERE
#line 5 "BearPair.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

class BearPair {
	public:
	int bigDistance(string s) {
		int ans = -1;
		int n = s.size();

		rep(i, n) {
			REP(j, i + 1, n) {
				if(s[i] != s[j]) {
					ans = max(ans, j - i);
				}
			}
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "bear"; int Arg1 = 3; verify_case(0, Arg1, bigDistance(Arg0)); }
	void test_case_1() { string Arg0 = "abcba"; int Arg1 = 3; verify_case(1, Arg1, bigDistance(Arg0)); }
	void test_case_2() { string Arg0 = "oooohyeahpotato"; int Arg1 = 13; verify_case(2, Arg1, bigDistance(Arg0)); }
	void test_case_3() { string Arg0 = "zzzzzzzzzzzzzzzzzzzzz"; int Arg1 = -1; verify_case(3, Arg1, bigDistance(Arg0)); }
	void test_case_4() { string Arg0 = "qw"; int Arg1 = 1; verify_case(4, Arg1, bigDistance(Arg0)); }
	void test_case_5() { string Arg0 = "xxyyxyxyyyyyyxxxyxyxxxyxyxyyyyyxxxxxxyyyyyyyyxxxxx"; int Arg1 = 47; verify_case(5, Arg1, bigDistance(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    BearPair ___test;
    ___test.run_test(-1);
}
// END CUT HERE
