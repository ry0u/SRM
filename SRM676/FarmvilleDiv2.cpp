// BEGIN CUT HERE

// END CUT HERE
#line 5 "FarmvilleDiv2.cpp"
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
typedef pair<int,int> P;

class FarmvilleDiv2 {
	public:
	int minTime(vector <int> time, vector <int> cost, int budget) {
		int n = time.size();
		vector<P> v(n);

		rep(i, n) {
			v[i].first = cost[i];
			v[i].second = time[i];
		}

		sort(v.begin(), v.end());

		rep(i, n) {
			while(budget >= v[i].first) {
				budget	-= v[i].first;
				v[i].second--;

				if(v[i].second == 0) break;
			}
		}

		int ans = 0;
		rep(i, n) {
			ans += v[i].second;
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 26; int Arg3 = 74; verify_case(0, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 101; int Arg3 = 0; verify_case(1, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 0; verify_case(2, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 15; int Arg3 = 6; verify_case(3, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {100,100,100,100,100,100,100,100,100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4,6,8,10,1,3,5,7,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5000; int Arg3 = 50; verify_case(4, Arg3, minTime(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {30,40,20,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 100; verify_case(5, Arg3, minTime(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FarmvilleDiv2 ___test;
    ___test.run_test(-1);
}
// END CUT HERE
