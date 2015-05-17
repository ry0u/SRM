// BEGIN CUT HERE

// END CUT HERE
#line 5 "DoubleLetter.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

class DoubleLetter {
	public:
	string ableToSolve(string s) {
		string ret = s;
		cout << ret << endl;
		while(true && ret.size() > 0)
		{
			bool flag = false;
			rep(i,ret.size()-1)
			{
				if(ret[i] == ret[i+1]) 
				{
					flag = true;
					break;
				}
			}

			if(!flag) break;
			
			rep(i,ret.size()-1)
			{
				if(ret[i] == ret[i+1])
				{
					stringstream ss;
					rep(j,ret.size())
					{
						if(j == i || j == i+1) continue;
						ss << ret[j];
					}
					ret = ss.str();
					break;
				}
			}
		}

		if(ret.size() == 0) return "Possible";
		else return "Impossible";
	}
};

// BEGIN CUT HERE
int main() {
	DoubleLetter ___test;
	cout << ___test.ableToSolve("aabb") << endl;;
}
// END CUT HERE
