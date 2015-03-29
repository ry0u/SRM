// BEGIN CUT HERE

// END CUT HERE
#line 5 "OneEntrance.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

struct edge
{
	int from,to;
	int cost;

	edge(int t,int c) : to(t),cost(c) {}
	edge(int f,int t,int c) : from(f),to(t),cost(c) {}

	bool operator<(const edge &e) const
	{
		return cost < e.cost;
	}
};

vector<edge> G[10];
bool used[10],visit[10];
bool flag = false;

void dfs(int s,int t)
{
	if(used[s]) return;
	used[s] = true;
	
	if(s == t)
	{
		flag = true;
		return;
	}

	rep(i,G[s].size())
	{
		dfs(G[s][i].to,t);
	}
}

class OneEntrance {
	public:
	int count(vector <int> a, vector <int> b, int s) {
		int n = a.size();
		
		map<int,int> m;
		rep(i,n)
		{
			m[a[i]]++;
			m[b[i]]++;

			G[a[i]].push_back(edge(b[i],1));
			G[b[i]].push_back(edge(a[i],1));
		}

		if(m.size() <= 1)
		{
			return 1;
		}

		vector<int> v;
		map<int,int>::iterator ite;
		for(ite = m.begin();ite != m.end();ite++)
		{
			if(ite->first == s) continue;
			v.push_back(ite->first);
		}

		int cnt = 0;
		do
		{
			bool get = false;
			rep(i,10) visit[i] = false;
			
			rep(i,v.size())
			{
				rep(j,10)
				{
					if(visit[j]) used[j] = true;
					else used[j] = false;
				}
				
				flag = false;
				dfs(s,v[i]);
				if(!flag) break;
				
				visit[v[i]] = true;

				if(i == v.size()-1) get = true;
			}

			if(get) cnt++;
		}while(next_permutation(v.begin(),v.end()));
	
		return cnt;
	}
};

// BEGIN CUT HERE
int main() {
	OneEntrance ___test;
	vector<int> a(1);
	a[0] = 0;
	vector<int> b(1);
	b[0] = 1;
	cout << ___test.count(a,b,0) << endl;

}	
// END CUT HERE
