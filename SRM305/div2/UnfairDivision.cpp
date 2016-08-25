// BEGIN CUT HERE

// END CUT HERE
#line 5 "UnfairDivision.cpp"

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

class UnfairDivision {
	public:
	int albertsShare(vector <int> v) {
		int n = v.size();

		int ans = 0, res = 0, vmax = 0;
		REP(a, 1, n) {
			res = 0;
			vmax = 0;
			REP(b, 1, n) {
				if(a == b) continue;
				int i = min(a, b), j = max(a, b);

				vector<int> t(3);
				rep(k, i) t[0] += v[k];
				REP(k, i, j) t[1] += v[k];
				REP(k, j, n) t[2] += v[k];

				sort(t.begin(), t.end());

				if(t[1] > res) {
					res = t[1];
					vmax = t[0];
				} else if(t[1] == res) {
					vmax = min(vmax, t[0]);
				}
			}
			ans = max(ans, vmax);
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 50, 90, 10, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; verify_case(0, Arg1, albertsShare(Arg0)); }
	void test_case_1() { int Arr0[] = { 5, 5, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, albertsShare(Arg0)); }
	void test_case_2() { int Arr0[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, albertsShare(Arg0)); }
	void test_case_3() { int Arr0[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, albertsShare(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    UnfairDivision ___test;

    ___test.run_test(-1);
}

// END CUT HERE
