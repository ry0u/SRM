// BEGIN CUT HERE

// END CUT HERE
#line 5 "TagalogDictionary.cpp"
#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,k,n) for(int i=k;i<(int)(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

bool comp(vector<int> a, vector<int> b) {
	rep(i, min(a.size(), b.size())) {
		if(a[i] == b[i]) continue;

		if(a[i] < b[i]) return true;
		else return false;
	}

	if(a.size() < b.size()) return true;
	else return false;
}

class TagalogDictionary {
	public:
	vector <string> sortWords(vector <string> words) {
		map<char, int> m;
		m['a'] = 1; m['b'] = 2; m['k'] = 3; m['d'] = 4; m['e'] = 5;
		m['g'] = 6; m['h'] = 7; m['i'] = 8; m['l'] = 9; m['m'] = 10;
		m['n'] = 11; /*m['ng'] = 12;*/ m['o'] = 13; m['p'] = 14; m['r'] = 15;
		m['s'] = 16; m['t'] = 17; m['u'] = 18; m['w'] = 19; m['y'] = 20;

		map<int, string> s;
		s[1] = "a"; s[2] = "b"; s[3] = "k"; s[4] = "d"; s[5] = "e";
		s[6] = "g"; s[7] = "h"; s[8] = "i"; s[9] = "l"; s[10] = "m";
		s[11] = "n"; s[12] = "ng"; s[13] = "o"; s[14] = "p"; s[15] = "r";
		s[16] = "s"; s[17] = "t"; s[18] = "u"; s[19] = "w"; s[20] = "y";

		int n = words.size();
		vector<vector<int> > v(n);

		rep(i, n) {
			vector<int> res;
			rep(j, words[i].size()) {
				if(words[i][j] == 'n' && j + 1 < words[i].size() && words[i][j+1] == 'g') {
					res.push_back(12);
					j++;
				} else {
					res.push_back(m[words[i][j]]);
				}
			}
			v[i] = res;
		}

		sort(v.begin(), v.end(), comp);

		vector<string> ans(n);
		rep(i, n) {
			string x = "";
			rep(j, v[i].size()) x += s[v[i][j]];
			ans[i] = x;
		}
		return ans;

	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"abakada","alpabet","tagalog","ako"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"abakada", "ako", "alpabet", "tagalog" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sortWords(Arg0)); }
	void test_case_1() { string Arr0[] = {"ang","ano","anim","alak","alam","alab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"alab", "alak", "alam", "anim", "ano", "ang" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sortWords(Arg0)); }
	void test_case_2() { string Arr0[] = {"siya","niya","kaniya","ikaw","ito","iyon"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"kaniya", "ikaw", "ito", "iyon", "niya", "siya" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sortWords(Arg0)); }
	void test_case_3() { string Arr0[] = {"kaba","baka","naba","ngipin","nipin"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"baka", "kaba", "naba", "nipin", "ngipin" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sortWords(Arg0)); }
	void test_case_4() { string Arr0[] = {"knilngiggnngginggn","ingkigningg","kingkong","dingdong","dindong","dingdont","ingkblot"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"kingkong", "knilngiggnngginggn", "dindong", "dingdont", "dingdong", "ingkblot", "ingkigningg" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, sortWords(Arg0)); }
	void test_case_5() { string Arr0[] = {"silangang", "baka", "bada", "silang"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"baka", "bada", "silang", "silangang" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, sortWords(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    TagalogDictionary ___test;

    ___test.run_test(-1);

}

// END CUT HERE
