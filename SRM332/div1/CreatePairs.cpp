// BEGIN CUT HERE

// END CUT HERE
#line 5 "CreatePairs.cpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

class CreatePairs {
	public:
	int maximalSum(vector <int> data) {
		int cnt = 0;
		ll sum = 0;
		priority_queue<int> up;
		priority_queue<int, vector<int>, greater<int> > down;
		rep(i, data.size()) {
			if(data[i] == 0) cnt++;
			if(data[i] == 1) {
				sum++;
				continue;
			}

			if(data[i] < 0) down.push(data[i]);
			if(0 < data[i]) up.push(data[i]);
		}

		while(up.size()) {
			if(up.size() >= 2) {
				int a = up.top(); up.pop();
				int b = up.top(); up.pop();

				sum += a * b;
			} else {
				sum += up.top(); up.pop();
			}
		}

		while(down.size()) {
			if(down.size() >= 2) {
				int a = down.top(); down.pop();
				int b = down.top(); down.pop();

				sum += a * b;
			} else {
				int a = down.top(); down.pop();
				if(cnt) cnt--;
				else sum += a;
			}
		}

		return sum;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 2, 4, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; verify_case(0, Arg1, maximalSum(Arg0)); }
	void test_case_1() { int Arr0[] = {-1, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, maximalSum(Arg0)); }
	void test_case_2() { int Arr0[] = {-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, maximalSum(Arg0)); }
	void test_case_3() { int Arr0[] = {-1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, maximalSum(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, maximalSum(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    CreatePairs ___test;

    ___test.run_test(-1);

}

// END CUT HERE
