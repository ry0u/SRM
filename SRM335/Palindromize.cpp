// BEGIN CUT HERE

// END CUT HERE
#line 5 "Palindromize.cpp"
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

class Palindromize {
	public:
	string minAdds(string s) {
		string t = s;
		reverse(t.begin(), t.end());

		bool flag = true;
		rep(i, s.size()/2) {
			if(s[i] == s[s.size()-1-i]) continue;
			flag = false;
		}
		if(flag) return s;

		rep(i, s.size()) {
			bool ch = true;
			rep(j, t.size()) {
				if(i + j >= s.size() || s[i+j] == t[j]) continue;
				ch = false;
			}
			if(ch) {
				return s.substr(0, i) + t;
			}
		}

		return s + t;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "add"; string Arg1 = "adda"; verify_case(0, Arg1, minAdds(Arg0)); }
	void test_case_1() { string Arg0 = "cigartragic"; string Arg1 = "cigartragic"; verify_case(1, Arg1, minAdds(Arg0)); }
	void test_case_2() { string Arg0 = "redocpot"; string Arg1 = "redocpotopcoder"; verify_case(2, Arg1, minAdds(Arg0)); }
	void test_case_3() { string Arg0 = "acaba"; string Arg1 = "acabaca"; verify_case(3, Arg1, minAdds(Arg0)); }
	void test_case_4() { string Arg0 = "abczyxyz"; string Arg1 = "abczyxyzcba"; verify_case(4, Arg1, minAdds(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    Palindromize ___test;

    ___test.run_test(-1);

}

// END CUT HERE
