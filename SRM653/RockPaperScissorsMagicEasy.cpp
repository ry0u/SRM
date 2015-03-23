#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007

using namespace std;
typedef long long ll;

int cnt[3] = {0};
int memo[2005][2005];

ll nCr(ll n,ll r)
{
	if(n < r) return 0;
	if(n == r) return 1;
	if(r == 1) return n;
	if(memo[n][r] != -1) return memo[n][r];

	return memo[n][r] = (nCr(n-1,r)+nCr(n-1,r-1))%MOD;
}


class RockPaperScissorsMagicEasy {
	public:
	int count(vector<int> card, int score) {
		rep(i,card.size())
		{
			cnt[card[i]]++;
		}

		ll ans = 1;
		memset(memo,-1,sizeof(memo));

		int j = card.size() - score;
		if(j >= 0)
		{
			ans = nCr(card.size(),score);
			rep(i,j)
			{
				ans *= 2;
				ans %= MOD;
			}
			return ans;
		}
		else return 0;
	}
};

// BEGIN CUT HERE
int main() {
	RockPaperScissorsMagicEasy ___test;
	vector<int> a(9);
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	a[3] = 0;
	a[4] = 1;
	a[5] = 2;
	a[6] = 2;
	a[7] = 1;
	a[8] = 0;
	cout << ___test.count(a,8) << endl;
}
// END CUT HERE
