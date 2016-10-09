// BEGIN CUT HERE

// END CUT HERE
#line 5 "PlacingPieces.cpp"

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

int dp[55][55][1005];

class PlacingPieces {
	public:
	int optimalPlacement(int L, vector <int> pieces) {
		int n = pieces.size();
		sort(pieces.begin(), pieces.end());

		int ans = n;

		rep(i, n) {
			int sum = i;
			rep(j, i + 1) sum += pieces[j];
			if(sum > L) continue;

			memset(dp, 0, sizeof(dp));
		}

		rep(t, n + 1) {
			int sum = 0;
			rep(j, t) sum += pieces[j];
			if(sum > L) break;

			memset(dp, false, sizeof(dp));

			dp[t][t][sum] = true;
			REP(i, t, n) {
				REP(j, t, n) {
					rep(k, 1005) {
						if(dp[i][j][k]) {
							dp[i+1][j][k] = dp[i][j][k];
							if(k + pieces[i] < 1005) dp[i+1][j+1][k+pieces[i]] = dp[i][j][k];
						} 
					}
				}
			}

			rep(i, n + 1) {
				rep(j, L + 1) {
					if(dp[n][i][j]) {
						double res = double(L - j) / (i + 1);
						if(res < pieces[t]) {
							ans = min(ans, i);
						}
					}
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
	void test_case_0() { int Arg0 = 9; int Arr1[] = {1, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, optimalPlacement(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 36; int Arr1[] = {1, 1, 5, 5, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, optimalPlacement(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 37; int Arr1[] = {1, 1, 5, 5, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, optimalPlacement(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 18; int Arr1[] = {2, 2, 2, 9, 9, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, optimalPlacement(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {2, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, optimalPlacement(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 703; int Arr1[] = {73, 76, 90, 42, 84, 13, 57, 88, 80, 45, 80, 1, 78, 41, 73, 40, 97, 42}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(5, Arg2, optimalPlacement(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    PlacingPieces ___test;

    ___test.run_test(-1);

    // ___test.run_test(0);
    // ___test.run_test(1);
    // ___test.run_test(2);
    // ___test.run_test(4);
	// cout << ___test.optimalPlacement(52, {11, 15, 18, 1}) << endl; // 2
}

// END CUT HERE
