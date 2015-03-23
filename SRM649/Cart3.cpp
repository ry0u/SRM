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
					res = min(res,max(dfs(i,j),dfs(n-i,k-1-j)) + 1);
				}
			}
		}

		memo[n][k] = res;
		return memo[n][k];
	}
}

class Cart
{
	public:
	int calc(int N, int K) {
		memset(memo,-1,sizeof(memo));

		return dfs(N,K);
	}
};

int main()
{
	int n,k;
	cin >> n >> k;

	Cart cart;
	cout << cart.calc(n,k) << endl;

	cout << "---------------=" << endl;

	rep(i,n+1)
	{
		rep(j,k+1)
		{
			cout << memo[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
