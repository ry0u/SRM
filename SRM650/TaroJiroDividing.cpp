// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

class TaroJiroDividing {
	public:
	int getNumber(int A, int B) {

		vector<int> v,v2;
		while(true)
		{
			v.push_back(A);

			if(A%2 != 0) break;
			A /= 2;
		}

		while(true)
		{
			v2.push_back(B);
			
			if(B%2 != 0) break;
			B /= 2;
		}

		int ans = 0;
		rep(i,v.size())
		{
			rep(j,v2.size())
			{
				if(v[i] == v2[j]) ans++;
			}
		}
		
		return ans;
	}
};

// BEGIN CUT HERE
int main() {
	TaroJiroDividing ___test;
	
	cout << ___test.getNumber(4,7) << endl;;
}
// END CUT HERE
//

