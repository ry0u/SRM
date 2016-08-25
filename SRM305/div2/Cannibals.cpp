// BEGIN CUT HERE

// END CUT HERE
#line 5 "Cannibals.cpp"

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
typedef pair<P, P> PP;

int memo[105][105][2];

struct State {
	int a, b, c, d, cost;
	bool flag;

	State(int a, int b, int c, int d, int cost, bool flag) : a(a), b(b), c(c), d(d), cost(cost), flag(flag) {}

	bool operator<(const State& s) const {
		return cost < s.cost;
    }
	bool operator>(const State& s) const {
		return cost > s.cost;
    }
};

ostream& operator << (ostream& os, const State& s) {
	os << "(" << s.a << ", " << s.b << " | " << s.c << ", " << s.d << ") : " << s.cost << " flag:" << s.flag;
	return os;
}

bool ok(State s) {
	int a = s.a, b = s.b, c = s.c, d = s.d;
	bool f1 = false;
	if(a == 0 || b == 0) f1 = true;
	if(a >= b) f1 = true;

	bool f2 = false;
	if(c == 0 || d == 0) f2 = true;
	if(c >= d) f2 = true;

	return (f1 && f2);
}

class Cannibals {
	public:
	int minCrossings(int M, int C, int R) {
		memset(memo, -1, sizeof(memo));


		priority_queue<State, vector<State>, greater<State> > que;
		que.push(State(M, C, 0, 0, 0, 0));
		memo[M][C][0] = 0;

		while(que.size()) {
			State s = que.top(); que.pop();

			if(s.flag == 0) {
				rep(i, s.a + 1) {
					rep(j, s.b + 1) {
						if(i == 0 && j == 0) continue;
						if(i + j > R) continue;
						if(i != 0 && j != 0 && i < j) continue;

						int a = s.a - i;
						int b = s.b - j;


						State nc(a, b, s.c + i, s.d + j, s.cost + 1, 1);

						if(ok(nc) && memo[nc.a][nc.b][nc.flag] == -1) {
							memo[nc.a][nc.b][nc.flag] = nc.cost;
							que.push(nc);
						}
					}
				}
			} else {
				rep(i, s.c + 1) {
					rep(j, s.d + 1) {
						if(i == 0 && j == 0) continue;
						if(i + j > R) continue;
						if(i != 0 && j != 0 && i < j) continue;

						int c = s.c - i;
						int d = s.d - j;

						State nc(s.a + i, s.b + j, c, d, s.cost + 1, 0);

						if(ok(nc) && memo[nc.a][nc.b][nc.flag] == -1) {
							memo[nc.a][nc.b][nc.flag] = nc.cost;
							que.push(nc);
						}
					}
				}
			}
		}

		return memo[0][0][1];
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; int Arg3 = 11; verify_case(0, Arg3, minCrossings(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 2; int Arg3 = -1; verify_case(1, Arg3, minCrossings(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 8; int Arg2 = 3; int Arg3 = 17; verify_case(2, Arg3, minCrossings(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 20; int Arg3 = 21; verify_case(3, Arg3, minCrossings(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 99; int Arg2 = 2; int Arg3 = 395; verify_case(4, Arg3, minCrossings(Arg0, Arg1, Arg2)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    Cannibals ___test;

    ___test.run_test(-1);

}

// END CUT HERE
