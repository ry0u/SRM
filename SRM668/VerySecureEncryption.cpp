// BEGIN CUT HERE

// END CUT HERE
#line 5 "VerySecureEncryption.cpp"
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

class VerySecureEncryption {
	public:
	string encrypt(string s, vector <int> key, int K) {
        int n = s.size();

        rep(i,K) {
            string ret = s;

            rep(j,n) {
                ret[ key[j] ] = s[j];
            }

            s = ret;
        }

        return s;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abc"; int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; string Arg3 = "cab"; verify_case(0, Arg3, encrypt(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "abcde"; int Arr1[] = {4, 3, 2, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; string Arg3 = "edcba"; verify_case(1, Arg3, encrypt(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "abcde"; int Arr1[] = {4, 3, 2, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; string Arg3 = "abcde"; verify_case(2, Arg3, encrypt(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "uogcodlk"; int Arr1[] = {4, 3, 6, 2, 5, 1, 0, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 44; string Arg3 = "goodluck"; verify_case(3, Arg3, encrypt(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    VerySecureEncryption ___test;
    ___test.run_test(-1);
}
// END CUT HERE
