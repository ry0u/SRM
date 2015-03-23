// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxAndSouvenirTheNext.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

class FoxAndSouvenirTheNext {
	public:
	string ableToSplit(vector <int> v) {
		int n = v.size();
		sort(v.begin(),v.end());

		bool flag = true;
		if(v.size()%2 != 0) flag = false;
		else
		{

			bool a[2505][55];
			rep(i,2505) rep(j,55) a[i][j] = false;
			a[0][0] = true;

			int sum = 0;
			rep(i,n)
			{
				sum += v[i];

				REP(t,v[i],sum)
				{
					for(int j=i+1;j>0;j--)
					{
						if(a[t-v[i]][j-1])
						{
							a[t][j] = true;
						}
					}
				}
			}

			if(a[sum/2][n/2] && sum%2 == 0) flag = true;
			else flag = false;
		}

		if(flag) return "Possible";
		else return "Impossible";
	}
};

// BEGIN CUT HERE
int main() {
	FoxAndSouvenirTheNext ___test;
	vector<int> v(6);
	v[0] = 1;
	v[1] = 1;
	v[2] = 2;
	v[3] = 3;
	v[4] = 5;
	v[5] = 8;

	
	cout << ___test.ableToSplit(v) << endl;
}
// END CUT HERE
