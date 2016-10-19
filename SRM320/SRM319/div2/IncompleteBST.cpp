// BEGIN CUT HERE

// END CUT HERE
#line 5 "IncompleteBST.cpp"

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

int cnt[1<<21];
bool flag[1<<21];

int vmax = -1;
bool dfs(int id, int val, int minval, int maxval) {
	if(val < minval || val > maxval) {
		return false;
	}

	int l = (id * 2);
	int r = (id * 2 + 1);

	bool f1 = false, f2 = false;

	if(cnt[l] != -1) {
		f1 = dfs(l, cnt[l], minval, val);
	} else {
		f1 = true;
	}

	if(cnt[r] != -1) {
		f2 = dfs(r, cnt[r], val + 1, maxval);
	} else {
		f2 = true;
	}

	return f1 && f2;
}


class IncompleteBST {
	public:
	string missingValues(vector <string> tree) {
		int n = tree.size();
		memset(cnt, -1, sizeof(cnt));
		memset(flag, 0, sizeof(flag));

		int x = -1;
		rep(i, n) {
			string s = tree[i].substr(2);
			stringstream ss(s);
			int id; ss >> id;

			vmax = max(vmax, id);

			if(tree[i][0] == '?') {
				flag[id] = true;
				x = id;
			} else {
				int val = (tree[i][0] - 'A');
				cnt[id] = val;
			}

		}

		string ans = "";
		rep(i, 26) {
			cnt[x] = i;
			if(dfs(1, cnt[1], 0, 25)) {
				ans += char('A'+i);
			}
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"A 1", "? 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; verify_case(0, Arg1, missingValues(Arg0)); }
	void test_case_1() { string Arr0[] = {"B 1", "? 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AB"; verify_case(1, Arg1, missingValues(Arg0)); }
	void test_case_2() { string Arr0[] = {"V 1", "? 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WXYZ"; verify_case(2, Arg1, missingValues(Arg0)); }
	void test_case_3() { string Arr0[] = {"K 1", "K 2", "A 6", "? 12", "Y 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(3, Arg1, missingValues(Arg0)); }
	void test_case_4() { string Arr0[] = {"Z 1", "Y 2", "X 4", "W 8", "V 16", "U 32", "T 64", "S 128", "R 256", "Q 512", 
"P 1024", "O 2048", "N 4096", "M 8192", "L 16384", "K 32768", "J 65536", "? 131072"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABCDEFGHIJ"; verify_case(4, Arg1, missingValues(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    IncompleteBST ___test;

    ___test.run_test(-1);

}

// END CUT HERE
