// BEGIN CUT HERE

// END CUT HERE
#line 5 "RugSizes.cpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

class RugSizes {
	public:
	int rugCount(int a) {
		int cnt = 0;

		REP(i, 1, sqrt(a) + 1) {
			if(a % i != 0) continue;
			int b = a / i;
			if(i > b) continue;
			if(i != b && i % 2 == 0 && b % 2 == 0) continue;
			cnt++;
		}

		return cnt;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; verify_case(0, Arg1, rugCount(Arg0)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 1; verify_case(1, Arg1, rugCount(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    RugSizes ___test;

    ___test.run_test(-1);

}

// END CUT HERE
