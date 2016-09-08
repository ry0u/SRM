// BEGIN CUT HERE

// END CUT HERE
#line 5 "PyramidOfCubes.cpp"

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

class PyramidOfCubes {
	public:
	double surface(int K) {
		ll x = 1;
		ll sum = x * x;

		while(sum < K) {
			x++;
			sum += x * x;
		}

		double ans = 0.0;
		bool first = true;

		while(K) {
			if(K >= x * x) {
				if(first) {
					ans += x * x * 2;
					first = false;
				}

				K -= x * x;
				ans += x * 4;
				x--;
			} else {
				if(first) {
					ans += K * 2;
					first = false;
				}

				double res = INF;

				if(x <= K) {
					REP(i, 1, x + 1) {
						if(x * i >= K) {
							res = min(res, double(i * 2 + x * 2));
						}
					}
				} else {
					res = min(res, double(K * 2 + 2));
				}

				K = 0;
				ans += res;
			}
		}
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 14; double Arg1 = 42.0; verify_case(0, Arg1, surface(Arg0)); }
	void test_case_1() { int Arg0 = 21; double Arg1 = 58.0; verify_case(1, Arg1, surface(Arg0)); }
	void test_case_2() { int Arg0 = 1; double Arg1 = 6.0; verify_case(2, Arg1, surface(Arg0)); }
	void test_case_3() { int Arg0 = 2; double Arg1 = 10.0; verify_case(3, Arg1, surface(Arg0)); }
	void test_case_4() { int Arg0 = 451234; double Arg1 = 47498.0; verify_case(4, Arg1, surface(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    PyramidOfCubes ___test;

    ___test.run_test(-1);
	cout << ___test.surface(10) << endl;
}

// END CUT HERE
