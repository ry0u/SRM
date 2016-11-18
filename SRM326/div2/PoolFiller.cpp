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

int v[55][55], cnt, n, m;
bool flag, used[55][55];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int i, int j, int val) {
	if(used[i][j]) return;

	cnt++;
	used[i][j] = true;

	rep(k, 4) {
		int y = i + dy[k];
		int x = j + dx[k];

		if(0 <= y && y < n && 0 <= x && x < m) {
			if(v[y][x] == val) {
				dfs(y, x, val);
			} else if(v[y][x] > val) {
				continue;
			} else {
				flag = false;
			}
		} else {
			flag = false;
		}
	}
}

void dfs2(int i, int j, int val) {
	if(v[i][j] == val) {
		v[i][j]++;

		rep(k, 4) {
			int y = i + dy[k];
			int x = j + dx[k];

			dfs2(y, x, val);
		}
	}
}

class PoolFiller {

    public:

    int getCapacity(vector <string> layout) {
		n = layout.size();
		m = layout[0].size();

		memset(v, 0, sizeof(v));

		rep(i, n) {
			rep(j, m) {
				int t = int(layout[i][j] - '0');
				v[i][j] = t;
			}
		}

		int ans = 0;
		rep(i, n) {
			rep(j, m) {
				flag = true;

				while(flag) {
					cnt = 0;
					memset(used, 0, sizeof(used));

					dfs(i, j, v[i][j]);

					if(flag) {
						ans += cnt;
						dfs2(i, j, v[i][j]);
					}
				}
			}
		}

		return ans;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"16661",
"61116",
"16661"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(0, Arg1, getCapacity(Arg0)); }
	void test_case_1() { string Arr0[] = {
"999999",
"955119",
"955119",
"999999"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 48; verify_case(1, Arg1, getCapacity(Arg0)); }
	void test_case_2() { string Arr0[] = {
"111111111",
"115111611",
"131516161",
"115111611",
"111111111"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(2, Arg1, getCapacity(Arg0)); }
	void test_case_3() { string Arr0[] = {
"1111111111111",
"1555555555551",
"1511111111151",
"1511199911151",
"1511192911151",
"1511199911151",
"1511111111151",
"1555555555551",
"1111111111111"
}

; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 151; verify_case(3, Arg1, getCapacity(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    PoolFiller ___test;

    ___test.run_test(-1);

}

// END CUT HERE
