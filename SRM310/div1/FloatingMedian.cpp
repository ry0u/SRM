
// BEGIN CUT HERE

// END CUT HERE
#line 5 "FloatingMedian.cpp"

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
#define MOD 65536

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

class FloatingMedian {
	public:
	long long sumOfMedians(int seed, int mul, int add, int N, int K) {
		ll t = seed;
		vector<ll> v;
		rep(i, N) {
			v.push_back(t);
			t = (t * mul + add) % MOD;
		}

		int l = 0, r = K;

		vector<ll> res(r);
		rep(i, r) {
			res[i] = v[i];
		}
		sort(res.begin(), res.end());

		ll x = res[(K + 1) / 2 - 1];
		map<ll, int> down, up;
		rep(i, r) {
			if(i < (K + 1) / 2 - 1) down[res[i]]++;
			if(i > (K + 1) / 2 - 1) up[res[i]]++;
		}

		ll ans = x;
		int cnt = 0;
		while(r < N) {
			bool f1 = (down.count(v[l]) == 0);
			bool f2 = (up.count(v[l]) == 0);

			if(f1 && f2) {
				if(v[r] <= x) {
					down[v[r]]++;
					map<ll, int>::iterator it = down.end(); it--;
					x = it->first;
					down[x]--; if(down[x] == 0) down.erase(x);
				} else {
					up[v[r]]++;
					x = up.begin()->first;
					up[x]--; if(up[x] == 0) up.erase(x);
				}
			} else if(!f1) {
				if(v[r] <= x) {
					down[v[l]]--; if(down[v[l]] == 0) down.erase(v[l]);
					down[v[r]]++;
				} else {
					down[v[l]]--; if(down[v[l]] == 0) down.erase(v[l]);
					down[x]++;
					up[v[r]]++;

					x = up.begin()->first;
					up[x]--; if(up[x] == 0) up.erase(x);
				}
			} else if(!f2) {
				if(v[r] <= x) {
					up[v[l]]--; if(up[v[l]] == 0) up.erase(v[l]);
					up[x]++;
					down[v[r]]++;

					map<ll, int>::iterator it = down.end(); it--;
					x = it->first;
					down[x]--; if(down[x] == 0) down.erase(x);
				} else {
					up[v[l]]--; if(up[v[l]] == 0) up.erase(v[l]);
					up[v[r]]++;
				}
			}

			cnt++;
			ans += x;

			l++; r++;
		}
		
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 10; int Arg4 = 3; long long Arg5 = 60LL; verify_case(0, Arg5, sumOfMedians(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 0; int Arg2 = 13; int Arg3 = 5; int Arg4 = 2; long long Arg5 = 49LL; verify_case(1, Arg5, sumOfMedians(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 4123; int Arg1 = 2341; int Arg2 = 1231; int Arg3 = 7; int Arg4 = 3; long long Arg5 = 102186LL; verify_case(2, Arg5, sumOfMedians(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 5621; int Arg2 = 1; int Arg3 = 125000; int Arg4 = 1700; long long Arg5 = 4040137193LL; verify_case(3, Arg5, sumOfMedians(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 32321; int Arg1 = 46543; int Arg2 = 32552; int Arg3 = 17; int Arg4 = 17; long long Arg5 = 25569LL; verify_case(4, Arg5, sumOfMedians(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    FloatingMedian ___test;

    ___test.run_test(-1);

	cout << ___test.sumOfMedians(32321, 46543, 32552, 250000, 5000) << endl;
}

// END CUT HERE
