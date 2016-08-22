// BEGIN CUT HERE

// END CUT HERE
#line 5 "SpiralNumbers.cpp"

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

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

string ans(ll y, ll x) {
	stringstream ss;
	ss << "(" << y << "," << x << ")";
	return ss.str();
}

class SpiralNumbers {
	public:
	string getPosition(int N) {
		if(N == 1) return ans(0, 0);

		ll l = 1, r = 1, t = 1;
		while(true) {
			if(l <= N && N <= r) break;
			t += 2;
			l = r + 1;
			r = t * t;
		}

		vector<ll> v(5);
		v[0] = t * t - 4 * (t - 1) + 1;
		v[1] = t * t - 3 * (t - 1);
		v[2] = t * t - 2 * (t - 1);
		v[3] = t * t - (t - 1);
		v[4] = t * t;

		vector<ll> y(5), x(5);
		y[0] = t / 2 - 1; x[0] = t / 2;
		y[1] = y[0] - (t - 2); x[1] = t / 2;
		y[2] = y[1]; x[2] = x[1] - (t - 1);
		y[3] = y[2] + t - 1; x[3] = x[2];
		y[4] = y[3]; x[4] = x[3] + (t - 1);

		ll R = 0, C = 0;
		rep(i, 4) {
			if(v[i] <= N && N <= v[i+1]) {
				ll cnt = N - v[i];
				R = y[i] + cnt * dy[i];
				C = x[i] + cnt * dx[i];
			}
		}

		return ans(-R, C);
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; string Arg1 = "(0,1)"; verify_case(0, Arg1, getPosition(Arg0)); }
	void test_case_1() { int Arg0 = 3; string Arg1 = "(1,1)"; verify_case(1, Arg1, getPosition(Arg0)); }
	void test_case_2() { int Arg0 = 7; string Arg1 = "(-1,-1)"; verify_case(2, Arg1, getPosition(Arg0)); }
	void test_case_3() { int Arg0 = 17; string Arg1 = "(2,-2)"; verify_case(3, Arg1, getPosition(Arg0)); }
	void test_case_4() { int Arg0 = 24; string Arg1 = "(-2,1)"; verify_case(4, Arg1, getPosition(Arg0)); }
	void test_case_5() { int Arg0 = 830; string Arg1 = "(-14,3)"; verify_case(5, Arg1, getPosition(Arg0)); }
	void test_case_6() { int Arg0 = 765409; string Arg1 = "(-437,221)"; verify_case(6, Arg1, getPosition(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    SpiralNumbers ___test;

    ___test.run_test(-1);

}

// END CUT HERE
