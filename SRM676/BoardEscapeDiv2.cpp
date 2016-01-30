// BEGIN CUT HERE

// END CUT HERE
#line 5 "BoardEscapeDiv2.cpp"
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

using namespace std;
typedef long long ll;

int w,h,x,y;
int sx,sy;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool can(int y,int x) {
	if(0 <= y && y < h && 0 <= x && x < w) return true;
	return false;
}

class BoardEscapeDiv2 {
	public:
	string findWinner(vector <string> s, int k) {
		h = s.size();
		w = s[0].size();

		rep(i, h) {
			rep(j, w) {
				if(s[i][j] == 'T') {
					sy = i;
					sx = j;
				}
			}
		}

		int cnt = 0;
		bool first = false;
		rep(i, 4) {
			int ny = sy + dy[i];
			int nx = sx + dx[i];
			if(can(ny, nx) && s[ny][nx] != '#') {
				if(s[ny][nx] == 'E') first = true;
				cnt++;
			}
		}

		if(cnt == 0) return "Bob";
		if(k == 1) return "Alice";
		if(first) return "Alice";

		bool flag = false;
		rep(i, 4) {
			int ny = sy + dy[i];
			int nx = sx + dx[i];

			if(can(ny, nx) && s[ny][nx] != '#') {
				bool ch = false;
				rep(j, 4) {
					int gy = ny + dy[j];
					int gx = nx + dx[j];

					if(can(gy, gx) && s[gy][gx] == 'E') {
						ch = true;
					}
				}

				if(ch) continue;
				flag = true;
			}
		}

		if(flag) {
			if(k % 2 == 1) return "Alice";
			else return "Bob";
		} else {
			return "Bob";
		}
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"T.#",
 "#.E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "Alice"; verify_case(0, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"E#E",
 "#T#",
 "E#E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 99; string Arg2 = "Bob"; verify_case(1, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"#E...",
 "#...E",
 "E.T#.",
 "..#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; string Arg2 = "Alice"; verify_case(2, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"TE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; string Arg2 = "Alice"; verify_case(3, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".T."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "Alice"; verify_case(4, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"..........................",
 "......EEE..EEE..E...E.....",
 ".....E.....E..E.EE.EE.....",
 "......EEE..EEE..E.E.E.....",
 ".........E.E.E..E...E.....",
 "......EEE..E..E.E...E.....",
 "..........................",
 "...E#E#E#E#E#E#E#E#E#E#...",
 "..........................",
 "......EEE..EEE...EEE......",
 ".....E........E.E.........",
 "......EEE.....E..EEE......",
 ".....E...E...E..E...E.....",
 "......EEE....E...EEE......",
 "..........................",
 "...#E#E#E#E#E#E#E#E#E#E...",
 "..........................",
 "....EE...E...E..E.EEE.E...",
 "...E.....E...E..E.E...E...",
 "...E.EE..E...EEEE.EE..E...",
 "...E..E..E...E..E.E.......",
 "....EE...EEE.E..E.E...E...",
 "T........................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; string Arg2 = "Bob"; verify_case(5, Arg2, findWinner(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    BoardEscapeDiv2 ___test;
    ___test.run_test(-1);

	vector<string> v = {"EE#..EE###.E.#.E#####EE##.##", 
						"#E.#EE##EE##E.#EEE#.E.##E..#", 
						"EE#.EE##E##E#E....E##E.EEEE#", 
						"#E..E.#E#EE########.E.#E#E.#", 
						"#.E##E#E#.EEE##EEE#E.##E#E..", 
						"E#####.E.#.EEE#E##.E###EE##E", 
						"#EE##E#E#.#EE..#.E..T##E..E#",
						"E##E..E#..EE##EEE.#####.##E#"};
	cout << ___test.findWinner(v, 22) << endl;
}
// END CUT HERE
