// BEGIN CUT HERE

// END CUT HERE
#line 5 "TextStatistics.cpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

class TextStatistics {
	public:
	double averageLength(string text) {
		int len = 0;
		double sum = 0, cnt = 0;
		rep(i, text.size()) {
			if('a' <= text[i] && text[i] <= 'z') {
				sum++;
				len++;
				continue;
			}
			if('A' <= text[i] && text[i] <= 'Z') {
				sum++;
				len++;
				continue;
			}

			if(len != 0) {
				cnt++;
			}

			len = 0;
		}

		if(len != 0) cnt++;
		if(sum == 0) return 0;
		return sum / cnt;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "This is div2 easy problem."; double Arg1 = 4.0; verify_case(0, Arg1, averageLength(Arg0)); }
	void test_case_1() { string Arg0 = "Hello, world!"; double Arg1 = 5.0; verify_case(1, Arg1, averageLength(Arg0)); }
	void test_case_2() { string Arg0 = "Simple"; double Arg1 = 6.0; verify_case(2, Arg1, averageLength(Arg0)); }
	void test_case_3() { string Arg0 = ""; double Arg1 = 0.0; verify_case(3, Arg1, averageLength(Arg0)); }
	void test_case_4() { string Arg0 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"; double Arg1 = 50.0; verify_case(4, Arg1, averageLength(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    TextStatistics ___test;

    ___test.run_test(-1);

}

// END CUT HERE
