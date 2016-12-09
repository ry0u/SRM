// BEGIN CUT HERE

// END CUT HERE
#line 5 "PrefixFreeSubsets.cpp"

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

bool check(string s, string t) {
	if(s.size() > t.size()) swap(s, t);
	rep(i, s.size()) {
		if(s[i] == t[i]) continue;
		return false;
	}
	return true;
}

class PrefixFreeSubsets {
	public:
	long long cantPrefFreeSubsets(vector <string> words) {
		int n = words.size();
		vector<string> s = words;
		sort(s.begin(), s.end());

		ll dp[55];
		memset(dp, 0, sizeof(dp));
		dp[n] = 1;

		for(int i = n - 1; i >= 0; i--) {
			int j = i + 1;
			while(j < n && check(s[i], s[j])) j++;
			dp[i] = dp[i+1] + dp[j];
		}

		return dp[0];
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"hello","hell","hi"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 6LL; verify_case(0, Arg1, cantPrefFreeSubsets(Arg0)); }
	void test_case_1() { string Arr0[] = {"a","b","c","d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 16LL; verify_case(1, Arg1, cantPrefFreeSubsets(Arg0)); }
	void test_case_2() { string Arr0[] = {"a","ab","abc","abcd","abcde","abcdef"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(2, Arg1, cantPrefFreeSubsets(Arg0)); }
	void test_case_3() { string Arr0[] = {"a","b","aa","ab","ba","bb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 25LL; verify_case(3, Arg1, cantPrefFreeSubsets(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    PrefixFreeSubsets ___test;

    ___test.run_test(-1);

}

// END CUT HERE
