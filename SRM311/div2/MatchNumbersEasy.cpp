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

// i桁の数でマッチの本数が残りjの時の最大値
string dp[55][55];

string f(string s, string t) {
	if(s.size() == t.size()) {
		bool flag = true;
		rep(i, s.size()) {
			if(s[i] > t[i]) break;
			if(s[i] == t[i]) continue;
			flag = false;
		}
		if(flag) return s;
		return t;
	} else {
		if(s.size() > t.size()) return s;
		else return t;
	}
}

class MatchNumbersEasy {

    public:

    string maxNumber(vector <int> matches, int n) {
		int m = matches.size();

		rep(i, 55) rep(j, 55) dp[i][j] = "";

		rep(i, 54) {
			string res = "";
			for(int j = n; j >= 0; j--) {
				rep(k, m) {
					int x = j - matches[k];
					char c = char('0' + k);

					if(x >= 0 && dp[i][j][0] != '0') {
						dp[i+1][x] = f(dp[i+1][x], dp[i][j] + c);
					}
				}
			}
		}

		string ans = "";
		rep(i, 55) {
			rep(j, n + 1) {
				ans = f(ans, dp[i][j]);
			}
		}

		return ans;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,7,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; string Arg2 = "210"; verify_case(0, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5,23,24}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; string Arg2 = "20"; verify_case(1, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,5,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "0"; verify_case(2, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; string Arg2 = "99999999999999999999999999999999999999999999999999"; verify_case(3, Arg2, maxNumber(Arg0, Arg1)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    MatchNumbersEasy ___test;

    ___test.run_test(-1);

}

// END CUT HERE
