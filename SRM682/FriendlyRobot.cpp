// BEGIN CUT HERE

// END CUT HERE
#line 5 "FriendlyRobot.cpp"
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
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll dp[305][305];

class FriendlyRobot {
	public:
	int findMaximumReturns(string s, int K) {

		vector<int> X(s.size() + 1), Y(s.size() + 1);
		int x = 0, y = 0;
		rep(i, s.size()) {
			if(s[i] == 'U') y++;
			if(s[i] == 'D') y--;
			if(s[i] == 'R') x++;
			if(s[i] == 'L') x--;

			X[i+1] = x; Y[i+1] = y;
		}

		rep(i, s.size() + 1) {
			rep(j, K + 1) {
				dp[i][j] = -1;
			}
		}
		dp[0][0] = 0;

		rep(i, s.size() + 1) {
			rep(j, K + 1) {
				if(dp[i][j] == -1) continue;
				for(int k = i + 2; k < s.size() + 1; k += 2) {
					int s = abs(X[k] - X[i]), t = abs(Y[k] - Y[i]);
					int res = 0;

					if(s % 2 == 0 && t % 2 == 1) continue;
					if(s % 2 == 1 && t % 2 == 0) continue;
					if(s % 2 == 0 && t % 2 == 0) res = s / 2 + t / 2;
					if(s % 2 == 1 && t % 2 == 1) res = s / 2 + t / 2 + 1;

					if(j + res > K) continue;
					dp[k][j + res] = max(dp[k][j + res], dp[i][j] + 1);
				}
			}
		}

		ll ans = 0;
		rep(i, s.size() + 1) {
			rep(j, K + 1) {
				ans = max(ans, dp[i][j]);
			}
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "UULRRLLL"; int Arg1 = 1; int Arg2 = 3; verify_case(0, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ULDR"; int Arg1 = 0; int Arg2 = 1; verify_case(1, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ULDR"; int Arg1 = 2; int Arg2 = 2; verify_case(2, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ULDRRLRUDUDLURLUDRUDL"; int Arg1 = 4; int Arg2 = 8; verify_case(3, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "LRLDRURDRDUDDDDRLLRUUDURURDRRDRULRDLLDDDDRLRRLLRRDDLRURLRULLLLLRRRDULRULULRLRDLLDDLLRDLUUDUURRULUDUDURULULLDRUDUUURRRURUULRLDLRRRDLLDLRDUULUURUDRURRLURLDLDDUUURRURRLRDLDDULLUDLUDULRDLDUURLUUUURRLRURRDLRRLLLRDRDUUUDRRRDLDRRUUDUDDUDDRLUDDULRURRDRUDLDLLLDLUDDRLURLDUDRUDDDDURLUUUDRLURDDDDLDDRDLUDDLDLURR"; int Arg1 = 47; int Arg2 = 94; verify_case(4, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU"; int Arg1 = 300; int Arg2 = 150; verify_case(5, Arg2, findMaximumReturns(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "UD"; int Arg1 = 1; int Arg2 = 1; verify_case(6, Arg2, findMaximumReturns(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FriendlyRobot ___test;
    ___test.run_test(-1);
}
// END CUT HERE
