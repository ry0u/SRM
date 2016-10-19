// BEGIN CUT HERE

// END CUT HERE
#line 5 "CyclicGame.cpp"

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

double dp[2000][50]; //iからスタートして得られる得点の最大値

class CyclicGame {
	public:
	double estimateBank(vector <int> cells) {
		int n = cells.size();
		memset(dp, 0, sizeof(dp));

		rep(t, 2000) {
			rep(i, n) {
				double p = 0.0;
				rep(j, 6) {
					int k = (i + j + 1) % n;
					p += cells[k] + dp[t][k];
				}
				p /= 6.0;
				dp[t+1][i] = max(dp[t][i], p);
			}
		}

		return dp[1999][0];
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-10, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.3611111111111112; verify_case(0, Arg1, estimateBank(Arg0)); }
	void test_case_1() { int Arr0[] = {-10, 7, -5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.30434782608695654; verify_case(1, Arg1, estimateBank(Arg0)); }
	void test_case_2() { int Arr0[] = {-1, -2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(2, Arg1, estimateBank(Arg0)); }
	void test_case_3() { int Arr0[] = {-40, 9, 9, 9, 9, 9, -44, 9, 9, 9, 9, 9, -40, 15, 15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.5653612433724144; verify_case(3, Arg1, estimateBank(Arg0)); }
	void test_case_4() { int Arr0[] = {-36, 95, -77, -95, 49, -52, 42, -34, -1, 98, -20, 96, -96, 23, -52}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 12.395613307567126; verify_case(4, Arg1, estimateBank(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    CyclicGame ___test;

    ___test.run_test(-1);

}

// END CUT HERE
