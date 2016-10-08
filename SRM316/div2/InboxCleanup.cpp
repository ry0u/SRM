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
#define INF 1<<28
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

class InboxCleanup {

    public:

    int fewestClicks(string messages, int low, int high) {
		int n = messages.size();
		int ans = INF;
		REP(t, low, high + 1) {
			int D = 0, len = 0, res = n / t - (n % t == 0);

			rep(i, n) {
				if(messages[i] == 'D') D++;
				len++;

				if(len % t == 0) {
					len = 0;
					if(D != 0) {
						res += min(t - D + 1 + 1, D + 1);
						D = 0;
					}
				}
			}

			if(len != 0 && D != 0) {
				res += min(len - D + 1 + 1, D + 1);
			}

			ans = min(ans, res);
		}
		return ans;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ".........."; int Arg1 = 5; int Arg2 = 10; int Arg3 = 0; verify_case(0, Arg3, fewestClicks(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = ".D.D.DD.D."; int Arg1 = 5; int Arg2 = 5; int Arg3 = 8; verify_case(1, Arg3, fewestClicks(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "...D..DDDDDD...D.DD.."; int Arg1 = 3; int Arg2 = 10; int Arg3 = 12; verify_case(2, Arg3, fewestClicks(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "D.D..D..DD.DDDD.D.DDD.DDDD.."; int Arg1 = 3; int Arg2 = 11; int Arg3 = 17; verify_case(3, Arg3, fewestClicks(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "DDD........................."; int Arg1 = 1; int Arg2 = 3; int Arg3 = 11; verify_case(4, Arg3, fewestClicks(Arg0, Arg1, Arg2)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    InboxCleanup ___test;

    ___test.run_test(-1);
	// cout << ___test.fewestClicks("D....DD.D.DD......DD.DDD.", 6, 17) << endl;
}

// END CUT HERE
