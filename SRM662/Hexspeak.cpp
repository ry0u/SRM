// BEGIN CUT HERE

// END CUT HERE
#line 5 "Hexspeak.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

bool check(char c) {
    if(c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'O' || c == 'I') {
        return true;
    }
    return false;
}

class Hexspeak {
	public:
	string decode(long long c) {
		bool flag = true;

        stringstream ss;

        while(c != 0) {
            ll t = c%16;
            if(t >= 10) {
                ss << char('A' + (t-10));
            }
            else if(t == 0) {
                ss << "O";
            }
            else if(t == 1) {
                ss << "I";
            }
            else {
                ss << t;
            }

            c /= 16;
        }

        string s = ss.str();
        reverse(s.begin(),s.end());

        rep(i,s.size()) {
            if(!check(s[i])) flag = false;
        }

        if(flag) {
            return s;
        }
        else return "Error!";
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 257LL; string Arg1 = "IOI"; verify_case(0, Arg1, decode(Arg0)); }
	void test_case_1() { long long Arg0 = 258LL; string Arg1 = "Error!"; verify_case(1, Arg1, decode(Arg0)); }
	void test_case_2() { long long Arg0 = 3405691582LL; string Arg1 = "CAFEBABE"; verify_case(2, Arg1, decode(Arg0)); }
	void test_case_3() { long long Arg0 = 2882400001LL; string Arg1 = "ABCDEFOI"; verify_case(3, Arg1, decode(Arg0)); }
	void test_case_4() { long long Arg0 = 999994830345994239LL; string Arg1 = "DEOBIFFFFFFFFFF"; verify_case(4, Arg1, decode(Arg0)); }
	void test_case_5() { long long Arg0 = 1000000000000000000LL; string Arg1 = "Error!"; verify_case(5, Arg1, decode(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main() {
  Hexspeak ___test;
  ___test.run_test(-1);
}
// END CUT HERE
