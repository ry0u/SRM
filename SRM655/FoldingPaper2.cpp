// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoldingPaper2.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

ll func(ll x,ll i)
{
	ll cnt = 0;
	if(x <= i) return 0;

	while((x+1)/2 > i)
	{
		x = (x+1) / 2;
		cnt++;
	}

	return cnt+1;
}

class FoldingPaper2 {
	public:
	int solve(int W, int H, int A) {
		ll ret = W;
		ret *= H;
		if(ret < A) return -1;
		if(ret == A) return 0;			
		
		ll ans = 1<<30;

		REP(i,1,A+1)
		{
			if(A%i == 0)
			{
				if(W >= i && H >= A/i) 
				{
					ans = min(ans,func(W,i) + func(H,A/i));
				}

				if(H >= i && W >= A/i)
				{
					ans = min(ans,func(H,i) + func(W,A/i));
				}
			}
		}
		
		if(ans == 1<<30) return -1;
		return ans;
	}	
};

// BEGIN CUT HERE
int main() {
	FoldingPaper2 ___test;
	cout << ___test.solve(1000000000,1000000000,100000) << endl;
}
// END CUT HERE

// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
