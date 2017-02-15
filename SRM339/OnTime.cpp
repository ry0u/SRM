// BEGIN CUT HERE

// END CUT HERE
#line 5 "OnTime.cpp"
#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,k,n) for(int i=k;i<(int)(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<P, int> PI;
typedef pair<P, P> PP;

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

vector<PP> G[55];
int d[55][100005];

void dijkstra() {
	rep(i, 55) rep(j, 100005) d[i][j] = INF;
	d[0][0] = 0;

	priority_queue<PI, vector<PI>, greater<PI> > que;
	que.push(mp(mp(0, 0), 0));

	while(que.size()) {
		PI p = que.top(); que.pop();
		int c = p.fi.fi;
		int t = p.fi.se;
		int cur = p.se;

		if(d[cur][t] < cur) continue;

		rep(i, G[cur].size()) {
			int departure = G[cur][i].fi.fi;
			int time = G[cur][i].fi.se;
			int cost = G[cur][i].se.fi;
			int next = G[cur][i].se.se;

			if(departure != 0 && time != 0 && departure <= t) continue;
			if(d[next][departure + time] > c + cost) {
				d[next][departure + time] = c + cost;
				que.push(mp(mp(c + cost, departure + time), next));
			}
		}
	}
}

class OnTime {
	public:
	int minCost(int N, int T, vector <string> buses) {
		rep(i, 55) G[i].clear();

		int M = buses.size();
		rep(i, M) {
			stringstream ss;
			ss << buses[i];
			int a, b, departure, time, cost;
			ss >> a >> b >> departure >> time >> cost;

			G[a].push_back(mp(mp(departure, time), mp(cost, b)));
		}

		dijkstra();

		int ans = INF;
		rep(i, T + 1) {
			ans = min(ans, d[N-1][i]);
		}

		if(ans == INF) return -1;
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 8; string Arr2[] = {"0 1 0 4 3", "1 2 5 3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(0, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 8; string Arr2[] = {"0 1 0 4 3", "1 2 6 3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(1, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 7; string Arr2[] = {"0 1 0 5 1", "1 2 6 1 40", "0 1 1 2 5", "1 2 4 2 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(2, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 8; string Arr2[] = {"0 1 0 5 3", "1 2 5 3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(3, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 100; string Arr2[] = {"0 1 0 1 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(4, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 9; int Arg1 = 100; string Arr2[] = {"0 3 1 6 15", "0 6 0 23 20", "6 2 25 15 30", "6 1 30 15 40", "3 1 15 35 10", 
 "3 2 30 80 40", "1 5 55 25 25", "1 2 49 31 10", "2 8 85 10 10", "5 8 83 15 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 55; verify_case(5, Arg3, minCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    OnTime ___test;

    ___test.run_test(-1);

}

// END CUT HERE
