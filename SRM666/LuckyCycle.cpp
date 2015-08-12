// BEGIN CUT HERE

// END CUT HERE
#line 5 "LuckyCycle.cpp"
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
#define INF 1<<30

using namespace std;
typedef long long ll;

int n = 0,m = 0;

struct edge {
    int from,to;
    int cost;

    edge(int t,int c) : to(t),cost(c) {}
    edge(int f,int t,int c) : from(f),to(t),cost(c) {}

    bool operator<(const edge &e) const {
        return cost < e.cost;
    }
};

vector<edge> G[105];
vector<pair<int,int> > cnt(105);
bool used[105];

void dfs(int cur) {
    used[cur] = true;

    rep(i,G[cur].size()) {
        edge e = G[cur][i];
        if(e.cost == 4 && !used[e.to]) {
            cnt[e.to].first = cnt[cur].first + 1;
            cnt[e.to].second = cnt[cur].second;
            dfs(e.to);
        }
        else if(e.cost == 7 && !used[e.to]) {
            cnt[e.to].second = cnt[cur].second + 1;
            cnt[e.to].first = cnt[cur].first;
            dfs(e.to);
        }
    }
}

class LuckyCycle {
	public:
	vector <int> getEdge(vector <int> edge1, vector <int> edge2, vector <int> weight) {
        n = edge1.size() + 1;
        m = edge1.size();

        rep(i,105) {
            G[i].clear();
            cnt[i].first = 0;
            cnt[i].second = 0;
        }

        rep(i,m) {
            int s = edge1[i];
            int t = edge2[i];
            int c = weight[i];

            s--;
            t--;

            G[s].push_back(edge(t,c));
            G[t].push_back(edge(s,c));
        }

        rep(i,n) {
            memset(used,0,sizeof(used));
            rep(j,105) cnt[i].first = 0,cnt[j].second = 0;
            dfs(i);

            rep(j,n) {
                if(i == j) continue;

                bool flag = true;
                rep(k,m) {
                    if(edge1[k] == i+1 && edge2[k] == j+1) flag = false;
                    if(edge1[k] == j+1 && edge2[k] == i+1) flag = false;
                }

                if(!flag) continue;

                if(cnt[j].first == cnt[j].second+1) {
                    vector<int> ret(3);
                    ret[0] = i+1;
                    ret[1] = j+1;
                    ret[2] = 7;
                    return ret;
                }

                if(cnt[j].first+1 == cnt[j].second) {
                    vector<int> ret(3);
                    ret[0] = i+1;
                    ret[1] = j+1;
                    ret[2] = 4;
                    return ret;
                }
            }
        }

        vector<int> ret;
        return ret;

	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, getEdge(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1, 3, 2, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 7, 4, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 5, 7 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, getEdge(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 12, 7 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, getEdge(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 4, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 7, 7, 7, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 4, 4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, getEdge(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    LuckyCycle ___test;
    ___test.run_test(-1);
}
// END CUT HERE
