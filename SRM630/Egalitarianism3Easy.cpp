// BEGIN CUT HERE

// END CUT HERE
#line 5 "Egalitarianism3Easy.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 10000000

using namespace std;

int d[15][15];

class Egalitarianism3Easy {
	public:
	int maxCities(int n, vector<int> a, vector<int> b, vector<int> len) {
		if(n == 1) return 1;

		int ans = 0;
		rep(i,n) rep(j,n) d[i][j] = INF;
		rep(i,n) d[i][i] = 0;

		rep(i,n-1)
		{
			a[i]--;
			b[i]--;

			d[a[i]][b[i]] = len[i];
			d[b[i]][a[i]] = len[i];
		}

		rep(k,n)
		{
			rep(i,n)
			{
				rep(j,n)
				{
					d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
				}
			}
		}

		
		rep(i,1<<n)
		{
			bitset<10> bit(i);
			
			vector<int> v;
		
			rep(j,10) if(bit[j]) v.push_back(j);
			map<int,set<int> > res;
		
			rep(j,v.size())
			{
				REP(k,j+1,v.size())
				{
					int from = v[j];
					int to = v[k];

					res[d[from][to]].insert(from);
					res[d[from][to]].insert(to);
				}
			}
			if(res.size() != 1) continue;

			map<int,set<int> >::iterator ite;
			for(ite=res.begin();ite!=res.end();ite++)
			{
				set<int> st = ite->second;
				ans = max(ans,(int)st.size());
			}
		}

		return ans;
	}
};

// BEGIN CUT HERE
int main() {
	Egalitarianism3Easy ___test;
	int n = 6;
	vector<int> a(5);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 2;
	a[4] = 3;

	vector<int> b(5);
	b[0] = 2;
	b[1] = 3;
	b[2] = 4;
	b[3] = 5;
	b[4] = 6;

	vector<int> len(5);
	len[0] = 2;
	len[1] = 1;
	len[2] = 3;
	len[3] = 2;
	len[4] = 3;

	cout << ___test.maxCities(n,a,b,len) << endl;
}
// END CUT HERE
