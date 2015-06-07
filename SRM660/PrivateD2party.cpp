// BEGIN CUT HERE

// END CUT HERE
#line 5 "PrivateD2party.cpp"
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

using namespace std;
typedef long long ll;

struct UnionFind {
    vector<int> par,rank;
    int N;

    UnionFind(int n) {
        N = n;
        par.resize(n);
        rank.resize(n);

        rep(i,n) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x,int y) {
        x = find(x);
        y = find(y);

        if(x == y) return;

        if(rank[x] < rank[y]) {
            par[x] = y;
        }
        else {
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(int x,int y) {
        return find(x) == find(y);
    }

    int size() {
        int cnt = 0;
        rep(i,N) if(find(i) == i) cnt++;
        return cnt;
    }
};

vector<int> g;
bool used[55];
int cnt = 0;

void dfs(int cur) {
    int next = g[cur];
    if(used[next]) return;
    if(used[g[next]]) return;

    used[next] = true;
    cnt++;
    
    dfs(next);
}

class PrivateD2party {
	public:
	int getsz(vector <int> a) {
        int n = a.size();
        g.clear();
        copy(a.begin(),a.end(),back_inserter(g));

        UnionFind uf(n);

        rep(i,n) {
            if(a[i] == i) continue;
            uf.unite(i,a[i]);
        }

        int d[55];
        memset(d,0,sizeof(d));
        rep(i,n) {
            int p = uf.find(i);
            memset(used,0,sizeof(used));
            used[i] = true;
            cnt = 1;
            dfs(i);
            d[p] = max(d[p],cnt);
        }

        int ans = 0;
        rep(i,n) {
            ans += d[i];
        }

        return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getsz(Arg0)); }
	void test_case_1() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getsz(Arg0)); }
	void test_case_2() { int Arr0[] = {1,0,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getsz(Arg0)); }
	void test_case_3() { int Arr0[] = {5,2,2,4,5,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, getsz(Arg0)); }
	void test_case_4() { int Arr0[] = {3,2,1,0,5,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, getsz(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PrivateD2party ___test;
    ___test.run_test(-1);

    vector<int> v;
    v.push_back(13);
    v.push_back(1);
    v.push_back(2);
    v.push_back(6);
    v.push_back(17);
    v.push_back(17);
    v.push_back(2);
    v.push_back(18);
    v.push_back(14);
    v.push_back(14);
    v.push_back(15);
    v.push_back(7);
    v.push_back(14);
    v.push_back(15);
    v.push_back(6);
    v.push_back(8);
    v.push_back(5);
    v.push_back(5);
    v.push_back(4);
    v.push_back(2);

    cout << ___test.getsz(v) << endl;
}
// END CUT HERE
