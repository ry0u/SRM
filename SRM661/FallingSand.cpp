// BEGIN CUT HERE

// END CUT HERE
#line 5 "FallingSand.cpp"
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

class FallingSand {
	public:
	vector <string> simulate(vector <string> board) {
	    int h = board.size();
        int w = board[0].size();

        for(int i=h-1;i>=0;i--) {
            rep(j,w) {
                if(board[i][j] == '.') {
                    int y = i;
                    while(0 <= y-1 && board[y-1][j] == '.') {
                        y--;
                    }


                    if(0 <= y-1 && board[y-1][j] == 'o') {
                        swap(board[i][j],board[y-1][j]);
                    }
                }
            }


            // cout << "---------" << endl;
            // rep(j,h) {
            //     rep(k,w) {
            //         cout << board[j][k];
            //     }
            //     cout << endl;
            // }
        }
        
        return board;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ooooo",
 "..x..",
 "....x",
 ".....",
 "....o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..o..", "..x.o", "....x", ".....", "oo.oo" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, simulate(Arg0)); }
	void test_case_1() { string Arr0[] = {"..o..", 
 "..x.o", 
 "....x", 
 ".....", 
 "oo.oo" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..o..", "..x.o", "....x", ".....", "oo.oo" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, simulate(Arg0)); }
	void test_case_2() { string Arr0[] = {"ooooxooo.ooxo.oxoxoooox.....x.oo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ooooxooo.ooxo.oxoxoooox.....x.oo" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, simulate(Arg0)); }
	void test_case_3() { string Arr0[] = {"o",
 ".",
 "o",
 ".",
 "o",
 ".",
 "."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".", ".", ".", ".", "o", "o", "o" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, simulate(Arg0)); }
	void test_case_4() { string Arr0[] = {"oxxxxooo",
 "xooooxxx",
 "..xx.ooo",
 "oooox.o.",
 "..x....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"oxxxxooo", "x.oo.xxx", "..xxo...", ".oo.x.o.", "ooxo.ooo" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, simulate(Arg0)); }
	void test_case_5() { string Arr0[] = {"..o..o..o..o..o..o..o..o..o..o..o",
 "o..o..o..o..o..o..o..o..o..o..o..",
 ".o..o..o..o..o..o..o..o..o..o..o.",
 "...xxx...xxx...xxxxxxxxx...xxx...",
 "...xxx...xxx...xxxxxxxxx...xxx...",
 "...xxx...xxx......xxx......xxx...",
 "...xxxxxxxxx......xxx......xxx...",
 "...xxxxxxxxx......xxx......xxx...",
 "...xxxxxxxxx......xxx......xxx...",
 "...xxx...xxx......xxx............",
 "...xxx...xxx...xxxxxxxxx...xxx...",
 "...xxx...xxx...xxxxxxxxx...xxx...",
 "..o..o..o..o..o..o..o..o..o..o..o",
 "o..o..o..o..o..o..o..o..o..o..o..",
 ".o..o..o..o..o..o..o..o..o..o..o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".................................", ".................................", "...ooo...ooo...ooooooooo...ooo...", "...xxx...xxx...xxxxxxxxx...xxx...", "...xxx...xxx...xxxxxxxxx...xxx...", "...xxxoooxxx......xxx......xxx...", "...xxxxxxxxx......xxx......xxx...", "...xxxxxxxxx......xxx......xxx...", "...xxxxxxxxx......xxx......xxx...", "...xxx...xxx......xxx............", "...xxx...xxx...xxxxxxxxx...xxx...", "...xxx...xxx...xxxxxxxxx...xxx...", ".................................", "ooo.........ooo.........ooo...ooo", "ooooooooooooooooooooooooooooooooo" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, simulate(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main() {
  FallingSand ___test;
  ___test.run_test(-1);
}
// END CUT HERE
