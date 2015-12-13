// BEGIN CUT HERE

// END CUT HERE
#line 5 "Tdetectived2.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <bitset>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int n = 0;
vector<string> t;
int res = 0,to = 0;

void dfs(int S, int cur) {
    int id = 0,val = -1;

    bitset<8> bit(S);
    cout << bit << " " << cur << " " << t[cur] << endl;

    if(__builtin_popcount(S) == n) {
        return;
    }

    rep(i,n) {
        if(S & (1<<i)) continue;

        if(val < t[cur][i]-'0') {
            val = t[cur][i] - '0';
            id = i;
        }
    }

    rep(i,n) {
        if(val == t[cur][i] - '0') {
            if(i == to) {
                res = __builtin_popcount(S);
                return;
            }
            else if(!(S & (1<<i))) {
                dfs(S | (1<<i), i);
            }
        }
    }

    return;
}

class Tdetectived2 {
	public:
	int reveal(vector <string> s) {
        n = s.size();
        t.clear();
        rep(i,n) t.push_back(s[i]);

        cout << n << endl;
        rep(i,n) {
            cout << s[i] << endl;
        }

        int ans = 0;
        map<int,int> m;

        rep(i,n) {
            to = i;

            rep(j,n) {
                res = 0;
                cout << " ----------------- dfs start ------- to:" << i << " start:" << j << endl;
                dfs(0, j);
                cout << "----- ----- ------- ------ ----- dfs ------- end -----" << endl;
                cout << i << " " << j << ":" << res << endl;
            }
        }
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"000","000","000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, reveal(Arg0)); }
	void test_case_1() { string Arr0[] = {"0224","2011","2104","4140"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(1, Arg1, reveal(Arg0)); }
	void test_case_2() { string Arr0[] = {"0886","8086","8801","6610"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(2, Arg1, reveal(Arg0)); }
	void test_case_3() { string Arr0[] = {"064675511","603525154","430262731","652030511","726302420","552020464","517544052","153126500","141104200"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 170; verify_case(3, Arg1, reveal(Arg0)); }
	void test_case_4() { string Arr0[] = {"0313131","3030020","1301132","3010031","1010003","3233003","1021330"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 37; verify_case(4, Arg1, reveal(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    Tdetectived2 ___test;
    ___test.run_test(0);
}
// END CUT HERE
