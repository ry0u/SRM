// BEGIN CUT HERE

// END CUT HERE
#line 5 "InfiniteString.cpp"
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

class InfiniteString {
	public:
	string equal(string s, string t) {
		int n = s.size();
		int m = t.size();

		stringstream ss;
		rep(i,n)
		{
			ss << t;
		}

		string ret = ss.str();

		stringstream ss2;
		rep(i,m)
		{
			ss2 << s;
		}

		string ret2 = ss2.str();
		
		if(ret == ret2) return "Equal";
		else return "Not equal";
	}




	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ab"; string Arg1 = "abab"; string Arg2 = "Equal"; verify_case(0, Arg2, equal(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abc"; string Arg1 = "bca"; string Arg2 = "Not equal"; verify_case(1, Arg2, equal(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "abab"; string Arg1 = "aba"; string Arg2 = "Not equal"; verify_case(2, Arg2, equal(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "aaaaa"; string Arg1 = "aaaaaa"; string Arg2 = "Equal"; verify_case(3, Arg2, equal(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "ababab"; string Arg1 = "abab"; string Arg2 = "Equal"; verify_case(4, Arg2, equal(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "a"; string Arg1 = "z"; string Arg2 = "Not equal"; verify_case(5, Arg2, equal(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    InfiniteString ___test;
    ___test.run_test(-1);
}
// END CUT HERE