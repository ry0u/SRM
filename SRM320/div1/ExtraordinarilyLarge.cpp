// BEGIN CUT HERE

// END CUT HERE
#line 5 "ExtraordinarilyLarge.cpp"

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

class ExtraordinarilyLarge {
	public:
	string compare(string x, string y) {
		ll a = 0, b = 0;
		int ac = 0, bc = 0;

		stringstream ss;
		rep(i, x.size()) {
			if(x[i] == '!') {
				ac++;
				continue;
			}
			ss << x[i];
		}
		ss >> a;

		if(a == 0 && ac > 0) {
			a = 1;
			ac--;
		}

		stringstream ss2;
		rep(i, y.size()) {
			if(y[i] == '!') {
				bc++;
				continue;
			}
			ss2 << y[i];
		}
		ss2 >> b;

		if(b == 0 && bc > 0) {
			b = 1;
			bc--;
		}

		vector<string> ans(3);
		ans[0] = "x<y"; ans[1] = "x>y"; ans[2] = "x=y";

		if(ac > bc) {
			swap(ac, bc);
			swap(a, b);
			swap(ans[0], ans[1]);
		}

		while(ac < bc) {
			bc--;

			ll nb = 1;
			for(int i = b; i >= 1; i--) {
				nb *= i;
				if(nb > a) break;
			}
			b = nb;
			if(b > a) break;
		}

		if(a == b) {
			return ans[2];
		} else if(a < b) {
			return ans[0];
		} else {
			return ans[1];
		}
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "0!"; string Arg1 = "1"; string Arg2 = "x=y"; verify_case(0, Arg2, compare(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "9!"; string Arg1 = "999999999"; string Arg2 = "x<y"; verify_case(1, Arg2, compare(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "9!!"; string Arg1 = "999999999"; string Arg2 = "x>y"; verify_case(2, Arg2, compare(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "456!!!"; string Arg1 = "123!!!!!!"; string Arg2 = "x<y"; verify_case(3, Arg2, compare(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "5!"; string Arg1 = "120"; string Arg2 = "x=y"; verify_case(4, Arg2, compare(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    ExtraordinarilyLarge ___test;

    ___test.run_test(-1);
	cout << ___test.compare("0!", "0!!!!!!!!!!") << endl;
}

// END CUT HERE
