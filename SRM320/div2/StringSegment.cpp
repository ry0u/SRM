// BEGIN CUT HERE

// END CUT HERE
#line 5 "StringSegment.cpp"

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

vector<string> samesplit(string s) {
	vector<string> ret;
	rep(i, s.size()) {
		string t = "";

		char c = s[i];
		t += c;

		REP(j, i+1, s.size()) {
			if(c == s[j]) {
				t += s[j];
				i++;
				continue;
			} else break;
		}

		ret.push_back(t);
	}

	return ret;
}

class StringSegment {
	public:
	double average(string s) {
		vector<string> ret = samesplit(s);

		double sum = 0;
		rep(i, ret.size()) {
			sum += ret[i].size();
		}

		return sum / ret.size();
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aaabbaaac"; double Arg1 = 2.25; verify_case(0, Arg1, average(Arg0)); }
	void test_case_1() { string Arg0 = "aabbccdd"; double Arg1 = 2.0; verify_case(1, Arg1, average(Arg0)); }
	void test_case_2() { string Arg0 = "abba"; double Arg1 = 1.3333333333333333; verify_case(2, Arg1, average(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    StringSegment ___test;

    ___test.run_test(-1);

}

// END CUT HERE
