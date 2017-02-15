#include <bits/stdc++.h>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

class ImprovingStatistics {

    public:

    int howManyGames(int played, int won) {
		double a = played;
		double b = won;
		double t = floor(b / a * 100);

		if((t + 1) / 100 == b / a) {
			t++;
		}

		ll l = 0, r = 1e9 + 5;


		while(r - l > 1) {
			ll mid = (l + r) / 2;
			ll f = floor( ((b + mid) / (a + mid)) * 100 );
			if(f < t + 1) {
				l = mid;
			} else {
				r = mid;
			}
		}

		if(r == 1e9 + 5) return -1;
		return r;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 8; int Arg2 = 1; verify_case(0, Arg2, howManyGames(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 80; int Arg2 = 6; verify_case(1, Arg2, howManyGames(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 47; int Arg1 = 47; int Arg2 = -1; verify_case(2, Arg2, howManyGames(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 99000; int Arg1 = 0; int Arg2 = 1000; verify_case(3, Arg2, howManyGames(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 470000000; int Arg2 = 19230770; verify_case(4, Arg2, howManyGames(Arg0, Arg1)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    ImprovingStatistics ___test;

    ___test.run_test(-1);
	//
	cout << ___test.howManyGames(999999, 999998) << endl; // -1
	cout << ___test.howManyGames(1750, 1015) << endl; // 43
}

// END CUT HERE
