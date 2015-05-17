// BEGIN CUT HERE

// END CUT HERE
#line 5 "CorruptedMessage.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

class CorruptedMessage {
	public:
	string reconstructMessage(string s, int k) {
		string ret = "";

		map<char,int> m;
		rep(i,s.size())
		{
			m[s[i]]++;
		}

		bool flag = true;
		char c = s[0];
		rep(i,27)
		{
			if(m['a'+i] == s.size()-k)
			{
				flag = false;
				c = (char)('a'+i);
				break;
			}
		}

		if(!flag)
		{
			stringstream ss;
			ss << c;
			rep(i,s.size())
			{
				ret += ss.str();
			}
		}
		else
		{
			char t = s[0];
			rep(i,27)
			{
				if(m['a'+i] == 0)
				{
					t = (char)('a'+i);
					break;
				}
			}

			stringstream ss;
			ss << t;

			rep(i,s.size()) ret += ss.str();
		}


		return ret;
	}
};

// BEGIN CUT HERE
int main() {
	CorruptedMessage ___test;
	cout << ___test.reconstructMessage("abs",3) << endl;
}
// END CUT HERE

