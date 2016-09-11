// BEGIN CUT HERE

// END CUT HERE
#line 5 "MatrixTransforming.cpp"

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

class MatrixTransforming {
	public:
	int minPushes(vector <string> a, vector <string> b) {
		int cnt = 0;
		int n = a.size(), m = a[0].size();

		bool flag = true;
		rep(i, n) {
			rep(j, m) {
				if(a[i][j] != b[i][j]) {
					if(i + 2 < n && j + 2 < m) {
						rep(y, 3) {
							rep(x, 3) {
								if(a[i+y][j+x] == '0') {
									a[i+y][j+x] = '1';
								} else {
									a[i+y][j+x] = '0';
								}
							}
						}
						cnt++;
					}

					if(a[i][j] == b[i][j]) continue;
					flag = false;
				}
			}
		}

		if(flag) return cnt;
		return -1;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"111","111","111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"000","000","000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, minPushes(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, minPushes(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"001","100","100","000","011","010","100","100","010",
"010","010","110","101","101","000","110","000","110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"001","100","011","000","100","010","011","100","101",
"101","010","001","010","010","111","110","111","001"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(2, Arg2, minPushes(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {
"0000",
"0010",
"0000"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {
"1001",
"1011",
"1001"
}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, minPushes(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    MatrixTransforming ___test;

    ___test.run_test(-1);

}

// END CUT HERE
