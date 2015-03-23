// BEGIN CUT HERE

// END CUT HERE
#line 5 "ThePermutationGameDiv2.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

vector<ll> v;

class ThePermutationGameDiv2 {
	public:
	long long findMin(int n) {
		ll ans = 0;
		v.resize(n);
		rep(i,n) v[i] = i+1;

		do
		{
			vector<ll> f;
			ll i = 0,res = 1<<30;
			bool flag = false;
			
			cout << "-----------------" << endl;
			rep(j,n) cout << v[j] << " ";
			cout << endl;
			while(true)
			{
				if(i == 0) f.push_back(v[0]);
				else
				{
					f.push_back(v[f[i-1]]);
				}
				
				if(f[i] == 1)
				{
					res = min(res,i+1);
					flag = true;
					break;
				}

				i++;
			}

			if(flag) ans = max(ans,res);

		}while(next_permutation(v.begin(),v.end()));

		cout << "ans:" << ans << endl;

		return ans;
	}
};

// BEGIN CUT HERE
int main() {
	ThePermutationGameDiv2 ___test;
	cout << ___test.findMin(2) << endl;;
}
// END CUT HERE
