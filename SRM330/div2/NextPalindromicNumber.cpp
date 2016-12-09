// BEGIN CUT HERE

// END CUT HERE
#line 5 "NextPalindromicNumber.cpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

string func(string a,string b) {
	string ret;
	if(a.size() < b.size()) swap(a,b);

	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());

	int carry = 0;
	rep(i,b.size()) {
		int x = a[i] - '0';
		int y = b[i] - '0';
		int z = x + y + carry;

		carry = z / 10;
		ret.push_back('0' + (z%10));
	}

	REP(i,b.size(),a.size()) {
		int x = a[i] - '0';
		int z = x + carry;

		carry = z / 10;
		ret.push_back('0' + (z%10));
	}

	if(carry) ret.push_back('0' + carry);
	reverse(ret.begin(),ret.end());
	return ret;
}

class NextPalindromicNumber {
	public:
	string getNext(string n) {
		int sz = n.size();
		string s = n.substr(0, (sz + 1) / 2), t;
		if(sz % 2 == 0) {
			t = s;
		} else {
			t = s.substr(0, s.size()-1);
		}
		reverse(t.begin(), t.end());
		t = s + t;

		if(sz == t.size() && t > n) {
			return t;
		}


		string a = func(s, "1");
		string b;
		if(a.size() == (sz + 1) / 2) {
			if(sz % 2 == 0) {
				b = a;
			} else {
				b = a.substr(0, a.size()-1);
			}
		} else {
			b = a.substr(0, a.size()-1);
			if(sz % 2 == 1) {
				a = a.substr(0, a.size()-1);
			}
		}

		// if(sz % 2 == 0 && a.size() == (sz + 1) / 2) {
		// 	b = a;
		// } else {
		// 	b = a.substr(0, a.size()-1);
		// }
		reverse(b.begin(), b.end());
		return a + b;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "12345"; string Arg1 = "12421"; verify_case(0, Arg1, getNext(Arg0)); }
	void test_case_1() { string Arg0 = "858"; string Arg1 = "868"; verify_case(1, Arg1, getNext(Arg0)); }
	void test_case_2() { string Arg0 = "1999"; string Arg1 = "2002"; verify_case(2, Arg1, getNext(Arg0)); }
	void test_case_3() { string Arg0 = "1"; string Arg1 = "2"; verify_case(3, Arg1, getNext(Arg0)); }
	void test_case_4() { string Arg0 = "9999"; string Arg1 = "10001"; verify_case(4, Arg1, getNext(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    NextPalindromicNumber ___test;

    ___test.run_test(-1);
	cout << ___test.getNext("91") << endl;
	cout << ___test.getNext("9") << endl;
	cout << ___test.getNext("99") << endl;
	cout << ___test.getNext("999") << endl;
}

// END CUT HERE
