// BEGIN CUT HERE

// END CUT HERE
#line 5 "IntegerPalindrome.cpp"

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

// 1 2 3 4 5 6 7 8 9 11 22

class IntegerPalindrome {
	public:
	long long findByIndex(int K) {
		ll ret = 1;
		int l = 0, r = 9;

		if(l <= K && K < r) {
			return K + 1;
		}

		ret = 9;
		l = r;
		r += ret;

		if(l <= K && K < r) {
			return (K - l + 1) * 10 + (K - l + 1);
		}

		int cnt = 3, keta = 1;
		while(true) {
			if(cnt & 1) {
				keta++;
				ret *= 10;
			}
			l = r;
			r += ret;

			if(l <= K && K < r) break;
			cnt++;
		}

		ll t = 1;
		rep(i, keta-1) t *= 10;
		ll res = K - l + t;

		stringstream ss;
		ss << res;
		string s = ss.str();

		stringstream ss2;
		ss2 << s;
		if(cnt & 1) {
			for(int i = s.size() - 2; i >= 0; i--) ss2 << s[i];
		} else {
			reverse(s.begin(), s.end());
			ss2 << s;
		}

		s = ss2.str();

		ll ans = 0;
		t = 1;

		for(int i = s.size()-1; i >= 0; i--) {
			ans += (int)(s[i] - '0') * t;
			t *= 10;
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; long long Arg1 = 9LL; verify_case(0, Arg1, findByIndex(Arg0)); }
	void test_case_1() { int Arg0 = 9; long long Arg1 = 11LL; verify_case(1, Arg1, findByIndex(Arg0)); }
	void test_case_2() { int Arg0 = 19; long long Arg1 = 111LL; verify_case(2, Arg1, findByIndex(Arg0)); }
	void test_case_3() { int Arg0 = 235; long long Arg1 = 13731LL; verify_case(3, Arg1, findByIndex(Arg0)); }
	void test_case_4() { int Arg0 = 23746; long long Arg1 = 137484731LL; verify_case(4, Arg1, findByIndex(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    IntegerPalindrome ___test;

    ___test.run_test(-1);

	cout << ___test.findByIndex(199999997) << endl;
	cout << 9999999999999999 << endl;
	cout << ___test.findByIndex(107) << endl;
	cout << ___test.findByIndex(197) << endl;
}

// END CUT HERE
