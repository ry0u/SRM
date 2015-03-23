// BEGIN CUT HERE

// END CUT HERE
#line 5 "CartInSupermarketEasy.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int memo[101][101];

int dfs(int n,int k)
{
	if(memo[n][k] >= 0) return memo[n][k];
	else
	{
		int res = n;

		if(k > 0)
		{
			REP(i,1,n)
			{
				rep(j,k)
				{
					int split = dfs(i,j);
					int split2 = dfs(n-i,k-1-j);

					res = min(res,max(split,split2)+1);
				}
			}
		}

		memo[n][k] = res;
		return memo[n][k];
	}
}

class CartInSupermarketEasy {
	public:
	int calc(int N, int K) {
		memset(memo,-1,sizeof(memo));
		return dfs(N,K);
	}
};

// BEGIN CUT HERE
int main() {
CartInSupermarketEasy ___test;
___test.run_test(-1);
}
// END CUT HERE
