#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

bool vowels(char c) {
	if(c == 'A'|| c == 'E' || c == 'I' || c == 'O' ||  c == 'U') return true;
	return false;
}

bool dp[55][55][55][2];

class NiceOrUgly {

    public:

    string describe(string s) {
		
		memset(dp, 0, sizeof(dp));
		dp[0][0][0][0] = true;

		rep(i, s.size()) {
			rep(j, 3) {
				rep(k, 5) {
					rep(l, 2) {
						if(dp[i][j][k][l]) {
							if(s[i] == '?') {
								if(j + 1 == 3) {
									dp[i+1][j+1][0][1] = true;
								} else {
									dp[i+1][j+1][0][0] = true;
								}

								if(k + 1 == 5) {
									dp[i+1][0][k+1][1] = true;
								} else {
									dp[i+1][0][k+1][0] = true;
								}
							} else {
								if(vowels(s[i])) {
									if(j + 1 == 3) {
										dp[i+1][j+1][0][1] = true;
									} else {
										dp[i+1][j+1][0][0] = true;
									}
								} else {
									if(k + 1 == 5) {
										dp[i+1][0][k+1][1] = true;
									} else {
										dp[i+1][0][k+1][0] = true;
									}
								}
							}
						}
					}
				}
			}
		}

		bool flag = false;
		rep(i, s.size() + 1) {
			rep(j, 4) {
				rep(k, 6) {
					flag |= dp[i][j][k][1];
				}
			}
		}

		if(flag) {
			bool check = false;
			rep(j, 4) {
				rep(k, 6) {
					check |= dp[s.size()][j][k][0];
				}
			}

			if(check) return "42";
			return "UGLY";
		}
		else return "NICE";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "HELLOWORLD"; string Arg1 = "NICE"; verify_case(0, Arg1, describe(Arg0)); }
	void test_case_1() { string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; string Arg1 = "UGLY"; verify_case(1, Arg1, describe(Arg0)); }
	void test_case_2() { string Arg0 = "HELLOW?RLD"; string Arg1 = "42"; verify_case(2, Arg1, describe(Arg0)); }
	void test_case_3() { string Arg0 = "H??LOWOR??"; string Arg1 = "NICE"; verify_case(3, Arg1, describe(Arg0)); }
	void test_case_4() { string Arg0 = "EE?FFFF"; string Arg1 = "UGLY"; verify_case(4, Arg1, describe(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    NiceOrUgly ___test;

    ___test.run_test(-1);

}

// END CUT HERE
