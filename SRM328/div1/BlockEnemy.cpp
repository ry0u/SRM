// BEGIN CUT HERE

// END CUT HERE
#line 5 "BlockEnemy.cpp"

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

int f(string s) {
	int ret;
	stringstream ss(s);
	ss >> ret;
	return ret;
}

struct UnionFind {
	vector<int> par, rank;
	int N;

	UnionFind(int n) {
		N = n;
		par.resize(n);
		rank.resize(n);

		rep(i, n) {
			par[i] = i;
			rank[i] = 0;
		}
	}

	int find(int x) {
		if(par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);

		if(x == y) return;

		if(rank[x] < rank[y]) {
			par[x] = y;
		} else {
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
		}
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	int size() {
		int cnt = 0;
		rep(i, N) if(find(i) == i) cnt++;
		return cnt;
	}
};

struct edge {
	int from,to;
	int cost;

	edge(int t,int c) : to(t),cost(c) {}
	edge(int f,int t,int c) : from(f),to(t),cost(c) {}

	bool operator<(const edge &e) const {
		return cost < e.cost;
	}
};

vector<edge> G[55];
int dist[55][55];

int kruskal(int n, vector<edge> v) {
	sort(v.begin(),v.end());

	UnionFind uf(n);
	rep(i, 55) G[i].clear();
	rep(i, 55) rep(j, 55) dist[i][j] = INF;

	int ret = 0;
	rep(i, v.size()) {
		edge e = v[i];
		if(!uf.same(e.from,e.to)) {
			uf.unite(e.from,e.to);
			ret += e.cost;

			G[e.from].push_back(edge(e.to, e.cost));
			G[e.to].push_back(edge(e.from, e.cost));

			dist[e.from][e.to] = e.cost;
			dist[e.to][e.from] = e.cost;

			// cout << e.from << " -- " << e.to << " [label = \"" << e.cost << "\"];" << endl;
		}
	}

	return ret;
}

bool O[55];
int dp[55]; // 部分木iを消す時の最善
int n;

int dfs2(int cur, int pre) {
	int cnt = 0;
	rep(i, G[cur].size()) {
		edge e = G[cur][i];
		if(e.to == pre) continue;
		cnt++;
	}

	if(cnt == 0) {
		if(O[cur]) {
			dp[cur] = dist[cur][pre];
			return 0;
		} else {
			dp[cur] = 0;
			return 0;
		}
	}

	// cout << " ----------- in dfs : " << cur << " " << pre << endl;

	vector<int> v;
	int ret = 0;
	rep(i, G[cur].size()) {
		edge e = G[cur][i];
		if(e.to == pre) continue;

		int x = dfs2(e.to, cur);
		ret += x;
		int res = min(dp[e.to], dist[e.to][cur]);
		// cout << " comp : " << dp[e.to] << " " << dist[e.to][cur] << endl;

		if(res == 0) continue;
		v.push_back(res);
	}

	// cout << " ------------- back dfs : " << cur << " " << pre << " ret : " << ret << endl;
	// cout << " ---- print v " << endl;
	// rep(i, v.size()) {
	// 	cout << cur << " " << v[i] << endl;
	// }
	// cout << " ---- print dp " << endl;
	// rep(i, n) {
	// 	cout << i << " " << dp[i] << endl;
	// }
	//
	if(O[cur]) {
		int sum = 0;
		rep(i, v.size()) {
			sum += v[i];
		}
		return sum + ret;
	} else {
		if(v.size() == 0) {
			dp[cur] = 0;
			return ret;
		}
		else if(v.size() == 1) {
			dp[cur] = v[0];
			return ret;
		} else {
			sort(v.begin(), v.end());

			int sum = 0;
			rep(i, v.size()-1) {
				sum += v[i];
			}

			dp[cur] = v[v.size()-1];
			return sum + ret;
		}
	}
}

class BlockEnemy {
	public:
	int minEffort(int N, vector <string> roads, vector <int> occupiedTowns) {
		n = N;
		memset(O, 0, sizeof(O));
		rep(i, occupiedTowns.size()) {
			O[occupiedTowns[i]] = true;
			// cout << occupiedTowns[i] << "[color=red];" << endl;
		}

		rep(i, 55) dp[i] = INF;

		vector<edge> E;
		rep(i, roads.size()) {
			vector<string> ret = split(roads[i], ' ');

			int a = f(ret[0]);
			int b = f(ret[1]);
			int e = f(ret[2]);

			E.push_back(edge(a, b, e));
		}

		kruskal(N, E);

		return dfs2(0, -1);
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"1 0 1", "1 2 2", "0 3 3", "4 0 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 2, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(0, Arg3, minEffort(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; string Arr1[] = {"1 0 1", "1 2 2", "0 3 3", "4 0 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, minEffort(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 12; string Arr1[] = {"0 1 3", "2 0 5", "1 3 1", "1 4 8", "1 5 4", "2 6 2",
 "4 7 11", "4 8 10", "6 9 7", "6 10 9", "6 11 6"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 6, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 13; verify_case(2, Arg3, minEffort(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 12; string Arr1[] = {"0 1 3", "2 0 5", "1 3 1", "1 4 8", "1 5 4", "2 6 2",
 "4 7 11", "4 8 10", "6 9 7", "6 10 9", "6 11 6"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 66; verify_case(3, Arg3, minEffort(Arg0, Arg1, Arg2)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    BlockEnemy ___test;

    ___test.run_test(-1);

}

// END CUT HERE
