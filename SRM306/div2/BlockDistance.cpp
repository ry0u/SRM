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

int dp[1005][1005];

class BlockDistance {

    public:

    int minDist(vector <string> oldText, vector <string> newText) {
		rep(i, 1005) rep(j, 1005) dp[i][j] = INF;

		string s = "", t = "";
		rep(i, oldText.size()) s += oldText[i];
		rep(i, newText.size()) t += newText[i];

		dp[0][0] = 0;

		rep(i, s.size()) {
			rep(j, t.size()) {
				cout << " i : " << i << " j : " << j << " " << s[i] << " " << t[j] << endl;
				if(s[i] == t[j]) {
					dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
				}

				REP(k, j+1, t.size()) {
					dp[i][k] = min(dp[i][k], dp[i][j] + 1);
				}
			}
		}

		if(dp[s.size()][t.size()] == INF) return -1;
		return dp[s.size()][t.size()];
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"hello goodbye"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"hello, how are you? goodbye have a nice day"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, minDist(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"aaaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ababababa"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, minDist(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"aaaaaaaaaaaaaaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"aaaaaaaaaaaaaaaa","t","aaaaaaaaaaaaaaaa"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, minDist(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"no way"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"No way!"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, minDist(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"abce","f","ij","klm","n","op","uvwx","z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ab","cdefg","hijklmnop","q","rs","tuv","wxyz"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(4, Arg2, minDist(Arg0, Arg1)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    BlockDistance ___test;

    ___test.run_test(0);

}

// END CUT HERE
