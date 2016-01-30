// BEGIN CUT HERE

// END CUT HERE
#line 5 "PalindromePath.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;

char co[25][25];
int d[25][25];

class PalindromePath {
	public:
	int shortestLength(int n, vector <int> a, vector <int> b, string c) {
		int m = a.size();
		rep(i, 25) rep(j, 25) co[i][j] = 'X', d[i][j] = INF;

		rep(i, m) {
			co[a[i]][b[i]] = c[i];
			co[b[i]][a[i]] = c[i];
		}

		queue<pair<int,int> > que;
		que.push(mp(0, 1));
		d[0][1] = 0;
		d[1][0] = 0;
		int ans = INF;

		while(que.size()) {
			pair<int,int> p = que.front();
			que.pop();

			int x = p.first, y = p.second;

			rep(i, n+1) {
				rep(j, n+1) {
					if(co[x][i] == 'X' || co[y][j] == 'X') continue;
					if(co[x][i] == co[y][j] && d[i][j] > d[x][y] + 2) {
						d[i][j] = d[x][y] + 2;
						d[j][i] = d[x][y] + 2;

						if(i == j) ans = min(ans, d[i][j]);
						else que.push(mp(i, j));
					}

					if(x == j && y == i) {
						ans = min(ans, d[i][j] + 1);
					}
				}
			}
		}

		if(ans == INF) {
			return -1;
		} else {
			return ans;
		}
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {2,2,0,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1,3,4,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "abxyx"; int Arg4 = 3; verify_case(0, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {2,2,0,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1,3,4,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "abxyz"; int Arg4 = -1; verify_case(1, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {0,0,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,5,6,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "abaaaa"; int Arg4 = 9; verify_case(2, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 6; int Arr1[] = {0,0,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,5,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "abaaa"; int Arg4 = -1; verify_case(3, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 2; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "x"; int Arg4 = 1; verify_case(4, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 20; int Arr1[] = {18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {19}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "z"; int Arg4 = -1; verify_case(5, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PalindromePath ___test;
    ___test.run_test(-1);
}
// END CUT HERE
