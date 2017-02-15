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

class BinaryIncrementation {

    public:

    string plusOne(string x) {
		ll a = 0, t = 1;
		for(int i = x.size()-1; i >= 0; i--) {
			if(x[i] == '1') a += t;
			t *= 2;
		}

		a++;

		string ans = "";
		while(a) {
			ans += char(a % 2 + '0');
			a /= 2;
		}

		reverse(ans.begin(), ans.end());
		return ans;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "10011"; string Arg1 = "10100"; verify_case(0, Arg1, plusOne(Arg0)); }
	void test_case_1() { string Arg0 = "10000"; string Arg1 = "10001"; verify_case(1, Arg1, plusOne(Arg0)); }
	void test_case_2() { string Arg0 = "1111"; string Arg1 = "10000"; verify_case(2, Arg1, plusOne(Arg0)); }
	void test_case_3() { string Arg0 = "1"; string Arg1 = "10"; verify_case(3, Arg1, plusOne(Arg0)); }
	void test_case_4() { string Arg0 = "101010101010101010101010101010"; string Arg1 = "101010101010101010101010101011"; verify_case(4, Arg1, plusOne(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    BinaryIncrementation ___test;

    ___test.run_test(-1);

}

// END CUT HERE
