// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheNicePair.cpp"
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

bool check(vector<int> v,int size)
{
	int ret = 0;
	REP(i,2,1001)
	{
		int cnt = 0;
		rep(j,v.size())
		{
			if(v[j]%i == 0) cnt++;
		}

		ret = max(ret,cnt);
	}

	if(ret >= size) return true;
	else return false;
}

class TheNicePair {
	public:
	int solve(vector <int> A) {
		int n = A.size();

		int ans = -1;
		rep(i,n)
		{
			REP(j,i,n)
			{
				if(i == j && A[i] != 1)
				{
					ans = max(ans,0);
					continue;
				}

				vector<int> v;
				REP(k,i,j+1) v.push_back(A[k]);

				double size = v.size()/2.0;
				size = ceil(size);

				if(check(v,(int)size))
				{
					ans = max(ans,j-i);
				}
			}
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5,5,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = {2,3,5,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {8,8,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1000,1000,1,1000,1,999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, solve(Arg0)); }
	void test_case_5() { int Arr0[] = {1000,1,1,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(5, Arg1, solve(Arg0)); }
	void test_case_6() { int Arr0[] = {1,1,953,1,1,1,1,1,1,1,1,1,1,1,1,953,1,953,953,1,1,1,1,1,1,1,953,953,953,1,1,1,1,1,953,953,1,1,1,953,953,953,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(6, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TheNicePair ___test;
    ___test.run_test(-1);
}
// END CUT HERE
