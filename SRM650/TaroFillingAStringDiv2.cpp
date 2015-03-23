// BEGIN CUT HERE

// END CUT HERE
#line 5 "TaroFillingAStringDiv2.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

class TaroFillingAStringDiv2 {
	public:
	int getNumber(string s) {
		int cnt = 0;
		int n = s.size();

		rep(i,n-1)
		{
			if(s[i] == 'A' && s[i+1] == 'A') cnt++;
			if(s[i] == 'B' && s[i+1] == 'B') cnt++;
		}

		vector<pair<int, pair<int,int> > > v;
		rep(i,n)
		{
			if(s[i] == '?')
			{
				int left = i,right = i,len = 1;
				REP(j,i+1,n)
				{
					if(s[j] == '?') 
					{
						len++;
						i++;
						right = j;
					}
					else  break;
				}

				v.push_back(make_pair(len,make_pair(left,right)));
			}
		}

		rep(i,v.size())
		{
			if(v[i].second.first == 0 && v[i].second.second == n-1) continue;	
			if(v[i].second.first == 0) continue;
			if(v[i].second.second == n-1) continue;
		
			int len = v[i].first;
			int left = v[i].second.first;
			int right = v[i].second.second;

			if(s[left-1] == s[right+1])
			{
				if(len%2 != 0) continue;
				cnt++;
			}
			else
			{
				if(len%2 == 0) continue;
				cnt++;
			}
		}

		return cnt;
	}
};

// BEGIN CUT HERE
int main() {
	TaroFillingAStringDiv2 ___test;
	cout << ___test.getNumber("A??B???AAB?A???A") << endl;	
}
// END CUT HERE
