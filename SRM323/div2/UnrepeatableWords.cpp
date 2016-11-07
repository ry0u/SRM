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

string ans = "";
int a[55];
int k, n, allowed;

int f(int sz) {
	rep(i, sz) {
		REP(j, i + 1, sz) {
			if((j - i + 1) % k == 0) {
				int len = (j - i + 1) / k;
				bool flag = true;

				REP(u, i, j - len + 1) {
					if(a[u] != a[u + len]) {
						flag = false;
						break;
					}
				}
				if(flag) return true;
			}
		}
	}
	return false;
}

bool flag;
void dfs(int sz) {
	if(flag) return;

	if(sz == n) {
		rep(i, n) {
			ans += char('A' + a[i]);
		}
		flag = true;
		return;
	}

	rep(i, allowed) {
		a[sz] = i;
		if(f(sz + 1)) continue;
		dfs(sz + 1);
	}
}

class UnrepeatableWords {
	public:
	string getWord(int _k, int _n, int _allowed) {
		k = _k;
		n = _n;
		allowed = _allowed;

		ans = "";
		flag = false;
		memset(a, 0, sizeof(a));

		dfs(0);
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 2; string Arg3 = "AABAA"; verify_case(0, Arg3, getWord(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 1; string Arg3 = ""; verify_case(1, Arg3, getWord(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 10; int Arg2 = 2; string Arg3 = "AABAABABAA"; verify_case(2, Arg3, getWord(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 50; int Arg2 = 2; string Arg3 = "AABAABABAABAABBAABAABABAABAABBAABAABABAABABBAABAAB"; verify_case(3, Arg3, getWord(Arg0, Arg1, Arg2)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    UnrepeatableWords ___test;

    ___test.run_test(-1);

}

// END CUT HERE
