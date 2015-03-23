#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

class Cart
{
	public:
	int calc(int N, int K) {
		int res[101][101];

		REP(i,1,N+1) res[i][0] = i;
		rep(i,K+1) res[1][i] = 1;

		REP(i,1,K+1)
		{
			REP(j,2,N+1)
			{
				res[j][i] = j;

				REP(k,1,j)
				{
					for(int l=i-1;l>=0;l--)
					{
						int m = res[k][l];

						if(m < res[j-k][i-1-l]) m = res[j-k][i-1-l];
						if(res[j][i] > m + 1) res[j][i] = m + 1;
					}
				}
			}
		}

		rep(i,N+1)
		{
			rep(j,K+1)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}

		return res[N][K];
	}
};

int main()
{
	Cart c;
	cout << c.calc(15,4) << endl;
	return 0;
}
