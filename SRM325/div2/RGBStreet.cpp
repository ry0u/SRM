// BEGIN CUT HERE

// END CUT HERE
#line 5 "RGBStreet.cpp"

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

int dp[25][3];

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

int f(string s) {
	int ret;
	stringstream ss;
	ss << s;
	ss >> ret;
	return ret;
}

class RGBStreet {
	public:
	int estimateCost(vector <string> houses) {
		int n = houses.size();
		vector<int> R(n), G(n), B(n);
		rep(i, n) {
			vector<string> ret = split(houses[i], ' ');
			R[i] = f(ret[0]);
			G[i] = f(ret[1]);
			B[i] = f(ret[2]);
		}

		rep(i, 25) {
			rep(j, 3) dp[i][j] = INF;
		}

		rep(j, 3) {
			dp[0][j] = 0;
		}

		rep(i, n) {
			dp[i+1][0] = min(dp[i][1] + R[i], dp[i][2] + R[i]);
			dp[i+1][1] = min(dp[i][0] + G[i], dp[i][2] + G[i]);
			dp[i+1][2] = min(dp[i][0] + B[i], dp[i][1] + B[i]);
		}

		int ans = INF;
		rep(i, 3) {
			ans = min(ans, dp[n][i]);
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 100 100", "100 1 100", "100 100 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, estimateCost(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 100 100", "100 100 100", "1 100 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 102; verify_case(1, Arg1, estimateCost(Arg0)); }
	void test_case_2() { string Arr0[] = {"26 40 83", "49 60 57", "13 89 99"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 96; verify_case(2, Arg1, estimateCost(Arg0)); }
	void test_case_3() { string Arr0[] = {"30 19 5", "64 77 64", "15 19 97", "4 71 57", "90 86 84", "93 32 91"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 208; verify_case(3, Arg1, estimateCost(Arg0)); }
	void test_case_4() { string Arr0[] = {"71 39 44", "32 83 55", "51 37 63", "89 29 100", 
 "83 58 11", "65 13 15", "47 25 29", "60 66 19"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 253; verify_case(4, Arg1, estimateCost(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    RGBStreet ___test;

    ___test.run_test(-1);

}

// END CUT HERE
