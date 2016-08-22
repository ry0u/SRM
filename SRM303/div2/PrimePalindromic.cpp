// BEGIN CUT HERE

// END CUT HERE
#line 5 "PrimePalindromic.cpp"

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

vector<ll> prime_factor(ll n) {
	vector<ll> res;
	if(n == 1) return res;

	for(ll i = 2; i*i <= n; i++) {
		while(n%i == 0) {
			res.push_back(i);
			n /= i;
		}
	}

	if(n != 1) res.push_back(n);
	return res;
}

string f(ll x) {
	string ret = "";
	while(x) {
		ret = char('0' + x % 10) + ret;
		x /= 10;
	}
	return ret;
}

class PrimePalindromic {
	public:
	int count(int A, int B) {
		int ans = 0;
		REP(i, A, B + 1) {
			vector<ll> ret = prime_factor(i);
			sort(ret.begin(), ret.end());

			do {
				string s = "";
				rep(j, ret.size()) s += f(ret[j]);

				bool flag = true;
				rep(j, s.size() / 2) {
					if(s[j] == s[s.size()-1-j]) continue;
					flag = false;
				}

				if(flag) {
					ans++;
					break;
				}
			} while (next_permutation(ret.begin(), ret.end()));
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2260; int Arg1 = 2262; int Arg2 = 1; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 9; int Arg2 = 7; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 100; int Arg2 = 36; verify_case(2, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    PrimePalindromic ___test;

    ___test.run_test(-1);

}

// END CUT HERE
