// BEGIN CUT HERE

// END CUT HERE
#line 5 "PolyMove.cpp"

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

double dp[55][2];

class PolyMove {
	public:
	double addedArea(vector <int> x, vector <int> y) {
		int n = x.size();
		memset(dp, 0, sizeof(dp));

		REP(i, 1, n) {
			int j = (i - 1 + n) % n;
			int k = (i + 1 + n) % n;

			dp[i][0] = max(dp[j][0], dp[j][1]);
			dp[i][1] = dp[j][0] + sqrt((x[j] - x[k]) * (x[j] - x[k]) + (y[j] - y[k]) * (y[j] - y[k]));
		}

		double ans = 0;
		rep(i, n) {
			rep(j, 2) {
				ans = max(ans, dp[i][j]);
			}
		}

		memset(dp, 0, sizeof(dp));
		rep(i, n - 1) {
			int j = (i - 1 + n) % n;
			int k = (i + 1 + n) % n;

			dp[i][0] = max(dp[j][0], dp[j][1]);
			dp[i][1] = dp[j][0] + sqrt((x[j] - x[k]) * (x[j] - x[k]) + (y[j] - y[k]) * (y[j] - y[k]));
		}

		rep(i, n) {
			rep(j, 2) {
				ans = max(ans, dp[i][j]);
			}
		}

		return ans / 2;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, addedArea(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,1,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.4142135623730951; verify_case(1, Arg2, addedArea(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    PolyMove ___test;

    ___test.run_test(-1);

	cout << ___test.addedArea({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, {0, 9, 17, 24, 30, 35, 39, 42, 44, 0}) << endl;
	cout << ___test.addedArea({0, 2, 19, 30, 29}, {0, 300, 300, 1, 0}) << endl;
}

// END CUT HERE
