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

class Shopping {

    public:

    int minNumber(int X, vector <int> values) {
		sort(values.begin(), values.end());

		vector<bool> dp(1005);
		dp[0] = true;

		vector<int> ans;
		REP(i, 1, X + 1) {
			if(dp[i]) continue;

			int res = i;
			vector<int> v;
			for(int j = values.size()-1; j >= 0; j--) {
				if(res - values[j] >= 0) {
					res -= values[j];
					v.push_back(values[j]);
					ans.push_back(values[j]);
					j++;
				}

				if(dp[res]) break;
			}

			vector<bool> dp2 = dp;
			REP(j, 0, X + 1) {
				if(dp[j]) {
					rep(k, v.size()) {
						if(j + v[k] <= X) {
							dp2[j + v[k]] = true;
						}
					}
				}
			}

			dp = dp2;
		}

		rep(i, X + 1) {
			if(!dp[i]) return -1;
		}

		return ans.size();
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 20; int Arr1[] = {1, 2, 5, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, minNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arr1[] = {2, 4, 1, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, minNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; int Arr1[] = {2,4,6,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, minNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 600; int Arr1[] = {1,2,3,10,11,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; verify_case(3, Arg2, minNumber(Arg0, Arg1)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    Shopping ___test;

    ___test.run_test(-1);

}

// END CUT HERE
