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

class AdditionCycles {

    public:

    int cycleLength(int n) {
		set<int> st;
		
		while(st.find(n) == st.end()) {
			st.insert(n);

			int a = n / 10;
			int b = n % 10;
			int c = (a + b) % 10;

			n = b * 10 + c;
		}

		return st.size();
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 26; int Arg1 = 4; verify_case(0, Arg1, cycleLength(Arg0)); }
	void test_case_1() { int Arg0 = 55; int Arg1 = 3; verify_case(1, Arg1, cycleLength(Arg0)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 1; verify_case(2, Arg1, cycleLength(Arg0)); }
	void test_case_3() { int Arg0 = 71; int Arg1 = 12; verify_case(3, Arg1, cycleLength(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    AdditionCycles ___test;

    ___test.run_test(-1);

}

// END CUT HERE
