// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

class TravellingSalesmanEasy {
	public:
	int getMaxProfit(int M, vector <int> profit, vector <int> city, vector <int> visit) {
		vector<int> v[M];
		rep(i,profit.size())
		{
			v[city[i]-1].push_back(profit[i]);
		}

		rep(i,M)
		{
			sort(v[i].begin(),v[i].end(),greater<int>());
		}

		int ans = 0;
		rep(i,visit.size())
		{
			if(v[visit[i]-1].size() == 0) continue;

			ans += v[visit[i]-1][0];
			v[visit[i]-1].erase(v[visit[i]-1].begin());
		}

		return ans;
	}
};

// BEGIN CUT HERE
int main() {
	TravellingSalesmanEasy ___test;
	
	//___test.run_test(-1);
}
// END CUT HERE
