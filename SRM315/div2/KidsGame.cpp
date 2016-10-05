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

class KidsGame {

    public:

    int kthKid(int n, int m, int k) {

		k--;
		for(int i = n; i > 0; i--) {
			if( (m - 1) % i == k) {
				return n - i + 1;
			}

			if(k > (m - 1) % i) {
				k -= (m - 1) % i + 1;
			} else {
				k = k + i - (m - 1) % i - 1;
			}
		}

		return -1;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 3; int Arg3 = 5; verify_case(0, Arg3, kthKid(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 1; int Arg3 = 1; verify_case(1, Arg3, kthKid(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 99; int Arg1 = 100; int Arg2 = 99; int Arg3 = 94; verify_case(2, Arg3, kthKid(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 19999; int Arg1 = 7; int Arg2 = 5; int Arg3 = 18019; verify_case(3, Arg3, kthKid(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 99999; int Arg1 = 11111; int Arg2 = 3; int Arg3 = 69557; verify_case(4, Arg3, kthKid(Arg0, Arg1, Arg2)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    KidsGame ___test;

    ___test.run_test(-1);

}

// END CUT HERE
