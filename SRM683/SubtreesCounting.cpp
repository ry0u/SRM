// BEGIN CUT HERE

// END CUT HERE
#line 5 "SubtreesCounting.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007

using namespace std;
typedef long long ll;

struct edge {
	int from,to;
	int cost;

	edge(int t,int c) : to(t),cost(c) {}
	edge(int f,int t,int c) : from(f),to(t),cost(c) {}

	bool operator<(const edge &e) const {
		return cost < e.cost;
	}
};

vector<edge> G[100005];
bool used[100005];
ll cnt[100005];
ll dp[100005], num[100005];

void dfs(int cur) {

	used[cur] = true;
	dp[cur] = 1;
	num[cur] = 1;

	rep(i, G[cur].size()) {
		int to = G[cur][i].to;
		if(!used[to]) {
			dfs(to);
			dp[cur] = (dp[cur]*(num[to] + 1))%MOD + (dp[to]*num[cur])%MOD;
			dp[cur] %= MOD;

			num[cur] = num[cur] * (num[to] + 1);
			num[cur] %= MOD;
		}
	}

	cnt[cur] = dp[cur];
}

class SubtreesCounting {
	public:
	int sumOfSizes(int n, int a0, int b, int c, int m) {
		vector<ll> v(n);
		v[0] = a0;
		ll ans = 0;

		REP(i, 1, n-1) {
			// cout << "i:" << i << " " << b * v[i-1] + c << " " << (b * v[i-1] + c) % m << endl;
			v[i] = (b % m) * (v[i-1] % m) + c;
			v[i] %= m;
		}

		rep(i, 100005) {
			G[i].clear();
		}

		REP(i, 1, n) {
			int t = v[i-1] % i;
			G[i].push_back(edge(t, 1));
			G[t].push_back(edge(i, 1));
		}

		memset(used, 0, sizeof(used));
		memset(cnt, 0, sizeof(cnt));
		memset(dp, 0, sizeof(dp));
		memset(num, 0, sizeof(num));

		int root = 0;
		dfs(root);

		rep(i, n) {
			ans += cnt[i];
			ans %= MOD;
		}
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arg5 = 10; verify_case(0, Arg5, sumOfSizes(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 2; int Arg3 = 3; int Arg4 = 100; int Arg5 = 52; verify_case(1, Arg5, sumOfSizes(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; verify_case(2, Arg5, sumOfSizes(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 5; int Arg2 = 6; int Arg3 = 7; int Arg4 = 8; int Arg5 = 4; verify_case(3, Arg5, sumOfSizes(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 123; int Arg2 = 46645; int Arg3 = 4564579; int Arg4 = 1000000000; int Arg5 = 769840633; verify_case(4, Arg5, sumOfSizes(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    SubtreesCounting ___test;
    ___test.run_test(-1);
}
// END CUT HERE
