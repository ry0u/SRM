#line 5 "TheTips.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

class TheTips {
	public:
		double solve(vector<string> s, vector<int> p) {
			vector<double> v(p.size());
			rep(i,p.size()) v[i] = p[i]/100.0;

			double ans = 0;
			rep(i,s.size())
			{
				int cnt = 0;
				rep(j,s[i].size()) if(s[i][j]== 'Y') cnt++;

				ans += cnt*p[i];
			}
			
			return ans/100.0;
		}
};


