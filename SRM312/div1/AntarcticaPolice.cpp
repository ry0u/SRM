#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

struct SCC {
	int n;
	vector<vector<int> > g, rg, ng, scc; // rg: 逆グラフ, ng: 分解後のグラフ
	vector<int> res; // scc: 強連結成分に属する頂点, res:強連結成分の番号
	bool used[100005];

	SCC(int _n) {
		n = _n;
		g.resize(n); rg.resize(n) ; scc.resize(n); res.resize(n);
	}

	SCC(const vector<vector<int> > &g) : n(g.size()), g(g), rg(n), scc(n), res(n) {
		rep(i, n) {
			rep(j, g[i].size()) rg[g[i][j]].push_back(i);
		}
	}

	// i-jに辺を追加する
	void add(int i, int j) {
		g[i].push_back(j);
		rg[j].push_back(i);
	}

	vector<int> vs;
	void dfs(int v) {
		used[v] = true;
		rep(i, g[v].size()) {
			if(!used[ g[v][i] ]) dfs(g[v][i]);
		}
		vs.push_back(v);
	}

	void rdfs(int v, int k) {
		used[v] = true;
		res[v] = k; 
		scc[k].push_back(v);
		rep(i, rg[v].size()) {
			if(!used[ rg[v][i] ]) rdfs(rg[v][i], k);
		}
	}

	void ng_make(int k) {
		ng.resize(k);

		rep(i, k) {
			set<int> st;
			rep(j, scc[i].size()) {
				int ii = scc[i][j];

				rep(l, g[ii].size()) {
					int ll = g[ii][l];
					int id = res[ll];

					if(i == id) continue;
					st.insert(id);
				}
			}

			vector<int> v(st.begin(), st.end());
			ng[i] = v;
		}
	}

	int run() {
		memset(used, 0, sizeof(used));
		rep(i, n) {
			if (!used[i]) dfs(i);
		}

		memset(used, 0, sizeof(used));
		int k = 0;
		for (int i = vs.size()-1; i >= 0; i--) {
			if (!used[vs[i]]) rdfs(vs[i], k++);
		}

		ng_make(k);

		return k;
	}
};

class AntarcticaPolice {

    public:

    double minAverageCost(vector <int> cost, vector <string> roads) {
		int n = cost.size();

		SCC scc(n);

		rep(i, n) {
			rep(j, n) {
				if(roads[i][j] == 'Y') {
					scc.add(i, j);
				}
			}
		}

		int k = scc.run();
		vector<int> res(k, INF), res_id(k, -1);
		rep(i, n) {
			int j = scc.res[i];
			if(res[j] > cost[i]) {
				res[j] = cost[i];
				res_id[j] = i;
			}
		}

		vector<int> out(k);
		rep(i, k) {
			rep(j, scc.ng[i].size()) {
				int l = scc.ng[i][j];
				out[l]++;
			}
		}

		int sum = 0, cnt = 0;
		vector<int> ret;
		
		rep(i, k) {
			if(out[i] == 0) {
				sum += res[i];
				cnt++;
			} else {
				ret.push_back(res[i]);
			}
		}

		set<int> id;
		rep(i, k) id.insert(res_id[i]);

		rep(i, n) {
			if(id.find(i) == id.end()) {
				ret.push_back(cost[i]);
			}
		}

		sort(ret.begin(), ret.end());

		rep(i, ret.size()) {
			double a = double(sum) / cnt;
			double b = double(sum + ret[i]) / (cnt + 1);

			if(a > b) {
				sum += ret[i];
				cnt++;
			} else break;
		}

		return double(sum) / cnt;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNN","NNYN","NNNY","YNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, minAverageCost(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNN","NNYN","NNNY","NYNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(1, Arg2, minAverageCost(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,6,7,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNN","YNNN","NNNY", "NNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.0; verify_case(2, Arg2, minAverageCost(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NY","NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 7.5; verify_case(3, Arg2, minAverageCost(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {34,22,25,43,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNNY","YNNYN","NNNYY","NNNNN","NNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 19.666666666666668; verify_case(4, Arg2, minAverageCost(Arg0, Arg1)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    AntarcticaPolice ___test;

    ___test.run_test(-1);

	cout << ___test.minAverageCost({1, 99, 100}, {"NNN", "NNN", "YYN"}) << endl; //50.5
	cout << ___test.minAverageCost({448, 886, 608, 800, 965, 701, 791, 961, 955, 861, 749, 261, 900, 898, 465, 775, 883, 520, 842, 967, 800}, {"NNNNNYNNNNNYNNNNNNNNN", "NNNNNNNNYNNNNNNNNNNNN", "NNNNNYNNNYNYNNNNNNYNN", "NNNNNNNNNNNNYNNNNNNNN", "NYNNNNNNNNNNNYNNNNNNN", "NNNNNNYNNNNNNNNNNNNNN", "YNYNNNNNNNNYNNNNNNNNN", "NYNNNNNNNNNNNNNNNNNNN", "NNNNYNNNNNYNNNNNYNNNY", "NNNNNYNNNNNNNNNNNNYNN", "NNNNNNNYNNNNNNNYNNNYN", "NNNNNNNNNNNNNNNNNNYNN", "NNNNNNNNNNNNNNYNNNNNN", "NNNNNNNNYNNNNNNNNNNNY", "NNNYNNNNNNNNNNNNNYNNN", "NNNNNNNNNNYNNNNNNNNNN", "NNNNNNNNNNYNNNNYNNNNY", "NNNNNNNNNNNNNNYNNNNNN", "NNNNNNYNNNNNNNNNNNNNN", "NNNNNNNNNNYNNNNNNNNNN", "NNNNNNNYNNNNNNNNNNNNN"}) << endl;
}

// END CUT HERE
