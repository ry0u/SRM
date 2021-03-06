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

ll memo[5000005], k;

ll f(ll x) {
	ll ret = 0;
	while(x) {
		ll y = (x % 10), t = 1;
		rep(i, k) {
			t *= y;
		}
		ret += t;
		x /= 10;
	}
	return ret;
}

ll dfs(ll x) {
	if(memo[x] != -1) {
		if(memo[x] == INF) {
			ll y = x, res = x;
			while(true) {
				y = f(y);
				res = min(res, y);
				if(y == x) break;
			}
			return memo[x] = res;
		} else return memo[x];
	}

	memo[x] = INF;
	ll res = min(x, dfs( f(x)) );
	return memo[x] = res;
}

class ExtendedHappyNumbers {

    public:

    long long calcTheSum(int A, int B, int K) {
		ll ans = 0;
		memset(memo, -1, sizeof(memo));
		k = K;

		REP(i, A, B + 1) {
			ans += dfs(i);
		}

		return ans;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 13; int Arg1 = 13; int Arg2 = 2; long long Arg3 = 1LL; verify_case(0, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 2; long long Arg3 = 14LL; verify_case(1, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 99; int Arg2 = 1; long long Arg3 = 450LL; verify_case(2, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 535; int Arg1 = 538; int Arg2 = 3; long long Arg3 = 820LL; verify_case(3, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 400000; int Arg2 = 6; long long Arg3 = 5169721292LL; verify_case(4, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    ExtendedHappyNumbers ___test;

    ___test.run_test(-1);
}

// END CUT HERE
