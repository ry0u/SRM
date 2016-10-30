// BEGIN CUT HERE

// END CUT HERE
#line 5 "BattleshipChecker.cpp"

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

int x[20][20];

bool check(vector<string> s) {
	int n = s.size();
	map<int, int> m;
	memset(x, -1, sizeof(x));

	int id = 0;
	rep(i, n) {
		rep(j, n) {
			if(s[i][j] != 'X') continue;
			if(x[i][j] != -1) continue;

			x[i][j] = id;
			int w = 1, h = 1;
			REP(k, j+1, n) {
				if(s[i][k] == 'X') {
					w++;
					x[i][k] = id;
					continue;
				} else break;
			}

			REP(k, i+1, n) {
				if(s[k][j] == 'X') {
					h++;
					x[k][j] = id;
					continue;
				} else break;
			}

			if(max(w, h) > 4) return false;

			m[max(w, h)]++;
			id++;
		}
	}

	bool flag = m[1] == 4 && m[2] == 3 && m[3] == 2 && m[4] == 1;
	if(!flag) return false;

	int dy[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
	int dx[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

	rep(i, n) {
		rep(j, n) {
			if(x[i][j] == -1) continue;

			rep(k, 8) {
				int ni = i + dy[k];
				int nj = j + dx[k];

				if(0 <= ni && ni < n && 0 <= nj && nj < n) {
					if(x[ni][nj] != -1 && x[ni][nj] != x[i][j]) {
						return false;
					}
				}
			}
		}
	}


	return true;
}

class BattleshipChecker {
	public:
	string checkBoard(vector <string> board) {

		if(!check(board)) {
			return "REJECTED";
		}

		int n = board.size(), cnt = 0;
		rep(i, n) {
			bool flag = true;
			rep(j, n) {
				if(board[i][j] != 'X') continue;
				flag = false;
			}

			if(flag) cnt++;
			flag = true;

			rep(j, n) {
				if(board[j][i] != 'X') continue;
				flag = false;
			}

			if(flag) cnt++;
		}

		stringstream ss;
		ss << "ACCEPTED, ";
		ss << cnt;
		ss << " POINTS";

		return ss.str();
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"......X...",
 ".XXX..X...",
 "......X...",
 "X.X...X...",
 "X.........",
 "...XX.X...",
 "......X...",
 ".XX...X...",
 "..........",
 ".X.X..X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ACCEPTED, 5 POINTS"; verify_case(0, Arg1, checkBoard(Arg0)); }
	void test_case_1() { string Arr0[] = {"X.X.X.X...",
 "......X...",
 ".XX...X...",
 "......X...",
 "......X..X",
 "...X..X...",
 "...X..X...",
 "......X...",
 "..XX..X...",
 "......X..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "REJECTED"; verify_case(1, Arg1, checkBoard(Arg0)); }
	void test_case_2() { string Arr0[] = {".....XX...",
 ".XX.......",
 "..........",
 ".X....XXX.",
 ".X........",
 ".....X....",
 "..X..X....",
 ".....X....",
 "...X......",
 "X.....XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "REJECTED"; verify_case(2, Arg1, checkBoard(Arg0)); }
	void test_case_3() { string Arr0[] = {".....XX..X",
 ".XX......X",
 "..........",
 ".X....XXX.",
 ".X........",
 ".....X..X.",
 "..X..X....",
 ".....X....",
 "...X......",
 "X.....XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "REJECTED"; verify_case(3, Arg1, checkBoard(Arg0)); }
	void test_case_4() { string Arr0[] = {"X.......X.",
 "...XXXX...",
 ".X......X.",
 "....XX....",
 ".........X",
 ".........X",
 ".....XXX..",
 ".........X",
 "..X......X",
 "..X......X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ACCEPTED, 0 POINTS"; verify_case(4, Arg1, checkBoard(Arg0)); }
	void test_case_5() { string Arr0[] = {"X.......X.",
 "...XXXX...",
 ".X......X.",
 "....XX....",
 "...X.....X",
 "...X.....X",
 ".....XXX..",
 ".........X",
 ".........X",
 ".........X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "REJECTED"; verify_case(5, Arg1, checkBoard(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    BattleshipChecker ___test;

    ___test.run_test(-1);
	cout << ___test.checkBoard(
			{"...XXX....",
			 ".X......X.",
			 ".X..X.....",
			 ".X..X...XX",
			 "....X.....",
			 "X...X.....",
			 "X.........",
			 "X.XX..XX..",
			 "X........X",
			 "X...X.X..."}) << endl;

}

// END CUT HERE
