// BEGIN CUT HERE

// END CUT HERE
#line 5 "CollectingPayment.cpp"

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

double dp[400], E[400];

class CollectingPayment {
	public:
	double maximumProfit(vector <int> earning, vector <int> moment, int fee, int rate) {
		int n = earning.size();

		memset(E, 0, sizeof(E));
		rep(i, n) {
			E[moment[i]] = earning[i];
		}

		memset(dp, 0, sizeof(dp));

		rep(i, 366) {
			if(i % 7 == 1) 
				dp[i] = dp[i] * (1.0 + double(rate) / 1000.0);

			double sum = 0.0;
			int cnt = 0;
			REP(j, i+1, 366) {
				sum += E[j];
				if(j % 7 == 1) cnt++;
				if(sum < fee) continue;

				dp[j] = max(dp[j], (dp[i] * pow(1.0 + rate / 1000.0, cnt - (j % 7 == 1)) + sum - fee));
			}
		}

		double ans = 0;
		rep(i, 366) {
			ans = max(ans, dp[i]);
			int cnt = 0;
			REP(j, i+1, 366) {
				if(j % 7 == 1) {
					cnt++;
				}
			}
			ans = max(ans, dp[i] * pow(1.0 + rate / 1000.0, cnt));
		}
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {300,290,320,150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {120,124,200,202}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 40; int Arg3 = 10; double Arg4 = 1325.1174146859212; verify_case(0, Arg4, maximumProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {300,290,320,150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,122,243,365}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 40; int Arg3 = 10; double Arg4 = 1240.733092976253; verify_case(1, Arg4, maximumProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {300,290,320,150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,122,243,365}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 200; int Arg3 = 10; double Arg4 = 868.6; verify_case(2, Arg4, maximumProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {365}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; int Arg3 = 100; double Arg4 = 110.0; verify_case(3, Arg4, maximumProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {1000,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {155,365}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 100; double Arg4 = 17274.90824619758; verify_case(4, Arg4, maximumProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {1,346,7,346,345,3,453,5,346,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,7,34,74,163,200,250,352,360}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 0; double Arg4 = 1855.0; verify_case(5, Arg4, maximumProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {1,346,7,346,345,3,453,5,346,354,25,23,354,235,235}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,7,34,74,98,154,163,178,200,210,250,279,325,352,360}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; int Arg3 = 10; double Arg4 = 3693.6800093457805; verify_case(6, Arg4, maximumProfit(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    CollectingPayment ___test;

    ___test.run_test(-1);

}

// END CUT HERE
