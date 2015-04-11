// BEGIN CUT HERE

// END CUT HERE
#line 5 "Similars.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <bitset>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int tobit(int A)
{
	stringstream ss;
	ss << A;
	string a = ss.str();
	
	int ret = 0;
	rep(i,a.size()) ret |= 1 << (a[i] - '0');

	return ret;
}

class Similars {
	public:
	int maxsim(int L, int R) {
		
		stringstream ss,ss2;
		
		ss2 << R;
		int r = ss2.str().size();

		int ans = 0;

		bool used[1050],used2[1050];
		memset(used,0,sizeof(used));

		for(int i=R;i>=L;i--)
		{
			int A = tobit(i);
			if(used[A]) continue;
			used[A] = true;

			memset(used2,0,sizeof(used2));

			for(int j=i-1;j>=L;j--)
			{
				int B = tobit(j);
				if(used2[B]) continue;
				used2[B] = true;

				int d = __builtin_popcount(A&B);
				ans = max(ans,d);
			}

			stringstream ss;
			ss << i;
			int size = ss.str().size();
			
			if(size < r-1) break;
			if(size <= ans) break;
		}

		return ans;
	}
};

// BEGIN CUT HERE
int main() {
	Similars ___test;
	cout << ___test.maxsim(7535,91956) << endl;
}
// END CUT HERE
