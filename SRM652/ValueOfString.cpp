// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

class ValueOfString {
	public:
	int findValue(string s) {
		int ans = 0;

		rep(i,s.size())
		{
			int k = 0;
			rep(j,s.size())
			{
				if(s[i] >= s[j]) k++;
			}

			ans += k * (int)(s[i] - 'a' + 1);
		}

		return ans;
	}
};

// BEGIN CUT HERE
int main() {
	ValueOfString ___test;
	cout << ___test.findValue("zz") << endl;
}
// END CUT HERE
