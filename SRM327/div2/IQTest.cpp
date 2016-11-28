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

class IQTest {

    public:

    string nextNumber(vector <int> previous) {

		vector<ll> v(previous.begin(), previous.end());

		if(v.size() == 1) return "AMBIGUITY";

		set<ll> st;

		REP(a, -100000, 100000) {
			ll b = v[1] - (v[0] * a);
			bool ch = true;

			rep(i, v.size()-1) {
				if(v[i] * a + b == v[i+1]) continue;
				ch = false;
			}

			if(ch) {
				st.insert(v[v.size()-1] * a + b);
			}
		}

		if(st.size() == 0) return "BUG";

		if(st.size() == 1) {
			stringstream ss;
			ss << *(st.begin());
			return ss.str();
		}

		return "AMBIGUITY";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "6"; verify_case(0, Arg1, nextNumber(Arg0)); }
	void test_case_1() { int Arr0[] = {3, 6, 12, 24, 48}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "96"; verify_case(1, Arg1, nextNumber(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 4, 13, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "121"; verify_case(2, Arg1, nextNumber(Arg0)); }
	void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AMBIGUITY"; verify_case(3, Arg1, nextNumber(Arg0)); }
	void test_case_4() { int Arr0[] = {-1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AMBIGUITY"; verify_case(4, Arg1, nextNumber(Arg0)); }
	void test_case_5() { int Arr0[] = {57, 57}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "57"; verify_case(5, Arg1, nextNumber(Arg0)); }
	void test_case_6() { int Arr0[] = {16, -8, 4, -2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BUG"; verify_case(6, Arg1, nextNumber(Arg0)); }
	void test_case_7() { int Arr0[] = {6, 5, 4, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BUG"; verify_case(7, Arg1, nextNumber(Arg0)); }
	void test_case_8() { int Arr0[] = {-12, 12, -36, 60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-132"; verify_case(8, Arg1, nextNumber(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    IQTest ___test;

    ___test.run_test(-1);
	cout << ___test.nextNumber({-100, -99, 99}) << endl;
}

// END CUT HERE
