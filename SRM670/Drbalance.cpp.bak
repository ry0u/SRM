// BEGIN CUT HERE

// END CUT HERE
#line 5 "Drbalance.cpp"
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

class Drbalance {
	public:
	int lesscng(string s, int k) {
        int n = s.size();
        int sum = 0;
        int ans = 0;

        rep(i,n) {
            if(s[i] == '+') sum++;
            else sum--;
        }

        vector<int> v(n);
        int cnt = 0;
        for(int i=n-1; i>=0; i--) {
            v[i] = sum;

            if(sum < 0) {
                cnt++;
            }

            if(s[i] == '+') sum--;
            else sum++;
        }

        while(cnt > k) {
            rep(i,n) {
                if(s[i] == '-') {
                    s[i] = '+';
                    ans++;
                    REP(j,i,n) {
                        v[j] += 2;
                    }

                    cnt = 0;
                    rep(j,n) {
                        if(v[j] < 0) cnt++;
                    }

                    break;
                }
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
	void test_case_0() { string Arg0 = "---"; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "+-+-"; int Arg1 = 0; int Arg2 = 0; verify_case(1, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "-+-+---"; int Arg1 = 2; int Arg2 = 1; verify_case(2, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "-------++"; int Arg1 = 3; int Arg2 = 3; verify_case(3, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "-+--+--+--++++----+"; int Arg1 = 3; int Arg2 = 2; verify_case(4, Arg2, lesscng(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    Drbalance ___test;
    ___test.run_test(-1);
}
// END CUT HERE
