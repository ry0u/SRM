// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxAverageSequence.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,n) for(int i=0;i<n;i++)

#define MOD 1000000007

using namespace std;
typedef long long ll;

ll dp[2][2005][45][2];

class FoxAverageSequence {
	public:
	int theCount(vector <int> seq) {
        int n = seq.size();

        memset(dp,0,sizeof(dp));
        
        rep(i,41) {
            if(seq[0] != -1 && seq[0] != i) continue;
            dp[1][i][i][0] = 1;
        }

        REP(i,1,n) {
            int cur = i%2;
            int tar = cur^1;

            rep(j,2005) rep(k,45) rep(l,2) dp[tar][j][k][l] = 0;

            rep(x,1601) {
                rep(y,41) {
                    if(seq[i] != -1 && seq[i] != y) continue;
                    if(i*y > x || x+y > 1600) break;

                    rep(z,41) {
                        if(seq[i-1] != -1 && seq[i-1] != z) continue;
                        if(dp[cur][x][z][0] == 0 && dp[cur][x][z][1] == 0) continue;

                        if(y < z) dp[tar][x+y][y][1] = (dp[tar][x+y][y][1] + dp[cur][x][z][0]) % MOD;
                        else dp[tar][x+y][y][0] = (dp[tar][x+y][y][0] + dp[cur][x][z][0] + dp[cur][x][z][1]) % MOD;

                    }
                }
            }
        }

        ll res = 0;;
        rep(i,2001) {
            rep(x,41) {
                rep(y,2) {
                    res += dp[n%2][i][x][y];
                    res %= MOD;
                }
            }
        }

        return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 3, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {-1, 0, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {-1, 40, -1, -1, -1, 10, -1, -1, -1, 21, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 579347890; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {-1, 12, 25, 0, 18, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main() {
  FoxAverageSequence ___test;
  ___test.run_test(-1);
}
// END CUT HERE
