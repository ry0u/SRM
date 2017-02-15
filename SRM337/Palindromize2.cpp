#line 5 "Palindromize2.cpp"
#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,k,n) for(int i=k;i<(int)(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

class Palindromize2 {
	public:
	string minChanges(string s) {
		rep(i, s.size()/2) {
			char a = s[i];
			char b = s[s.size()-1-i];
			if(a == b) continue;
			if(a < b) s[s.size()-1-i] = a;
			else s[i] = b;
		}
		return s;
	}

	

};




// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
