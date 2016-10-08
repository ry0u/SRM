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
typedef pair<P, int> PI;

int sub[55];
vector<int> g[55];

int dfs(int i) {
	if(g[i].size() == 0) return 0;

	vector<int> v;
	rep(j, g[i].size()) {
		v.push_back(dfs(g[i][j]));
	}

	sort(v.begin(), v.end(), greater<int>());

	int ret = 0;
	rep(i, v.size()) {
		ret = max(ret, v[i] + i + 1);
	}
	return ret;
}

class SpreadingNews {

    public:

    int minTime(vector <int> supervisors) {
		int n = supervisors.size();

		rep(i, 55) g[i].clear();
		memset(sub, 0, sizeof(sub));

		int root = -1;
		rep(i, n) {
			if(supervisors[i] == -1) {
				root = i;
			} else {
				g[supervisors[i]].push_back(i);
			}
		}

		return dfs(root);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { int Arr0[] = {-1, 0, 0, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { int Arr0[] = {-1, 0, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { int Arr0[] = {-1, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 7, 8, 12, 13, 14, 16, 16, 16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, minTime(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    SpreadingNews ___test;

    ___test.run_test(-1);
}

// END CUT HERE
