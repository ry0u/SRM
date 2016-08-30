// BEGIN CUT HERE

// END CUT HERE
#line 5 "CornersGame.cpp"

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
typedef pair<int, vector<string> > IS;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

bool can(int y, int x) {
	if(0 <= y && y < 6 && 0 <= x && x < 6) return true;
	return false;
}


class CornersGame {
	public:
	int countMoves(vector <string> board) {
		int n = 6;
		vector<string> s = board;
		s[n-2][n-2] = 'X';
		s[n-2][n-1] = 'X';
		s[n-1][n-2] = 'X';
		s[n-1][n-1] = 'X';

		set<vector<string> > st;
		priority_queue<IS, vector<IS>, greater<IS> > que;
		que.push(mp(0, s));

		while(que.size()) {
			IS is = que.top(); que.pop();
			int cnt = is.first;
			s = is.second;

			if(s[0][0] == 'X' && s[0][1] == 'X' && s[1][0] == 'X' && s[1][1] == 'X') {
				return cnt;
			}

			rep(i, n) {
				rep(j, 6) {
					if(s[i][j] != 'X') continue;

					rep(k, 4) {
						int y = i + dy[k];
						int x = j + dx[k];

						if(can(y, x) && s[y][x] == '.') {
							vector<string> t = s;
							swap(t[i][j], t[y][x]);
							if(st.find(t) == st.end()) {
								st.insert(t);
								que.push(mp(cnt + 1, t));
							}
						}

						int ny = y + dy[k];
						int nx = x + dx[k];

						if(can(y, x) && (s[y][x] == 's' || s[y][x] == 'X') && can(ny, nx) && s[ny][nx] == '.') {
							vector<string> t = s;
							swap(t[i][j], t[ny][nx]);
							if(st.find(t) == st.end()) {
								st.insert(t);
								que.push(mp(cnt + 1, t));
							}
						}
					}
				}
			}
		}

		return -1;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"......", 
 "......",
 "......",
 "......",
 "......",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(0, Arg1, countMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {".....s",
 "..s.r.",
 "r.....",
 ".srs..",
 "..r...",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(1, Arg1, countMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"......",
 "......",
 "....ss",
 "....ss",
 "...r..",
 "...r.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, countMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {"...s.r",
 "..r.s.",
 "rr.s..",
 "..s.rr",
 "s.rr..",
 ".s.s.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 54; verify_case(3, Arg1, countMoves(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    CornersGame ___test;

    ___test.run_test(-1);

}

// END CUT HERE
