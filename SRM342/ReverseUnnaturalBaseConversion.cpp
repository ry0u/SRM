// BEGIN CUT HERE

// END CUT HERE
#line 5 "ReverseUnnaturalBaseConversion.cpp"
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

class ReverseUnnaturalBaseConversion {
	public:
	string convertToBase(int x, int b) {
		if(x == 0) return "0";

		bool flag = false;
		if(x < 0 && b > 0) {
			flag = true;
			x = abs(x);
		}

		int c = abs(b);
		string ans = "";

		while(x != 0) {
			int t = (x % c + c) % c;
			ans = char('0' + t) + ans;
			x = (x - t) / b;
		}

		if(flag) ans = "-" + ans;
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 12345; int Arg1 = 10; string Arg2 = "12345"; verify_case(0, Arg2, convertToBase(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8265; int Arg1 = -10; string Arg2 = "12345"; verify_case(1, Arg2, convertToBase(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1001; int Arg1 = -2; string Arg2 = "10000111001"; verify_case(2, Arg2, convertToBase(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = -52; int Arg1 = -2; string Arg2 = "11011100"; verify_case(3, Arg2, convertToBase(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = -38; int Arg1 = 4; string Arg2 = "-212"; verify_case(4, Arg2, convertToBase(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = -123456789; int Arg1 = -7; string Arg2 = "3031330536"; verify_case(5, Arg2, convertToBase(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 0; int Arg1 = 2; string Arg2 = "0"; verify_case(6, Arg2, convertToBase(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    ReverseUnnaturalBaseConversion ___test;

    ___test.run_test(-1);

}

// END CUT HERE
