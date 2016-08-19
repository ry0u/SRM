// BEGIN CUT HERE

// END CUT HERE
#line 5 "IndicatorMotionReverse.cpp"

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

char f(char a, char b) {
	if(a == '|' && b == 'N') return 'L';
	if(a == 'N' && b == '-') return 'L';
	if(a == '-' && b == '/') return 'L';
	if(a == '/' && b == '|') return 'L';

	if(a == 'N' && b == '|') return 'R';
	if(a == '|' && b == '/') return 'R';
	if(a == '/' && b == '-') return 'R';
	if(a == '-' && b == 'N') return 'R';

	if(a == b) return 'S';

	if(a == '|' && b == '-') return 'F';
	if(a == '-' && b == '|') return 'F';
	if(a == '/' && b == 'N') return 'F';
	if(a == 'N' && b == '/') return 'F';
	return 'E';
}

class IndicatorMotionReverse {
	public:
	string getMinProgram(vector<string> v) {
		int n = v.size();
		char c = v[n-1][v[n-1].size()-1], res = 'Z';

		
		int cnt = 0;
		bool flag = true;
		string ans = "";

		for(int i = n - 1; i >= 0; i--) {
			for(int j = v[i].size()-1; j >= 0; j--) {
				if(i == n-1 && j == v[i].size()-1) continue;
				char nc = v[i][j];
				char x = f(nc, c);

				if(flag) {
					res = x;
					cnt = 1;
					flag = false;
				} else {
					if(res == x) {
						cnt++;
					} else {
						while(cnt >= 100) {
							stringstream ss;
							cnt -= 99;
							ss << res;
							ss << "99";
							ans = ss.str() + ans;
						}

						stringstream ss;
						ss << res;
						if(cnt < 10) {
							ss << '0';
							ss << char('0' + cnt);
						} else {
							ss << char('0' + (cnt/10));
							ss << char('0' + (cnt%10));
						}

						ans = ss.str() + ans;
						cnt = 1;
						res = x;
					}
				}
				c = nc;
			}
		}

		if(cnt != 0) {
			while(cnt >= 100) {
				stringstream ss;
				cnt -= 99;
				ss << res;
				ss << "99";
				ans = ss.str() + ans;
			}

			stringstream ss;
			ss << res;
			if(cnt < 10) {
				ss << '0';
				ss << char('0' + cnt);
			} else {
				ss << char('0' + (cnt/10));
				ss << char('0' + (cnt%10));
			}

			ans = ss.str() + ans;
		}

		if(ans.size() <= 100) return ans;
		else return ans.substr(0, 97) + "...";
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"-|-|/-/|//////-/"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "F03R02L02R01S05R01L01"; verify_case(0, Arg1, getMinProgram(Arg0)); }
	void test_case_1() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(1, Arg1, getMinProgram(Arg0)); }
	void test_case_2() { string Arr0[] = {"||||||||||||||||||||||||||||||||||||||||||||||||||",
 "||||||||||||||||||||||||||||||||||||||||||||||||||",
 "||||||||||||||||||||||||||||||||||||||||||||||||||"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "S50S99"; verify_case(2, Arg1, getMinProgram(Arg0)); }
	void test_case_3() { string Arr0[] = {"N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
 "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L..."; verify_case(3, Arg1, getMinProgram(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    IndicatorMotionReverse ___test;

    ___test.run_test(-1);

}

// END CUT HERE
