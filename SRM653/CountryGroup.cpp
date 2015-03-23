// BEGIN CUT HERE

// END CUT HERE
#line 5 "CountryGroup.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

class CountryGroup {
	public:
	int solve(vector<int> v) {
		bool flag = true;
		int ans = 0;
		int n = v.size();
		rep(i,n)
		{
			int cnt=v[i],len=1;
			REP(j,i+1,n)
			{
				if(len >= cnt) break;
				if(v[i] == v[j]) 
				{
					i++;
					len++;
				}
				else 
				{
					break;
				}
			}

			if(cnt == len) ans++;
			else flag = false;
		}

		if(flag) return ans;
		else return -1;
	}
};

// BEGIN CUT HERE
int main() {
	CountryGroup ___test;
	vector<int> v(5);
	v[0] = 2;
	v[1] = 2;
	v[2] = 3;
	v[3] = 3;
	v[4] = 3;
	cout << ___test.solve(v) << endl;
}
// END CUT HERE
