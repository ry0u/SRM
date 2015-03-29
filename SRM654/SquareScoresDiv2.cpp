// BEGIN CUT HERE

// END CUT HERE
#line 5 "SquareScoresDiv2.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

ll f(ll x)
{
	ll ret = 0;
	REP(i,1,x+1)
	{
		ret += i;
	}

	return ret;
}

class SquareScoresDiv2 {
	public:
	int getscore(string s) {
		vector<int> v;
		int n = s.size();
		rep(i,n)
		{
			int size = 1;
			REP(j,i+1,n)
			{
				if(s[i] == s[j])
				{
					i++;
					size++;
				}
				else break;
			}

			v.push_back(size);
		}
		
		ll ans = 0;
		rep(i,v.size())
		{
			ans += f(v[i]);
		}

		return ans;
	}
};

// BEGIN CUT HERE
int main() {
	SquareScoresDiv2 ___test;
	cout << ___test.getscore("zzzxxzz") << endl;
}
// END CUT HERE
