// BEGIN CUT HERE

// END CUT HERE
#line 5 "Knights.cpp"

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

class Knights {
	public:
	int makeFriendly(int N, vector <string> pos) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"A2 A4", "B1 B5", "D1 D5 E2 E4 C3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, makeFriendly(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"A1 A2 B1 B2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, makeFriendly(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; string Arr1[] = {"A1 A5 B3 C1 C5 D2 D4 E6 F5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, makeFriendly(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; string Arr1[] = {"A2 A4 A5 A6 B2 B5 B6 B7 B8",
 "C3 C8 D1 D2 D3 D4 D5 D6 D8",
 "E1 E3 E8 F1 F2 F8 G3 G5 H4 H7 H8"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(3, Arg2, makeFriendly(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 9; string Arr1[] = {"A3 A4 A5 A7 A8 B6 B8 C3 C6",
 "C7 C9 D4 D5 D8 D9 E1 E3 E7",
 "F2 G2 G6 G7 H2 H9 I2 I4 I5",
 "I6 I7 I8 I9"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(4, Arg2, makeFriendly(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    Knights ___test;

    ___test.run_test(-1);

}

// END CUT HERE
