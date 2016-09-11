// BEGIN CUT HERE

// END CUT HERE
#line 5 "SumThemAll.cpp"

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

vector<int> ch(ll x) {
	vector<int> ret;
	while(x) {
		ret.push_back(x % 10);
		x /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

ll f(ll x) {
	if(x <= 0) return 0;
	vector<int> v = ch(x);
	vector<int> t(v.size());
	ll tt = 1;
	rep(i, v.size()) {
		t.push_back(tt);
		tt *= 10;
	}
	reverse(t.begin(), t.end());
	t.push_back(0);

	ll ret = 0;
	rep(i, v.size()) {

		ll a = (v.size() - 1 - i) * 45;
		rep(j, v[i]) {
			ret += j * t[i];
			ret += a * t[i+1];
		}

		x -= t[i] * v[i];
		// cout << v[i] << " " << t[i] << " " << x << " " << a << " " << a * t[i+1] << endl;
		ret += x * v[i];
	}

	return ret;
}

class SumThemAll {
	public:
	long long getSum(int lowerBound, int upperBound) {
		return f(upperBound+1) - f(lowerBound);
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 3; long long Arg2 = 6LL; verify_case(0, Arg2, getSum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 14; long long Arg2 = 15LL; verify_case(1, Arg2, getSum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 0; long long Arg2 = 0LL; verify_case(2, Arg2, getSum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 14; int Arg1 = 53; long long Arg2 = 296LL; verify_case(3, Arg2, getSum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 24660; int Arg1 = 308357171; long long Arg2 = 11379854844LL; verify_case(4, Arg2, getSum(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    SumThemAll ___test;

    ___test.run_test(-1);

}

// END CUT HERE
