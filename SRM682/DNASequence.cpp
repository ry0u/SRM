// BEGIN CUT HERE

// END CUT HERE
#line 5 "DNASequence.cpp"
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

bool ch(char c){
	if(c == 'A') return true;
	if(c == 'C') return true;
	if(c == 'G') return true;
	if(c == 'T') return true;
	return false;
}


class DNASequence {
	public:
	int longestDNASequence(string s) {
		int ans = 0;

		rep(i, s.size()) {
			if(ch(s[i])) {
				int res = 1;
				REP(j, i+1, s.size()) {
					if(ch(s[j])) {
						res++;
						i++;
					} else break;
				}
				ans = max(ans, res);
			}
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "TOPBOATER"; int Arg1 = 2; verify_case(0, Arg1, longestDNASequence(Arg0)); }
	void test_case_1() { string Arg0 = "SUSHI"; int Arg1 = 0; verify_case(1, Arg1, longestDNASequence(Arg0)); }
	void test_case_2() { string Arg0 = "GATTACA"; int Arg1 = 7; verify_case(2, Arg1, longestDNASequence(Arg0)); }
	void test_case_3() { string Arg0 = "GOODLUCK"; int Arg1 = 1; verify_case(3, Arg1, longestDNASequence(Arg0)); }
	void test_case_4() { string Arg0 = "VVZWKCSIQEGANULDLZESHUYHUQGRKUMFCGTATGOHMLKBIRCA"; int Arg1 = 6; verify_case(4, Arg1, longestDNASequence(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    DNASequence ___test;
    ___test.run_test(-1);
}
// END CUT HERE
