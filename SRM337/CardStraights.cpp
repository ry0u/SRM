// BEGIN CUT HERE

// END CUT HERE
#line 5 "CardStraights.cpp"
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

class CardStraights {
	public:
	int longestStraight(vector <int> cards) {
		int cnt = 0;
		set<int> s;
		rep(i, cards.size()) {
			if(cards[i] == 0) cnt++;
			else s.insert(cards[i]);
		}

		vector<int> v(s.begin(), s.end());
		int n = v.size();
		sort(v.begin(), v.end());

		if(n == 0) return cards.size();

		int ans = 0;
		rep(i, n) {
			REP(j, i, n) {
				bool flag = true;
				int x = 0, pre = v[i];
				REP(k, i+1, j+1) {
					if(pre + 1 == v[k]) {
						pre++;
					} else if(x < cnt) {
						x++;
						pre++;
						k--;
					} else {
						flag = false;
						break;
					}
				}

				if(flag) {
					ans = max(ans, j - i + 1 + cnt);
				}

			}
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,6,5,10,3,0,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, longestStraight(Arg0)); }
	void test_case_1() { int Arr0[] = {100,100,100,101,100,99,97,103}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, longestStraight(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,0,1,2,6,8,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, longestStraight(Arg0)); }
	void test_case_3() { int Arr0[] = {1,9,5,7,3,4,0,0,0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, longestStraight(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    CardStraights ___test;

    ___test.run_test(-1);

}

// END CUT HERE
