// BEGIN CUT HERE

// END CUT HERE
#line 5 "BusSeating.cpp"

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
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

double f(vector<P> v) {
	double res = 0;
	rep(t, 3) {
		int nt = (t + 1) % 3;
		P p = mp(v[nt].first - v[t].first, v[nt].second - v[t].second);
		res += sqrt(p.first * p.first + p.second * p.second);
	}
	return res;
}

class BusSeating {
	public:
	double getArrangement(string leftRow, string rightRow) {
		vector<string> s;
		s.push_back(leftRow);
		s.push_back(rightRow);
		s.push_back("XXXXXXXXXX");

		double ans = INF;
		rep(i, 2) {
			rep(j, 10) {
				vector<P> v;

				REP(k, j, 10) {
					if(s[i][k] == '-') {
						v.push_back(mp(i, k));
					}
					if(v.size() == 3) break;
				}

				if(v.size() == 3) {
					ans = min(ans, f(v));
				}

				v.clear();
				REP(k, j, 10) {
					if(s[i][k] == '-') {
						v.push_back(mp(i, k));
					}
					if(v.size() == 2) break;
				}

				if(v.size() == 2) {
					REP(k, j, 10) {
						if(s[i+1][k] == '-') {
							v.push_back(mp(i+2, k));
						}
						if(v.size() == 3) break;
					}

					if(v.size() == 3) {
						ans = min(ans, f(v));
					}
				}

				v.clear();
				REP(k, j, 10) {
					if(s[i][k] == '-') {
						v.push_back(mp(i, k));
					}
					if(v.size() == 1) break;
				}

				if(v.size() == 1) {
					REP(k, j, 10) {
						if(s[i+1][k] == '-') {
							v.push_back(mp(i+2, k));
						}
						if(v.size() == 3) break;
					}

					if(v.size() == 3) {
						ans = min(ans, f(v));
					}
				}
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
	void test_case_0() { string Arg0 = "----------"; string Arg1 = "----------"; double Arg2 = 4.0; verify_case(0, Arg2, getArrangement(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "XXX-X-XX-X"; string Arg1 = "-XXXX---XX"; double Arg2 = 4.0; verify_case(1, Arg2, getArrangement(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "XXXXXXXXXX"; string Arg1 = "-XX-XX-X--"; double Arg2 = 6.0; verify_case(2, Arg2, getArrangement(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "XXX-X-XX-X"; string Arg1 = "XXX-X-XX-X"; double Arg2 = 6.82842712474619; verify_case(3, Arg2, getArrangement(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    BusSeating ___test;

    ___test.run_test(-1);

}

// END CUT HERE
