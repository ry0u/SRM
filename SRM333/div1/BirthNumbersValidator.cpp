// BEGIN CUT HERE

// END CUT HERE
#line 5 "BirthNumbersValidator.cpp"

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

int days[2][13] = {	{0,31,28,31,30,31,30,31,31,30,31,30,31},
					{0,31,29,31,30,31,30,31,31,30,31,30,31} };

string f(string s) {
	stringstream ss;
	ss << s;

	ll x;
	ss >> x;

	if(x % 11 != 0) return "NO";

	int yy = (s[0] -'0') * 10 + (s[1] - '0');
	int mm = (s[2] -'0') * 10 + (s[3] - '0');
	int dd = (s[4] -'0') * 10 + (s[5] - '0');
	// int cccc = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');

	if(yy % 4 == 0) {
		if(1 <= mm && mm <= 12 && 1 <= dd && dd <= days[1][mm]) {
			return "YES";
		} else if(51 <= mm && mm <= 62 && 1 <= dd && dd <= days[1][mm-50]) {
			return "YES";
		} else {
			return "NO";
		}
	} else {
		if(1 <= mm && mm <= 12 && 1 <= dd && dd <= days[0][mm]) {
			return "YES";
		} else if(51 <= mm && mm <= 62 && 1 <= dd && dd <= days[0][mm-50]) {
			return "YES";
		} else {
			return "NO";
		}
	}
}

class BirthNumbersValidator {
	public:
	vector <string> validate(vector <string> test) {
		int n = test.size();
		vector<string> ret(n);
		rep(i, n) {
			ret[i] = f(test[i]);
		}

		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"8104121234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YES" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, validate(Arg0)); }
	void test_case_1() { string Arr0[] = {"8154121239"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YES" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, validate(Arg0)); }
	void test_case_2() { string Arr0[] = {"8134120005"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NO" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, validate(Arg0)); }
	void test_case_3() { string Arr0[] = {"8102310007","8104121235"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NO", "NO" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, validate(Arg0)); }
	void test_case_4() { string Arr0[] = {"0411131237"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YES" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, validate(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    BirthNumbersValidator ___test;

    ___test.run_test(-1);

}

// END CUT HERE
