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

int ans = 0;
vector<P> v;

int dy[4] = {0, 0, 2, 2};
int dx[4] = {0, 2, 0, 2};
int ID[4][4] = {0};

void dfs(int id, set<int> st[4][4], vector<string> s) {
	if(id == v.size()) {
		bool ok = true;
		rep(t, 4) {
			set<int> ch;
			REP(i, dy[t], dy[t] + 2) {
				REP(j, dx[t], dx[t] + 2) {
					ch.insert(s[i][j]);
				}
			}

			if(ch.size() == 4) continue;
			ok = false;
		}

		rep(i, 4) {
			rep(j, 4) {
				set<int> ch;
				rep(y, 4) {
					rep(x, 4) {
						if(y == i) ch.insert(s[y][x]);
					}
				}

				if(ch.size() != 4) ok = false;

				ch.clear();
				rep(y, 4) {
					rep(x, 4) {
						if(x == j) ch.insert(s[y][x]);
					}
				}

				if(ch.size() != 4) ok = false;
			}
		}

		if(ok) {
			ans++;
		}
		return;
	}

	int y = v[id].first;
	int x = v[id].second;

	if(st[y][x].size() == 0) return;

	set<int> tmp[4][4];
	rep(i, 4) rep(j, 4) tmp[i][j] = st[i][j];

	vector<string> res = s;

	each(it, st[y][x]) {
		int d = *it;
		vector<P> pre;
		res[y][x] = char('0' + *it);

		rep(i, 4) {
			rep(j, 4) {
				if(i == y || j == x) {
					if(tmp[i][j].find(d) == tmp[i][j].end()) continue;
					tmp[i][j].erase(d);
					pre.push_back(mp(i, j));
				}
			}
		}

		int t = ID[y][x];
		REP(i, dy[t], dy[t] + 2) {
			REP(j, dx[t], dx[t] + 2) {
				if(tmp[i][j].find(d) == tmp[i][j].end()) continue;
				tmp[i][j].erase(d);
				pre.push_back(mp(i, j));
			}
		}

		dfs(id + 1, tmp, res);
		res[y][x] = '-';

		rep(i, pre.size()) {
			tmp[pre[i].first][pre[i].second].insert(*it);
		}
	}
}

class SillySudoku {

    public:

    int countWays(vector <string> board) {
		int n = 4;
		set<int> st[4][4];

		v.clear();
		rep(i, n) {
			rep(j, n) {
				rep(k, n) {
					st[i][j].insert(k+1);
				}
			}
		}

		bool flag = false;

		rep(t, 4) {
			set<int> del;
			REP(i, dy[t], dy[t] + 2) {
				REP(j, dx[t], dx[t] + 2) {
					ID[i][j] = t;
					if(board[i][j] == '-') {
						v.push_back(mp(i, j));
						continue;
					}

					int d = int(board[i][j] - '0');
					del.insert(d);
				}
			}

			
			REP(i, dy[t], dy[t] + 2) {
				REP(j, dx[t], dx[t] + 2) {
					each(it, del) {
						if(st[i][j].find(*it) == st[i][j].end()) continue;
						st[i][j].erase(*it);
					}
				}
			}
		}

		rep(i, 4) {
			rep(j, 4) {
				if(board[i][j] == '-') continue;
				int d = int(board[i][j] - '0');
				rep(y, 4) {
					rep(x, 4) {
						if(y == i || x == j) {
							if(st[y][x].find(d) == st[y][x].end()) continue;
							st[y][x].erase(d);
						}
					}
				}
			}
		}

		if(flag) {
			return 0;
		}

		ans = 0;
		dfs(0, st, board);
		return ans;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"--21", 
 "--34", 
 "2143", 
 "3412"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countWays(Arg0)); }
	void test_case_1() { string Arr0[] = {"--1-", 
 "--1-", 
 "----", 
 "----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, countWays(Arg0)); }
	void test_case_2() { string Arr0[] = {"1---", 
 "-42-", 
 "-3--", 
 "----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, countWays(Arg0)); }
	void test_case_3() { string Arr0[] = {"1---", 
 "--1-", 
 "-1--", 
 "---1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(3, Arg1, countWays(Arg0)); }
	void test_case_4() { string Arr0[] = {"1---", 
 "----", 
 "----", 
 "----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 72; verify_case(4, Arg1, countWays(Arg0)); }

// END CUT HERE
};

// BEGIN CUT HERE

int main() {

    SillySudoku ___test;

    ___test.run_test(-1);

}

// END CUT HERE
