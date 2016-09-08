// BEGIN CUT HERE

// END CUT HERE
#line 5 "InputBoxChecker.cpp"

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

string f(ll x) {
	string s = "";
	while(x) {
		s += char('0' + x % 10);
		x /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

ll g(string s) {
	ll ret = 0, t = 1;
	for(int i = s.size() - 1; i >= 0; i--) {
		ret += int(s[i] - '0') * t;
		t *= 10;
	}

	return ret;
}

class InputBoxChecker {
	public:
	vector <string> checkPrefix(int smallest, int largest, vector <int> numbers) {
		string s = f(smallest);
		string t = f(largest);

		int n = numbers.size();
		vector<string> ret(n);

		rep(i, n) {
			string x = f(numbers[i]);
			bool flag = false;

			if(numbers[i] <= largest) {
				if(x.size() > s.size()) {
					flag = true;
				} else {
					string xx = "";

					rep(j, s.size()) {
						if(j < x.size()) xx += x[j];
						else xx += s[j];
					}

					if(smallest <= g(xx) && g(xx) <= largest) flag = true;

					xx = x;
					while(g(xx) <= largest) {
						if(smallest <= g(xx) && g(xx) <= largest) flag = true;
						xx += "0";
					}
				}
			}

			if(flag) ret[i] = "VALID";
			else ret[i] = "INVALID";
		}
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); 
		if(Case == -1) test_case_5();
		if(Case == -1) test_case_6();
	}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 300; int Arg1 = 347; int Arr2[] = {37}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"INVALID" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, checkPrefix(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 310; int Arg1 = 320; int Arr2[] = {3, 31, 317, 3174, 310, 320}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"VALID", "VALID", "VALID", "INVALID", "VALID", "VALID" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, checkPrefix(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 600; int Arg1 = 1020; int Arr2[] = {7, 73, 734, 7349}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"VALID", "VALID", "VALID", "INVALID" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, checkPrefix(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 64; int Arg1 = 78; int Arr2[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"INVALID", "INVALID", "INVALID", "INVALID", "INVALID", "VALID", "VALID", "INVALID", "INVALID" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, checkPrefix(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1234567890; int Arr2[] = {123, 456, 789, 1234567, 7654321, 3245354, 325432532, 243212}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, checkPrefix(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 123; int Arg1 = 12345; int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 122, 123, 124, 12, 13, 139, 290, 9, 99, 999, 9999, 99999, 1234, 1233, 1235}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "INVALID", "VALID", "VALID", "VALID"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, checkPrefix(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 401234567; int Arg1 = 2000000000; int Arr2[] = {1, 1, 1, 1, 1, 11, 11, 11, 11, 11, 2, 3, 4, 5, 6, 7, 8, 9, 31, 78, 123456789, 234567890, 312435678, 1234567890, 1999999999, 2000000000, 123456789, 234567890, 312435678, 1234567890, 1999999999, 2000000000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "INVALID", "VALID", "VALID", "VALID", "VALID", "VALID", "VALID", "INVALID", "VALID", "VALID", "INVALID", "INVALID", "VALID", "VALID", "VALID", "VALID", "INVALID", "INVALID", "VALID", "VALID", "VALID"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(6, Arg3, checkPrefix(Arg0, Arg1, Arg2)); }


// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    InputBoxChecker ___test;

    ___test.run_test(-1);

	vector<int> v = {1, 3, 2, 5, 6, 87, 342, 325, 32, 32523532, 6437654, 1987654320, 213214, 32543265, 436235, 326437543, 437643, 43265432, 32, 33, 34, 333, 333333333};

	vector<string> ans = ___test.checkPrefix(33, 1234098765, v);
}

// END CUT HERE
