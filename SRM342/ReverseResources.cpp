// BEGIN CUT HERE

// END CUT HERE
#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,k,n) for(int i=k;i<(int)(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair
#define MOD 1000000007

#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int n;
string s;
vector<string> v;

int dp[55][55], dp2[35][35][55][55];

ll dfs(int l, int r);
ll dfs2(int l, int r, int id, int pos);

ll dfs(int l, int r) {
	if(dp[l][r] != -1) return dp[l][r];
	dp[l][r] = 0;
	rep(i, n) {
		dp[l][r] += dfs2(l, r, i, 0);
		dp[l][r] %= MOD;
	}
	return dp[l][r];
}

ll dfs2(int l, int r, int id, int pos) {
	if(dp2[l][r][id][pos] != -1) return dp2[l][r][id][pos];
	if(pos >= v[id].size()) return 0;

	if(v[id][pos] == '?') {
		if(pos != v[id].size() - 1) {
			dp2[l][r][id][pos] = 0;
			for(int i = l + 1; i <= r; i++) {
				ll a = dfs(l, i);
				ll b = dfs2(i, r, id, pos + 1);
				dp2[l][r][id][pos] += (a * b) % MOD;
				dp2[l][r][id][pos] %= MOD;
			}
			return dp2[l][r][id][pos];
		} else {
			return dp2[l][r][id][pos] = dfs(l, r);
		}
	} else {
		if(s[l] != v[id][pos]) return 0;
		if(r - l == 1) {
			if(pos == v[id].size()-1) return 1;
			else return 0;
		}
		return dp2[l][r][id][pos] = dfs2(l + 1, r, id, pos + 1);
	}
}

class ReverseResources {
	public:
	int findDecompositions(string str, vector <string> resources) {
		s = str;
		n = resources.size();
		v.clear(); v.resize(n);
		rep(i, n) {
			string t = "";
			rep(j, resources[i].size()) {
				if(j + 1 < resources[i].size() && resources[i][j] == '%' && resources[i][j+1] == 's') {
					j++;
					t += "?";
				} else {
					t += resources[i][j];
				}
			}
			v[i] = t;
		}

		memset(dp, -1, sizeof(dp));
		memset(dp2, -1, sizeof(dp2));
		return dfs(0, s.size());
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "Error in module foo, code 123."; string Arr1[] = {"foo", "123", "Error in module %s.", "%s, code %s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "The fox jumped over the dog."; string Arr1[] = {"The fox %s over the dog.",
 "lazy",
 "brown",
 "jump%s",
 "s",
 "ed",
 "The %s",
 "fox %s",
 "%s over %s",
 "the dog."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "abcde"; string Arr1[] = {"%sc%s", "b", "de", "a%s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abcde"; string Arr1[] = {"%se", "a%s", "%sb%s", "%sc%s", "%sd%s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "aaaaa"; string Arr1[] = {"a","%s%s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(4, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; string Arr1[] = {"a","aa","%s%s","%sa","a%s","aaa","aa%s","a%sa",
"a%s%s","%saa","%sa%s","%s%sa","%s%s%s","aaaa",
"aaa%s","aa%sa","aa%s%s","a%saa","a%sa%s","a%s%sa",
"a%s%s%s","%saaa","%saa%s","%sa%sa","%sa%s%s",
"%s%saa","%s%sa%s","%s%s%sa","%s%s%s%s","aaaaa",
"aaaa%s","aaa%sa","aaa%s%s","aa%saa","aa%sa%s",
"aa%s%sa","aa%s%s%s","a%saaa","a%saa%s","a%sa%sa",
"a%sa%s%s","a%s%saa","a%s%sa%s","a%s%s%sa",
"a%s%s%s%s","%saaaa","%saaa%s","%saa%sa","%saa%s%s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 879704799; verify_case(5, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "aa"; string Arr1[] = {"a", "a", "%s%s", "%s%s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(6, Arg2, findDecompositions(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    ReverseResources ___test;

    ___test.run_test(-1);

}

// END CUT HERE
