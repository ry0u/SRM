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

int bitcnt(int A,int B)
{
	stringstream ss;
	ss << A;
	string a = ss.str();

	stringstream ss2;
	ss2 << B;
	string b = ss2.str();

	int ret = 0;
	rep(i,a.size())
	{
		ret |= (1 << (a[i]-'0'));
	}

	int ret2 = 0;
	rep(i,b.size())
	{
		ret2 |= (1 << (b[i]-'0'));
	}

	ret &= ret2;
	bitset<10> bit(ret);
	
	return bit.count();
}

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
		ss << L;
		int l = ss.str().size();

		ss2 << R;
		int r = ss2.str().size();

		int ans = 0;

		bool used[1050];
		memset(used,0,sizeof(used));

		for(int i=R;i>=L;i--)
		{
			int A = tobit(i);
			if(used[A]) continue;
			used[A] = true;

			bool used2[1050];
			memset(used2,0,sizeof(used2));

			for(int j=i-1;j>=L;j--)
			{
				int B = tobit(j);
				if(used2[B]) continue;
				used2[B] = true;

				int d = bitcnt(i,j);
				ans = max(ans,d);
			}

			stringstream ss;
			ss << i;

			int size = ss.str().size();
			
			if(ans == size || size < r-1) break;
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
