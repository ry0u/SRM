// BEGIN CUT HERE

// END CUT HERE
#line 5 "Squares.cpp"

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

class Squares {
	public:
	int countSquares(vector <string> field) {
		int h = field.size(), w = field[0].size();

		int ans = 0;
		rep(i, h) {
			rep(j, w) {
				char c = field[i][j];

				rep(y, h) {
					rep(x, w) {
						if(i == y && j == x) continue;
						if(c != field[y][x]) continue;

						int l1 = y - i;
						int l2 = x - j;

						if(0 <= i + l2 && i + l2 < h && 0 <= j - l1 && j - l1 < w) {
							if(0 <= i + l1 + l2 && i + l1 + l2 < h && 0 <= j + l2 - l1 && j + l2 - l1 < w) {
								if(c == field[i+l2][j-l1] && c == field[i+l1+l2][j+l2-l1]) {
									ans++;
								}
							}
						}
					}
				}
			}
		}

		return ans / 4;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABA", "BAB", "ABA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, countSquares(Arg0)); }
	void test_case_1() { string Arr0[] = {"AA", "AA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, countSquares(Arg0)); }
	void test_case_2() { string Arr0[] = {"ABC", "DEF", "GHI"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, countSquares(Arg0)); }
	void test_case_3() { string Arr0[] = {"AABCA", "AAAAA", "BAAAB", "AAAEA", "ADBFA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(3, Arg1, countSquares(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    Squares ___test;

    ___test.run_test(-1);

	cout << ___test.countSquares({"AAAAA", "AAAAA", "AAAAA", "AAAAA", "AAAAA"}) << endl;
}

// END CUT HERE
