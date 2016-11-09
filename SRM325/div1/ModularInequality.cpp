// BEGIN CUT HERE

// END CUT HERE
#line 5 "ModularInequality.cpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1LL<<30
#define EPS 1e-2
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll p;
vector<int> v;

bool f(ll x) {
	ll sum = 0;
	rep(i, v.size()) {
		sum += abs(v[i] - x);
	}

	return sum <= p;
}

double g(double x) {
	double sum = 0;
	rep(i, v.size()) {
		sum += abs(v[i] - x);
	}
	return sum;
}

class ModularInequality {
	public:
	int countSolutions(vector <int> A, int P) {
		v = A;
		p = P;

		double l = -4 * INF, r = 4 * INF;

		rep(i, 2000) {
			double a = (l + l + r) / 3.0;
			double b = (l + r + r) / 3.0;

			if(g(a) > g(b)) l = a;
			else r = b;
		}

		if(g(l) >= P + EPS) return 0;

		ll left = l, right = 4 * INF;
		while(right - left > 1) {
			ll mid = (left + right) / 2;
			if(f(mid)) left = mid;
			else right = mid;
		}

		ll a = left + 1;

		left = -4 * INF, right = l + 1;
		while(right - left > 1) {
			ll mid = (left + right) / 2;
			if(f(mid)) right = mid;
			else left = mid;
		}

		ll b = left + 1;
		return a - b;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 5; verify_case(0, Arg2, countSolutions(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10, 30, 15, -1, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; int Arg2 = 7; verify_case(1, Arg2, countSolutions(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 2, 3, -5, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; int Arg2 = 0; verify_case(2, Arg2, countSolutions(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-693}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1265; int Arg2 = 2531; verify_case(3, Arg2, countSolutions(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {965, -938, -396, -142, 926, 31, -720}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6495; int Arg2 = 1781; verify_case(4, Arg2, countSolutions(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    ModularInequality ___test;

    ___test.run_test(-1);
}

// END CUT HERE
