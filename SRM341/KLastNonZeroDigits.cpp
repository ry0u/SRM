// BEGIN CUT HERE

// END CUT HERE
#line 5 "KLastNonZeroDigits.cpp"
#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,k,n) for(int i=k;i<(int)(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

class KLastNonZeroDigits {
	public:
	string getKDigits(int N, int K) {
		ll x = 1;

		for(int i = N; i >= 1; i--) {
			x *= i;

			while(x % 10 == 0) x /= 10;
		}

		string ans = "";
		rep(i, K) {
			int t = x % 10;
			ans += char('0' + t);

			x /= 10;
			if(x == 0) break;
		}

		reverse(ans.begin(), ans.end());
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 3; string Arg2 = "288"; verify_case(0, Arg2, getKDigits(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 1; string Arg2 = "2"; verify_case(1, Arg2, getKDigits(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 3; string Arg2 = "72"; verify_case(2, Arg2, getKDigits(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 2; string Arg2 = "04"; verify_case(3, Arg2, getKDigits(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 20; int Arg1 = 9; string Arg2 = "200817664"; verify_case(4, Arg2, getKDigits(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1; string Arg2 = "1"; verify_case(5, Arg2, getKDigits(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    KLastNonZeroDigits ___test;

    ___test.run_test(-1);

}

// END CUT HERE
