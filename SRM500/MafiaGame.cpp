// BEGIN CUT HERE

// END CUT HERE
#line 5 "MafiaGame.cpp"
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

class MafiaGame {
	public:
	double probabilityToLose(int N, vector <int> decisions) {
        vector<int> v(decisions.begin(),decisions.end());
        int cnt[505];
        memset(cnt,0,sizeof(cnt));

        rep(i,v.size()) {
            cnt[v[i]]++;
        }
        int vmax = 0;
        rep(i,N) {
            vmax = max(vmax,cnt[i]);
        }

        if(vmax == 1) return 0.0;

        int c = 0;
        rep(i,N) {
            if(cnt[i] == vmax) c++;
        }

        if(c == 1) return 1.0;

        double ans = 1.0/c;
        while(c != 1) {
            if(N%c == 0) return 0.0;
            c = N%c;
        }
        return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, probabilityToLose(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(1, Arg2, probabilityToLose(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 20; int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 18, 19, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, probabilityToLose(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 23; int Arr1[] = {17, 10, 3, 14, 22, 5, 11, 10, 22, 3, 14, 5, 11, 17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.14285714285714285; verify_case(3, Arg2, probabilityToLose(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MafiaGame ___test;
    ___test.run_test(-1);
    int n = 11;
    vector<int> v(1);

    cout << ___test.probabilityToLose(n,v) << endl;
}
// END CUT HERE
