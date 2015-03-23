#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

class CartInSupermarketEasy {
	public:
	int calc(int N,int K){
		K = min(N,K);

		int ans = N;

		REP(i,1,K+1)
		{
			int line = i+1;
			int cnt = 0;
			int add = 0;

			cout << "pre:" << line << endl;

			while(line > 1)
			{
				if(line%2 == 1) add++;
				cnt++;
				line = (line + 1) / 2;
			}

			cout << "aft:" << line << " " << cnt << " " << add << endl;;

			int sum = 0;
			rep(j,101)
			{
				if(sum + add < N)
				{
					cout << "j:" << sum << " " << add << " ";
					sum += i + 1;
					cnt++;

					cout << cnt << endl;
				}
				else break;
			}

			ans = min(ans,cnt);
		}



		return ans;
	}
};

int main()
{
	int n,k;
	cin >> n >> k;

	CartInSupermarketEasy cart;
	cout << cart.calc(n,k) << endl;
	return 0;
}
