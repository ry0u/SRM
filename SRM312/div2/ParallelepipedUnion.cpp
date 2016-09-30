#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

vector<string> split(const string &str, char delim) {
	vector<string> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos) {
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}

bool flag[105][105][105];

class ParallelepipedUnion {

    public:

    int getVolume(vector <string> parallelepipeds) {
		vector<string> a = split(parallelepipeds[0], ' ');
		vector<string> b = split(parallelepipeds[1], ' ');

		int n = a.size();
		vector<int> v1(n), v2(n);
		rep(i, n) {
			int x;
			stringstream ss;
			ss << a[i];
			ss >> x;
			v1[i] = x;
		}

		rep(i, n) {
			int x;
			stringstream ss;
			ss << b[i];
			ss >> x;
			v2[i] = x;
		}

		memset(flag, 0, sizeof(flag));

		REP(i, v1[0], v1[3]) {
			REP(j, v1[1], v1[4]) {
				REP(k, v1[2], v1[5]) {
					flag[i][j][k] = true;
				}
			}
		}

		REP(i, v2[0], v2[3]) {
			REP(j, v2[1], v2[4]) {
				REP(k, v2[2], v2[5]) {
					flag[i][j][k] = true;
				}
			}
		}

		int cnt = 0;
		rep(i, 105) {
			rep(j, 105) {
				rep(k, 105) {
					cnt += flag[i][j][k];
				}
			}
		}

		return cnt;

    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 1 1 4 4 2", "3 2 1 5 3 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(0, Arg1, getVolume(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 1 1 2 2 2", "3 3 3 4 4 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, getVolume(Arg0)); }
	void test_case_2() { string Arr0[] = {"1 10 20 5 15 23", "2 12 22 3 14 23"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(2, Arg1, getVolume(Arg0)); }
	void test_case_3() { string Arr0[] = {"28 31 21 67 60 81","60 1 21 67 50 81"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 80460; verify_case(3, Arg1, getVolume(Arg0)); }
	void test_case_4() { string Arr0[] = {"34 3 50 37 6 53","36 1 51 38 4 55"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; verify_case(4, Arg1, getVolume(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    ParallelepipedUnion ___test;

    ___test.run_test(-1);

}

// END CUT HERE
