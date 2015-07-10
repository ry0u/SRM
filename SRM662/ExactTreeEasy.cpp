// BEGIN CUT HERE

// END CUT HERE
#line 5 "ExactTreeEasy.cpp"
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

class ExactTreeEasy {
	public:
	vector <int> getTree(int n, int m) {
        vector<int> ans;

        ans.push_back(0);
        ans.push_back(1);

        ans.push_back(1);
        ans.push_back(2);

        REP(i,3,n) {
            ans.push_back(1);
            ans.push_back(i);
        }

        int end = ans.size()-2;
        int res = n-1;
        while(res != m) {
            int t = ans[end+1];

            ans[end] = t-1;
            ans[end+1] = t;

            res--;
            end -= 2;
        }

        return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; int Arr2[] = {0, 1, 1, 2, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getTree(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; int Arr2[] = {0, 1, 1, 2, 1, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getTree(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arr2[] = {0, 1, 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getTree(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 3; int Arr2[] = {0, 1, 1, 2, 1, 3, 3, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getTree(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 9; int Arr2[] = {0, 1, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getTree(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ExactTreeEasy ___test;
    ___test.run_test(-1);
   // vector<int> ret = ___test.getTree(10,2);
   // for(int i=0;i<2*10;i+=2) {
   //     cout << "i:" << i << " " << ret[i] << " " << ret[i+1] << endl;
   // }
   //  cout << "~~~~~~~~~~" << endl;
   return 0;
}
// END CUT HERE

