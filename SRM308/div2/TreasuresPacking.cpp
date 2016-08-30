// BEGIN CUT HERE

// END CUT HERE
#line 5 "TreasuresPacking.cpp"

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

vector<string> split(const string &str, char delim) {
	vector<string> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos) {
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}

double dp[55][10005];

class TreasuresPacking {
	public:
	double maximizeCost(vector <string> treasures, int W) {
		vector<int> w, c;
		vector<double> v;

		rep(i, treasures.size()) {
			int a, b;
			vector<string> ret = split(treasures[i], ' ');

			{
				stringstream ss(ret[0]);
				ss >> a;
			}
			{
				stringstream ss(ret[1]);
				ss >> b;
			}

			if(ret[2] == "Y") {
				REP(i, 1, a + 1) {
					v.push_back(1.0 / a * b);
				}
			} else {
				w.push_back(a);
				c.push_back(b);
			}
		}

		sort(v.begin(), v.end(), greater<double>());
		v.insert(v.begin(), 0);
		REP(i, 1, v.size()) {
			v[i] += v[i-1];
		}

		int n = w.size();
		memset(dp, 0, sizeof(dp));

		rep(i, n) {
			rep(j, W + 1) {
				if(j - w[i] < 0) {
					dp[i+1][j] = dp[i][j];
				} else {
					dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + c[i]);
				}
			}
		}

		double ans = 0;
		rep(j, W + 1) {
			int m = W - j;
			if(m < v.size()) {
				ans = max(ans, dp[n][j] + v[m]);
			}
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"100 100 N", "100 100 N", "130 10 Y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 150; double Arg2 = 103.84615384615384; verify_case(0, Arg2, maximizeCost(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"100 100 N", "100 100 N", "100 1000 Y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 150; double Arg2 = 1000.0; verify_case(1, Arg2, maximizeCost(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"207 1459 Y", "150 6867 N", "694 3494 Y", "417 7479 N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 650; double Arg2 = 14931.00966183575; verify_case(2, Arg2, maximizeCost(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"350 2765 Y", "258 560 Y", "120 9325 N", "879 302 Y",
 "611 2674 Y", "774 2273 Y", "318 1572 Y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3301; double Arg2 = 19467.907849829353; verify_case(3, Arg2, maximizeCost(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    TreasuresPacking ___test;

    ___test.run_test(-1);

	cout << ___test.maximizeCost({"501 10000 N", "500 5001 N", "500 5001 N", "501 10000 N", "500 5001 N", "500 5001 N", "501 10000 N", "500 5001 N", "500 5001 N", "501 10000 N", "500 5001 N", "500 5001 N", "501 10000 N", "500 5001 N", "500 5001 N", "501 10000 N", "500 5001 N", "500 5001 N", "501 10000 N", "500 5001 N", "500 5001 N", "501 10000 N", "500 5001 N", "500 5001 N", "501 10000 N", "500 5001 N", "500 5001 N", "501 10000 N", "500 5001 N", "500 5001 N", "501 10000 N", "500 5001 N", "500 5001 N", "501 10000 N", "500 5001 N", "500 5001 N"}, 9506) << endl; // 150006.0
}

// END CUT HERE
