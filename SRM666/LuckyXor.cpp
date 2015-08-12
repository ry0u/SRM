// BEGIN CUT HERE

// END CUT HERE
#line 5 "LuckyXor.cpp"
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

bool func(string s) {
    rep(i,s.size()) {
        if(s[i] == '4' || s[i] == '7') continue;
        return false;
    }

    return true;
}

class LuckyXor {
	public:
	int construct(int a) {
        int t = a;
        REP(i,a,101) {
            t = a;
            t ^= i;

            stringstream ss;
            ss << t;

            if(func(ss.str())) {
                return i;
            }
        }

        return -1;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 40; verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arg0 = 19; int Arg1 = 20; verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { int Arg0 = 88; int Arg1 = 92; verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { int Arg0 = 36; int Arg1 = -1; verify_case(3, Arg1, construct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    LuckyXor ___test;
    ___test.run_test(-1);
}
// END CUT HERE
