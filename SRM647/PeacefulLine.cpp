#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

class PeacefulLine {
	public:
	string makeLine(vector <int> x) {
		sort(x.begin(),x.end());

		map<int,int> ma;
		rep(i,x.size())
		{
			ma[x[i]]++;
		}
		
		int xmax = -1;
		map<int,int>::iterator ite;
		
		for(ite = ma.begin();ite != ma.end();ite++)
		{
			xmax = max(xmax,ite->second);
		}
		
		int ret = x.size() - xmax;
		if(xmax - ret <= 1)
		{
			return "possible";
		}
		else return "impossible";
	}
};

// BEGIN CUT HERE
int main() {
	PeacefulLine ___test;
	vector<int> v(11);
	v[0] = 25;
	v[1] = 12;
	v[2] = 3;
	v[3] = 25;
	v[4] = 25;
	v[5] = 12;
	v[6] = 12;
	v[7] = 12;
	v[8] = 12;
	v[9] = 3;
	v[10] = 25;
	cout << ___test.makeLine(v) << endl;;
}
// END CUT HERE

