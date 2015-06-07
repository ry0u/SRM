// BEGIN CUT HERE

// END CUT HERE
#line 5 "Cyclemin.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

class Cyclemin {
	public:
	string bestmod(string s, int k) {
        int n = s.size();

        vector<string> v;
        rep(i,n) {
            rotate(s.begin(),s.begin()+1,s.end());
            v.push_back(s);
        }

        rep(i,n) {
            int cnt = 0;
            while(cnt != k) {
                bool flag = true;
                rep(j,v[i].size()) {
                    if(cnt >= k) break;
                    if(v[i][j] != 'a') {
                        v[i][j] = 'a';
                        cnt++;
                        flag = false;
                    }
                }

                if(flag) break;
            }
        }

        sort(v.begin(),v.end());

        return v[0];
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aba"; int Arg1 = 1; string Arg2 = "aaa"; verify_case(0, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "aba"; int Arg1 = 0; string Arg2 = "aab"; verify_case(1, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "bbb"; int Arg1 = 2; string Arg2 = "aab"; verify_case(2, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "sgsgaw"; int Arg1 = 1; string Arg2 = "aasgsg"; verify_case(3, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "abacaba"; int Arg1 = 1; string Arg2 = "aaaabac"; verify_case(4, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "isgbiao"; int Arg1 = 2; string Arg2 = "aaaisgb"; verify_case(5, Arg2, bestmod(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    Cyclemin ___test;
    ___test.run_test(-1);
}
// END CUT HERE
