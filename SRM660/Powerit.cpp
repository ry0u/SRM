// BEGIN CUT HERE

// END CUT HERE
#line 5 "Powerit.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

ll func(ll x,ll n,ll m) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res = (res*x)%m;
        x = (x*x)%m;
        n >>= 1;
    }

    return res;
}

class Powerit {
	public:
	int calc(int n, int k, int m) {
		int ans = 0;
        ll d = 1;
        rep(i,k) {
            d *= 2;
            d %= (m-1);
        }
        d--;

        REP(i,1,n+1) {
            ans += func(i,d,m);
        }

        ans %= m;

        return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 107; int Arg3 = 10; verify_case(0, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 107; int Arg3 = 100; verify_case(1, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 107; int Arg3 = 69; verify_case(2, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 400; int Arg2 = 107; int Arg3 = 1; verify_case(3, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 2; int Arg2 = 10; int Arg3 = 5; verify_case(4, Arg3, calc(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    Powerit ___test;
    ___test.run_test(-1);
}
// END CUT HERE
