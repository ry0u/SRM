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

class FunnyFence {

    public:

    int getLength(string s) {
		int ans = 0;
		rep(i, s.size()) {
			char c = s[i];
			int len = 1;

			REP(j, i+1, s.size()) {
				if(c != s[j]) {
					c = s[j];
					len++;
					i++;
				} else break;
			}
			
			ans = max(ans, len);
		}
		return ans;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "|-|-|"; int Arg1 = 5; verify_case(0, Arg1, getLength(Arg0)); }
	void test_case_1() { string Arg0 = "-|-|-|-"; int Arg1 = 7; verify_case(1, Arg1, getLength(Arg0)); }
	void test_case_2() { string Arg0 = "||||||"; int Arg1 = 1; verify_case(2, Arg1, getLength(Arg0)); }
	void test_case_3() { string Arg0 = "|-||-|-"; int Arg1 = 4; verify_case(3, Arg1, getLength(Arg0)); }
	void test_case_4() { string Arg0 = "|-|---|-|---|-|"; int Arg1 = 5; verify_case(4, Arg1, getLength(Arg0)); }
	void test_case_5() { string Arg0 = "|||-||--|--|---|-||-|-|-|--||---||-||-||-|--||"; int Arg1 = 8; verify_case(5, Arg1, getLength(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    FunnyFence ___test;

    ___test.run_test(-1);

}

// END CUT HERE
