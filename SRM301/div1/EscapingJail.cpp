// BEGIN CUT HERE

// END CUT HERE
#line 5 "EscapingJail.cpp"

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
#define INF 1<<28
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int n;
int cost[55][55];

int f(char c) {
	if('0' <= c && c <= '9') return (c - '0');
	if('a' <= c && c <= 'z') return (c - 'a' + 10);
	if('A' <= c && c <= 'Z') return (c - 'A' + 36);
	return INF;
}

class EscapingJail {
	public:
	int getMaxDistance(vector<string> v) {
		int n = v.size();
		memset(cost, 0, sizeof(cost));

		rep(i, n) {
			rep(j, n) {
				cost[i][j] = f(v[i][j]);
			}
		}

		rep(k, n) {
			rep(i, n) {
				rep(j, n) {
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
				}
			}
		}

		int ans = -1;
		rep(i, n) {
			rep(j, n) {
				if(i == j) continue;
				if(cost[i][j] == INF) continue;
				ans = max(ans, cost[i][j]);
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
	void test_case_0() { string Arr0[] = {"0568",
 "5094",
 "6903",
 "8430"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(0, Arg1, getMaxDistance(Arg0)); }
	void test_case_1() { string Arr0[] = {"0 ",
 " 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, getMaxDistance(Arg0)); }
	void test_case_2() { string Arr0[] = {"0AxHH190",
 "A00f3AAA",
 "x00     ",
 "Hf 0  x ",
 "H3  0   ",
 "1A   0  ",
 "9A x  0Z",
 "0A    Z0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 43; verify_case(2, Arg1, getMaxDistance(Arg0)); }
	void test_case_3() { string Arr0[] = {"00",
 "00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, getMaxDistance(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    EscapingJail ___test;

    ___test.run_test(-1);

}

// END CUT HERE
