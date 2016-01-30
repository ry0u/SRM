// BEGIN CUT HERE

// END CUT HERE
#line 5 "PalindromePrime.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

bool prime[10000000];
void Eratosthenes(int n) {
	rep(i,n) prime[i] = true;
	prime[1] = false;

	REP(i,2,(int)sqrt(n)) {
		if(prime[i]) {
			for(int j=0;i*(j+2) < n;j++) {
				prime[i*(j+2)] = 0;
			}
		}
	}
}

class PalindromePrime {
	public:
	int count(int L, int R) {
		int ans = 0;

		Eratosthenes(1005);
		REP(i, L, R+1) {
			if(prime[i]) {
				stringstream ss;
				ss << i;

				bool flag = true;
				string s = ss.str();

				rep(j, s.size()/2) {
					if(s[j] == s[s.size()-1-j]) continue;
					flag = false;
				}

				if(flag) ans++;
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
	void test_case_0() { int Arg0 = 100; int Arg1 = 150; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 9; int Arg2 = 4; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 929; int Arg1 = 929; int Arg2 = 1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 0; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1000; int Arg2 = 20; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PalindromePrime ___test;
    ___test.run_test(-1);
}
// END CUT HERE
