// BEGIN CUT HERE

// END CUT HERE
#line 5 "ProblemSetsEasy.cpp"
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;

class ProblemSetsEasy {
	public:
	int maxSets(int E, int EM, int M, int MH, int H) {
		int e = 0,m = 0,h = 0;

		e = E + EM;
		m = M;
		h = MH + H;

		while(EM && MH)
		{
			if(m < e && m < h)
			{
				if(e >= h)
				{
					e--;
					m++;
					EM--;
				}
				else
				{
					h--;
					m++;
					MH--;
				}
			}
			else break;
		}
		
		int res = INF;
		res = min(res,e);
		res = min(res,m);
		res = min(res,h);

		return res;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 2; int Arg4 = 2; int Arg5 = 3; verify_case(0, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 100; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; verify_case(1, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 657; int Arg1 = 657; int Arg2 = 657; int Arg3 = 657; int Arg4 = 657; int Arg5 = 1095; verify_case(2, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 3; int Arg3 = 4; int Arg4 = 5; int Arg5 = 3; verify_case(3, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 100000; int Arg2 = 100000; int Arg3 = 100000; int Arg4 = 100000; int Arg5 = 166666; verify_case(4, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main() {
  ProblemSetsEasy ___test;
  ___test.run_test(-1);
}
// END CUT HERE

