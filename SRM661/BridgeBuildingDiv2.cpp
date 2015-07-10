// BEGIN CUT HERE

// END CUT HERE
#line 5 "BridgeBuildingDiv2.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <bitset>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

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
int d[55];

void dijkstra(int s,int n) {
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+n,INF);

    d[s] = 0;
    que.push(P(0,s));

    while(que.size()) {
        P p = que.top();
        que.pop();

        int v = p.second;
        if(d[v] < p.first) continue;

        rep(i,G[v].size()) {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

int cnt = 0;
void print(int n) {
    if(cnt != 85) return;

    cout << "digraph g {" << endl;
    rep(i,n) {
        rep(j,G[i].size()) {
            cout << i << " -> " << G[i][j].to <<"[label=" << G[i][j].cost << ",len = 3.0];" << endl;
        }
    }

    cout << "{ rank=same;";
    rep(i,n/2) {
        cout << i << ";";
    }
    cout << "}" << endl;

    cout << " { rank=same;";
    rep(i,n/2) {
        cout << i+n/2 << ";";
    }
    cout << "}" << endl;
    cout << "}" << endl;
}

class BridgeBuildingDiv2 {
	public:
	int minDiameter(vector <int> a, vector <int> b, int K) {
		int n = a.size() + 1;
        int ans = INF;

        rep(i,1<<n) {
            bitset<12> bit(i);
            if(bit.count() != K) continue;
            
            rep(j,2*n) {
                G[j].clear();
            }

            rep(j,12) {
                if(bit[j]) {
                    G[j].push_back(edge(j+n,0));
                    G[j+n].push_back(edge(j,0));
                }
            }

            rep(j,n-1) {
                G[j].push_back(edge(j+1,a[j]));
                G[j+1].push_back(edge(j,a[j]));
            }

            rep(j,n-1) {
                G[j+n].push_back(edge(j+n+1,b[j]));
                G[j+n+1].push_back(edge(j+n,b[j]));
            }

            int vmax = -1;
            rep(j,n*2) {
                dijkstra(j,2*n);
                rep(k,n*2) vmax = max(vmax,d[k]);
            }

            ans = min(ans,vmax);

        }

        return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,1,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,9,1,9,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 6; verify_case(0, Arg3, minDiameter(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,50,1,50,1,50,1,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,1,50,1,50,1,50,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = 8; verify_case(1, Arg3, minDiameter(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {50,10,15,31,20,23,7,48,5,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,5,1,8,3,2,16,11,9,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 124; verify_case(2, Arg3, minDiameter(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {2,4,10,2,2,22,30,7,28}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,26,1,2,6,2,16,3,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 54; verify_case(3, Arg3, minDiameter(Arg0, Arg1, Arg2)); }

// END CUT HERE
};

// BEGIN CUT HERE
int main() {
    BridgeBuildingDiv2 ___test;
    ___test.run_test(-1);
}
// END CUT HERE

