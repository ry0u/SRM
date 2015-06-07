// BEGIN CUT HERE

// END CUT HERE
#line 5 "Target.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

class Target {
	public:
	vector <string> draw(int n) {
        vector<string> v(n);
        string s = "";
        rep(i,n) s += " ";
        
        rep(i,n) v[i] = s;
        
        int cnt = ceil(n/4.0);
        int u = 0,d = n-1;

        while(cnt--) {
           rep(i,n) {
               rep(j,n) {
                   if(i == u && u <= j && j <= d) v[i][j] = '#';
                   if(i == d && u <= j && j <= d) v[i][j] = '#';
               }
           }

           rep(i,n) {
               rep(j,n) {
                   if(i == u && u <= j && j <= d) v[j][i] = '#';
                   if(i == d && u <= j && j <= d) v[j][i] = '#';
               }
           }

           u += 2;
           d -= 2;
        }
        
        return v;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"#####", "#   #", "# # #", "#   #", "#####" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, draw(Arg0)); }
	void test_case_1() { int Arg0 = 9; string Arr1[] = {"#########", "#       #", "# ##### #", "# #   # #", "# # # # #", "# #   # #", "# ##### #", "#       #", "#########" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, draw(Arg0)); }
	void test_case_2() { int Arg0 = 13; string Arr1[] = {"#############", "#           #", "# ######### #", "# #       # #", "# # ##### # #", "# # #   # # #", "# # # # # # #", "# # #   # # #", "# # ##### # #", "# #       # #", "# ######### #", "#           #", "#############" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, draw(Arg0)); }
	void test_case_3() { int Arg0 = 17; string Arr1[] = {"#################", "#               #", "# ############# #", "# #           # #", "# # ######### # #", "# # #       # # #", "# # # ##### # # #", "# # # #   # # # #", "# # # # # # # # #", "# # # #   # # # #", "# # # ##### # # #", "# # #       # # #", "# # ######### # #", "# #           # #", "# ############# #", "#               #", "#################" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, draw(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    Target ___test;
    ___test.run_test(-1);
}
// END CUT HERE
