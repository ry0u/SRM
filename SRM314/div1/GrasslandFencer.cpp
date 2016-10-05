// BEGIN CUT HERE

// END CUT HERE
#line 5 "GrasslandFencer.cpp"

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

double f(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double dp[1 << 20];

class GrasslandFencer {
	public:
	double maximalFencedArea(vector <int> fences) {
		int n = fences.size();
		sort(fences.begin(), fences.end());

		memset(dp, 0, sizeof(dp));

		rep(bit, 1<<n) {
			rep(i, n) {
				REP(j, i+1, n) {
					REP(k, j+1, n) {
						double a = fences[i];
						double b = fences[j];
						double c = fences[k];

						if(a + b <= c) continue;

						int state = 0;
						state |= (1 << i);
						state |= (1 << j);
						state |= (1 << k);

						if(bit & state) continue;

						dp[bit | state] = max(dp[bit | state], dp[bit] + f(a, b, c));
					}
				}
			}
		}

		double ans = 0;
		rep(bit, 1<<n) {
			ans = max(ans, dp[bit]);
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 36.754383146489694; verify_case(0, Arg1, maximalFencedArea(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,4,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(1, Arg1, maximalFencedArea(Arg0)); }
	void test_case_2() { int Arr0[] = {7,4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 6.928203230275509; verify_case(2, Arg1, maximalFencedArea(Arg0)); }
	void test_case_3() { int Arr0[] = {21,72,15,55,16,44,54,63,69,35,75,69,76,70,50,81}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 7512.322360676162; verify_case(3, Arg1, maximalFencedArea(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    GrasslandFencer ___test;

    ___test.run_test(-1);

}

// END CUT HERE
