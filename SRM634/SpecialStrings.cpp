
// BEGIN CUT HERE

// END CUT HERE
#line 5 "SpecialStrings.cpp"
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

bool isSpecial(string s) {
    REP(i,1,s.size()) {
        if(s.substr(0,i) >= s.substr(i)) return false;
    }
    return true;
}

class SpecialStrings {
	public:
	string findNext(string c) {
        int n = c.size();

        for(int i=n-1;i>=0;i--) {
            if(c[i] == '1') continue;

            string s = c;
            REP(j,i,n) {
                s[j] = '1';
            }

            if(isSpecial(s)) {
                REP(j,i+1,n) {
                    s[j] = '0';
                    if(!isSpecial(s)) {
                        s[j] = '1';
                    }
                }
                return s;
            }
        }

        return "";
    }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "01"; string Arg1 = ""; verify_case(0, Arg1, findNext(Arg0)); }
	void test_case_1() { string Arg0 = "00101"; string Arg1 = "00111"; verify_case(1, Arg1, findNext(Arg0)); }
	void test_case_2() { string Arg0 = "0010111"; string Arg1 = "0011011"; verify_case(2, Arg1, findNext(Arg0)); }
	void test_case_3() { string Arg0 = "000010001001011"; string Arg1 = "000010001001101"; verify_case(3, Arg1, findNext(Arg0)); }
	void test_case_4() { string Arg0 = "01101111011110111"; string Arg1 = "01101111011111111"; verify_case(4, Arg1, findNext(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main() {
  SpecialStrings ___test;
  ___test.run_test(-1);
  cout << ___test.findNext("001111111111111111111111") << endl;
  cout << ___test.findNext("000111") << endl;
}
// END CUT HERE
