// BEGIN CUT HERE

// END CUT HERE
#line 5 "MoveStonesEasy.cpp"
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

class MoveStonesEasy {
	public:
	int get(vector <int> a, vector <int> b) {
		int n = a.size();

		ll ans = 0;
		ll asum = 0, bsum = 0;

		rep(i, n) asum += a[i];
		rep(i, n) bsum += b[i];

		if(asum != bsum) return -1;

		rep(i, n) {
			if(a[i] == b[i]) continue;
			if(a[i] > b[i]) {
				a[i+1] += a[i] - b[i];
				ans += a[i] - b[i];
			} else {
				int len = 1, j = i+1;
				while(a[i] < b[i]) {
					int d = b[i] - a[i];
					if(a[j] >= d) {
						a[j] -= d;
						a[i] += d;
						ans += d * len;
					} else {
						a[i] += a[j];
						ans += a[j] * len;
						a[j] = 0;
						j++;
						len++;
					}
				}
			}
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, get(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(1, Arg2, get(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, get(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {12, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {12, 12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, get(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(4, Arg2, get(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {3,10,0,4,0,0,0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,5,0,7,0,0,0,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(5, Arg2, get(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MoveStonesEasy ___test;
    ___test.run_test(-1);
}
// END CUT HERE
