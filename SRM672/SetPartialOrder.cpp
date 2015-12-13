// BEGIN CUT HERE

// END CUT HERE
#line 5 "SetPartialOrder.cpp"
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

class SetPartialOrder {
	public:
	string compareSets(vector <int> a, vector <int> b) {
        int n = a.size();
        int m = b.size();

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        set<int> A;
        rep(i,n) {
            A.insert(a[i]);
        }

        set<int> B;
        rep(i,m) {
            B.insert(b[i]);
        }

        if(n == m) {
            bool flag = true;
            rep(i,n) {
                if(a[i] != b[i]) flag = false;
            }

            if(flag) return "EQUAL";
        } else {
            bool flag = true;
            rep(i,n) {
                if(B.find(a[i]) == B.end()) flag = false;
            }

            if(flag) {
                return "LESS";
            }

            flag = true;
            rep(i,m) {
                if(A.find(b[i]) == A.end()) flag = false;
            }

            if(flag) {
                return "GREATER";
            }

            return "INCOMPARABLE";
        }

        return "INCOMPARABLE";
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 5, 1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "EQUAL"; verify_case(0, Arg2, compareSets(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2, 3, 5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "LESS"; verify_case(1, Arg2, compareSets(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2, 4, 6, 8, 10, 12, 14, 16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 4, 8, 16}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "GREATER"; verify_case(2, Arg2, compareSets(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {42, 23, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {15, 23, 31}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "INCOMPARABLE"; verify_case(3, Arg2, compareSets(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    SetPartialOrder ___test;
    ___test.run_test(-1);
}
// END CUT HERE
