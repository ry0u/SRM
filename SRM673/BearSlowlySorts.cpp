// BEGIN CUT HERE

// END CUT HERE
#line 5 "BearSlowlySorts.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

class BearSlowlySorts {
	public:
	int minMoves(vector <int> w) {
		int n = w.size();
		int a = 1001, b = 0;

		rep(i, w.size()) {
			a = min(a, w[i]);
			b = max(b, w[i]);
		}

		bool flag = true;
		REP(i, 1, n) {
			if(w[i] < w[i-1]) flag = false;
		}

		if(flag) {
			return 0;
		}

		if(w[0] == b && w[n-1] == a) {
			return 3;
		}else if(w[0] == a || w[n-1] == b) {
			return 1;
		} else {
			return 2;
		}
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,6,8,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minMoves(Arg0)); }
	void test_case_1() { int Arr0[] = {4,3,1,6,2,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minMoves(Arg0)); }
	void test_case_2() { int Arr0[] = {93,155,178,205,213,242,299,307,455,470,514,549,581,617,677}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minMoves(Arg0)); }
	void test_case_3() { int Arr0[] = {50,20,30,40,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minMoves(Arg0)); }
	void test_case_4() { int Arr0[] = {234,462,715,596,906,231,278,223,767,925,9,526,369,319,241,354,317,880,5,696}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, minMoves(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    BearSlowlySorts ___test;
    ___test.run_test(-1);
}
// END CUT HERE
