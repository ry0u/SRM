// BEGIN CUT HERE

// END CUT HERE
#line 5 "EightRooks.cpp"
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdio>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

class EightRooks {
	public:
	string isCorrect(vector <string> board) {
		bool flag = true;
		int cnt = 0;

		int n = board[0].size();
		vector<pair<int,int> > v;
		rep(i,n)
		{
			rep(j,n) 
			{
				if(board[i][j] == 'R') 
				{
					cnt++;
					v.push_back(make_pair(i,j));
				}
			}
		}

		rep(k,v.size())
		{
			int y = v[k].first;
			int x = v[k].second;
			int res = 0;

			rep(i,n)
			{
				rep(j,n)
				{
					if((i == y || j == x) && board[i][j] == 'R')
					{
						res++;
					}
				}
			}

			if(res > 1) flag = false;
		}

		if(flag && cnt == 8) return "Correct";
		else return "Incorrect";

	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"R.......",
 ".R......",
 "..R.....",
 "...R....",
 "....R...",
 ".....R..",
 "......R.",
 ".......R"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Correct"; verify_case(0, Arg1, isCorrect(Arg0)); }
	void test_case_1() { string Arr0[] = {"........",
 "....R...",
 "........",
 ".R......",
 "........",
 "........",
 "..R.....",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Incorrect"; verify_case(1, Arg1, isCorrect(Arg0)); }
	void test_case_2() { string Arr0[] = {"......R.",
 "....R...",
 "...R....",
 ".R......",
 "R.......",
 ".....R..",
 "..R.....",
 ".......R"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Correct"; verify_case(2, Arg1, isCorrect(Arg0)); }
	void test_case_3() { string Arr0[] = {"......R.",
 "....R...",
 "...R....",
 ".R......",
 "R.......",
 ".......R",
 "..R.....",
 ".......R"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Incorrect"; verify_case(3, Arg1, isCorrect(Arg0)); }
	void test_case_4() { string Arr0[] = {"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Incorrect"; verify_case(4, Arg1, isCorrect(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main() {
  EightRooks ___test;
  ___test.run_test(-1);
}
// END CUT HERE
