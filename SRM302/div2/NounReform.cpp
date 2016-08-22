// BEGIN CUT HERE

// END CUT HERE
#line 5 "NounReform.cpp"

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


class NounReform {
	public:
	vector <string> makePlural(vector <string> v) {
		int n = v.size();
		vector<string> ret;

		rep(i, n) {
			string s = v[i];
			char e = s[s.size()-1], e2 = 'X';
			if(s.size() >= 2) e2 = s[s.size()-2];

			if(e == 's' || e == 'z' || e == 'x' || (e2 == 'c' && e == 'h') || (e2 == 's' && e == 'h')) {
				s += "es";
			} else if(e == 'y') {
				if(e2 == 'a' || e2 == 'e' || e2 == 'i' || e2 == 'o' || e2 == 'u') {
					s += 's';
				} else {
					s[s.size()-1] = 'i';
					s += "es";
				}
			} else {
				s += 's';
			}

			ret.push_back(s);
		}

		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"box", "church", "elephant", "stereo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"boxes", "churches", "elephants", "stereos" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, makePlural(Arg0)); }
	void test_case_1() { string Arr0[] = {"tray", "key", "enemy", "baby"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"trays", "keys", "enemies", "babies" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, makePlural(Arg0)); }
	void test_case_2() { string Arr0[] = {"a", "s", "oy", "y", "yy"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"as", "ses", "oys", "ies", "yies" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, makePlural(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    NounReform ___test;

    ___test.run_test(-1);

}

// END CUT HERE
