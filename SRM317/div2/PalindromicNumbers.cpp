#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

bool ch(int x) {
	string s = "";
	while(x) {
		s += char('0' + x % 10);
		x /= 10;
	}

	reverse(s.begin(), s.end());
	rep(i, s.size()/2) {
		if(s[i] == s[s.size()-1-i]) continue;
		return false;
	}
	return true;
}

vector<ll> rev(int x) {
	string s = "";
	while(x) {
		s += char('0' + x % 10);
		x /= 10;
	}
	string t = s;
	reverse(s.begin(), s.end());

	vector<string> v;
	v.push_back(s + t);

	rep(i, 10) {
		string ns = s + char('0' + i) + t;
		v.push_back(ns);
	}

	vector<ll> res;
	rep(i, v.size()) {
		ll ret = 0, k = 1;
		for(int j = v[i].size()-1; j >= 0; j--) {
			ret += int(v[i][j] - '0') * k;
			k *= 10;
		}
		res.push_back(ret);
	}

	return res;
}

class PalindromicNumbers {

    public:

    int countPalNums(int lower, int upper) {
		set<int> st;
		for(ll i = 1; i <= 10000; i++) {
			if(lower <= i && i <= upper && ch(i) && st.find(i) == st.end()) {
				st.insert(i);
			}
			
			vector<ll> ret = rev(i);
			rep(j, ret.size()) {
				int x = ret[j];
				if(lower <= x && x <= upper && ch(x) && st.find(x) == st.end()) {
					st.insert(x);
				}
			}
		}

		return st.size();
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 25; int Arg2 = 4; verify_case(0, Arg2, countPalNums(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 111; int Arg1 = 222; int Arg2 = 12; verify_case(1, Arg2, countPalNums(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 88966989; int Arg1 = 88977987; int Arg2 = 0; verify_case(2, Arg2, countPalNums(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 999999990; int Arg1 = 1000000000; int Arg2 = 1; verify_case(3, Arg2, countPalNums(Arg0, Arg1)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    PalindromicNumbers ___test;

    ___test.run_test(-1);
	cout << ___test.countPalNums(1, 1000000000) << endl; //109998
	cout << ___test.countPalNums(34, 24573457) << endl; // 12443
	cout << ___test.countPalNums(1, 20000) << endl; // 12443
}

// END CUT HERE
