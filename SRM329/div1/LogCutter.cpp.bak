// BEGIN CUT HERE

// END CUT HERE
#line 5 "LogCutter.cpp"

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
#define reach(it,v) for(__typeof((v).rbegin()) it=(v).rbegin();it!=(v).rend();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

set<int> st;
bool ok(int x, int L, int C) {
	int sum = 0, now = L, cnt = 0;
	reach(it, st) {
		if(now - *it > x) return false;
		
		if(sum + (now - *it) <= x) {
			sum += (now - *it);
		} else {
			sum = (now - *it);
			cnt++;
		}

		if(cnt > C) return false;
		now = *it;
	}

	return true;
}

class LogCutter {
	public:
	string bestCut(int L, int A, int K, int C) {
		st.clear();

		rep(i, K) {
			int x = (A * ll(i + 1)) % (L - 1) + 1;
			st.insert(x);
		}
		st.insert(0);

		ll l = 0, r = L;
		while(r - l > 1) {
			ll mid = (l + r) / 2;
			if(ok(mid, L, C)) {
				r = mid;
			} else {
				l = mid;
			}
		}

		int now = L, cut = L, sum = 0, cnt = 0;
		reach(it, st) {
			if(sum + (now - *it) <= l + 1) {
				sum += (now - *it);
			} else {
				cut = now;
				cnt++;
				sum = (now - *it);
			}
			now = *it;
		}
		
		stringstream ss;
		ss << l + 1 << " ";

		if(cnt < C) {
			st.erase(0);
			ss << *(st.begin());
		} else {
			ss << cut;
		}

		return ss.str();
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 3; int Arg2 = 2; int Arg3 = 1; string Arg4 = "5 4"; verify_case(0, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 1; int Arg3 = 2; string Arg4 = "3 3"; verify_case(1, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 5; int Arg3 = 3; string Arg4 = "2 1"; verify_case(2, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10000; int Arg1 = 999983; int Arg2 = 5000; int Arg3 = 1000; string Arg4 = "13 2"; verify_case(3, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 7; int Arg2 = 100; int Arg3 = 100; string Arg4 = "1 1"; verify_case(4, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    LogCutter ___test;

    ___test.run_test(-1);

}

// END CUT HERE
