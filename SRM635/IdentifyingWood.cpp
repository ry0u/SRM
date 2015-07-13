// BEGIN CUT HERE

// END CUT HERE
#line 5 "IdentifyingWood.cpp"
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

class IdentifyingWood {
	public:
	string check(string s, string t) {
		bool flag = true;
        
        int id = 0;
        rep(i,t.size()) {
            bool ch = true;
            for(int j=id;id < s.size() && j < s.size();j++) {
                id++;
                if(t[i] == s[j]) {
                    ch = false;
                    break;
                }
            }

            if(ch) {
                flag = false;
                break;
            }
        }

        if(flag) return "Yep, it's wood.";
        else return "Nope.";
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "absdefgh"; string Arg1 = "asdf"; string Arg2 = "Yep, it's wood."; verify_case(0, Arg2, check(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "oxoxoxox"; string Arg1 = "ooxxoo"; string Arg2 = "Nope."; verify_case(1, Arg2, check(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "oxoxoxox"; string Arg1 = "xxx"; string Arg2 = "Yep, it's wood."; verify_case(2, Arg2, check(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "qwerty"; string Arg1 = "qwerty"; string Arg2 = "Yep, it's wood."; verify_case(3, Arg2, check(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "string"; string Arg1 = "longstring"; string Arg2 = "Nope."; verify_case(4, Arg2, check(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    IdentifyingWood ___test;
    ___test.run_test(-1);
}
// END CUT HERE
