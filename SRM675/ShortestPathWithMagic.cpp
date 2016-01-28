// BEGIN CUT HERE

// END CUT HERE
#line 5 "ShortestPathWithMagic.cpp"
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
#define mp make_pair
#define INF 1<<30

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

struct edge {
	int from,to;
	double cost;
	bool sp;

	edge(int t,double c) : to(t),cost(c) {}
	edge(int t,double c, bool s) : to(t),cost(c),sp(s) {}
	// edge(int f,int t,int c) : from(f),to(t),cost(c) {}

	bool operator<(const edge &e) const {
		return cost < e.cost;
	}
};

struct data {
	double c;
	int to, k;
	data(double cc, int tt, int kk) {
		c = cc;
		to = tt;
		k = kk;
	}

	bool operator<(const data &e) const {
		return c < e.c;
	}
	bool operator>(const data &e) const {
		return c > e.c;
	}
};

vector<edge> G[55];
int K;
double d[55][55];
bool used[55][55];

void dijkstra(int s, int n) {
	priority_queue<data, vector<data>, greater<data> > que;
	rep(i, n) {
		rep(j, K+1) {
			d[i][j] = INF;
			used[i][j] = false;
		}
	}


	d[s][0] = 0;
	que.push(data(0, s, 0));

	while(que.size()) {
		data p = que.top();
		que.pop();

		double c = p.c;
		int v = p.to;
		int k = p.k;

		if(used[v][k]) continue;
		used[v][k] = true;


		if(d[v][k] < c) continue;

		rep(i,G[v].size()) {
			edge e = G[v][i];
			if(e.sp && k < K) {
				if(d[e.to][k+1] > c + e.cost) {
					d[e.to][k+1] = c + e.cost;
					que.push(data(d[e.to][k+1], e.to, k+1));
				}
			} 
			else if(!e.sp && d[e.to][k] > c + e.cost) {
				d[e.to][k] = c + e.cost;
				que.push(data(d[e.to][k],e.to, k));
			}
		}
	}
}


class ShortestPathWithMagic {
	public:
	double getTime(vector <string> dist, int k) {
		int n = dist.size();
		rep(i, n) G[i].clear();
		K = k;

		rep(i, n) {
			rep(j, n) {
				if(i == j) continue;
				double c = (dist[i][j] - '0');
				G[i].push_back(edge(j, c, false));
				G[i].push_back(edge(j, c/2.0, true));
			}
		}

		dijkstra(0, n);

		double ans = INF;
		rep(i, k+1) {
			ans = min(ans,d[1][i]);
		}
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"094",
 "904",
 "440"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 4.5; verify_case(0, Arg2, getTime(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"094",
 "904",
 "440"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 4.0; verify_case(1, Arg2, getTime(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"094",
 "904",
 "440"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; double Arg2 = 4.0; verify_case(2, Arg2, getTime(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"094",
 "904",
 "440"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; double Arg2 = 8.0; verify_case(3, Arg2, getTime(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"076237",
 "708937",
 "680641",
 "296059",
 "334508",
 "771980"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 3.5; verify_case(4, Arg2, getTime(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"00",
 "00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; double Arg2 = 0.0; verify_case(5, Arg2, getTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ShortestPathWithMagic ___test;
    ___test.run_test(-1);
}
// END CUT HERE
