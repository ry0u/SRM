#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int dp[10000000];
bool used[10000000];

class PreprimeNumbers {

    public:

    int nthNumber(int n) {
		ll i = 2;
		memset(dp, 0, sizeof(dp));
		memset(used, 0, sizeof(used));

		while(n) {
			if(dp[i] == 0 && i * i < 10000000 && i * i * i < 10000000) used[i * i * i] = true;
			if(dp[i] == 2 || used[i]) n--;

			for(ll j = i; j < 10000000; j += i) {
				dp[j]++;
			}
			i++;
		}

		return i - 1;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 8; verify_case(0, Arg1, nthNumber(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 14; verify_case(1, Arg1, nthNumber(Arg0)); }
	void test_case_2() { int Arg0 = 24; int Arg1 = 77; verify_case(2, Arg1, nthNumber(Arg0)); }
	void test_case_3() { int Arg0 = 43765; int Arg1 = 193539; verify_case(3, Arg1, nthNumber(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    PreprimeNumbers ___test;

    ___test.run_test(-1);

}

// END CUT HERE
