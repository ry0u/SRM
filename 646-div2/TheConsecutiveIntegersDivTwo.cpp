#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

class TheConsecutiveIntegersDivTwo {
	public:
	int find(vector <int> numbers, int k) {
		if(k == 1) return 0;
		else
		{
			vector<pair<int,pair<int,int> > > p;
			sort(numbers.begin(),numbers.end());

			rep(i,numbers.size()-1)
			{
				int temp = abs(numbers[i]-numbers[i+1]);
				p.push_back(make_pair(temp,make_pair(numbers[i],numbers[i+1])));
			}

			sort(p.begin(),p.end());

			return p[0].first-1;
		}
	}
};

// BEGIN CUT HERE
// END CUT HERE
