// BEGIN CUT HERE

// END CUT HERE
#line 5 "MazeConstruct.cpp"
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

class MazeConstruct {
	public:
	vector <string> construct(int k) {
		if(k <= 49) {
			vector<string> ans(1);
			rep(i, k + 1) ans[0] += '.';
			return ans;
		}

		if(k <= 98) {
			int n = k - 48, m = 50;
			vector<string> ans(n);
			rep(i, n) {
				rep(j, m) {
					ans[i] += '.';
				}
			}
			return ans;
		}

		int h = 50 - (k % 2 == 1);
		int w = 50;

		int cnt = k - (h - 1) - (w - 1);

		vector<string> ans(h);
		rep(i, h) {
			rep(j, w) {
				ans[i] += '.';
			}
		}

		for(int j = 1; j < w; j += 4) {
			rep(i, h - 1) {
				ans[i][j] = '#';
			}
		}

		for(int j = 3; j < w; j += 4) {
			for(int i = h - 1; i >= 1; i--) {
				ans[i][j] = '#';
				cnt -= 2;

				if(cnt == 0) break;
			}
			if(cnt == 0) break;
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"...." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arg0 = 4; string Arr1[] = {"...", "...", "..." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { int Arg0 = 10; string Arr1[] = {"..#..", "#.#..", "..#..", ".#...", "....." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, construct(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    MazeConstruct ___test;

    ___test.run_test(-1);

	vector<string> ret = ___test.construct(1000);
}

// END CUT HERE
