// BEGIN CUT HERE

// END CUT HERE
#line 5 "MinimumVariancePartition.cpp"
#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,k,n) for(int i=k;i<(int)(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

class MinimumVariancePartition {
	public:
	double minDev(vector <int> mixedSamples, int K) {
		vector<int> v = mixedSamples;
		sort(v.begin(), v.end());

		double dp[55][55];
		rep(i, 55) rep(j, 55) dp[i][j] = INF;
		dp[0][0] = 0;

		double var[55][55];
		memset(var, 0, sizeof(var));
		rep(i, v.size()) {
			REP(j, i+1, v.size()+1) {
				double mean = 0;
				REP(k, i, j) {
					mean += v[k];
				}
				mean /= (j - i);

				REP(k, i, j) {
					var[i][j] += (v[k] - mean) * (v[k] - mean);
				}
				var[i][j] /= (j - i);
			}
		}

		rep(i, v.size()) {
			REP(j, i+1, v.size()+1) {
				rep(k, K) {
					dp[j][k+1] = min(dp[j][k+1], dp[i][k] + var[i][j]);
				}
			}
		}

		return dp[v.size()][K];
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,4,7,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 7.5; verify_case(0, Arg2, minDev(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1000,500,1,500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 0.0; verify_case(1, Arg2, minDev(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {54,653,876,2,75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; double Arg2 = 0.0; verify_case(2, Arg2, minDev(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {42,234,10,1,123,545,436,453,74,85,34,999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; double Arg2 = 1700.7397959183672; verify_case(3, Arg2, minDev(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {923,456,12,12,542,234,11,12,10,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 1850.3333333333333; verify_case(4, Arg2, minDev(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    MinimumVariancePartition ___test;

    ___test.run_test(-1);

}

// END CUT HERE
