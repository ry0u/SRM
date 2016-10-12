#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

class ReversingBrackets {

    public:

    string removeBrackets(string s) {
		int n = s.size();
		string a = "", b = "", c = "";

		int l = -1, r = -1;
		rep(i, n) {
			if(s[i] == '[') l = i;
			if(s[i] == ']') r = i;
		}

		if(l == -1 && r == -1) {
			return s;
		}

		rep(i, l) {
			if(s[i] == '[' || s[i] == ']') continue;
			a += s[i];
		}

		for(int i = r; i >= l; i--) {
			if(s[i] == '[' || s[i] == ']') continue;
			b += s[i];
		}

		REP(i, r+1, n) {
			if(s[i] == '[' || s[i] == ']') continue;
			c += s[i];
		}

		return a + b + c;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "he[row oll]ld"; string Arg1 = "hello world"; verify_case(0, Arg1, removeBrackets(Arg0)); }
	void test_case_1() { string Arg0 = "ab[edc]f"; string Arg1 = "abcdef"; verify_case(1, Arg1, removeBrackets(Arg0)); }
	void test_case_2() { string Arg0 = "topcoder"; string Arg1 = "topcoder"; verify_case(2, Arg1, removeBrackets(Arg0)); }
	void test_case_3() { string Arg0 = "[desrever lla]"; string Arg1 = "all reversed"; verify_case(3, Arg1, removeBrackets(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    ReversingBrackets ___test;

    ___test.run_test(-1);

}

// END CUT HERE
