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

class EsperantoNumbers {

    public:

    string nameThisNumber(int x) {
		string s[10] = {"unu", "du", "tri", "kvar", "kvin", "ses", "sep", "ok", "nau", "dek"};

		if(1 <= x && x <= 10) {
			return s[x-1];
		} else {
			int y = x / 10;
			int z = x % 10;

			if(z == 0) {
				return s[y-1] + s[9];
			}

			if(y == 1) {
				return s[9] + " " + s[z-1];
			} else {
				return s[y-1] + s[9] + " " + s[z-1];
			}
		}
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "unu"; verify_case(0, Arg1, nameThisNumber(Arg0)); }
	void test_case_1() { int Arg0 = 90; string Arg1 = "naudek"; verify_case(1, Arg1, nameThisNumber(Arg0)); }
	void test_case_2() { int Arg0 = 11; string Arg1 = "dek unu"; verify_case(2, Arg1, nameThisNumber(Arg0)); }
	void test_case_3() { int Arg0 = 57; string Arg1 = "kvindek sep"; verify_case(3, Arg1, nameThisNumber(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    EsperantoNumbers ___test;

    ___test.run_test(-1);

}

// END CUT HERE
