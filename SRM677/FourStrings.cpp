// BEGIN CUT HERE

// END CUT HERE
#line 5 "FourStrings.cpp"
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

class FourStrings {
	public:
	int shortestLength(string a, string b, string c, string d) {
		vector<string> v(4);
		v[0] = a, v[1] = b, v[2] = c, v[3] = d;
		sort(v.begin(), v.end());
		int ans = 55;

		do {
			string s = "";

			rep(i, 4) {
				int t = 0, x = 0;

				if(s.size() <= v[i].size()) {
					t = 0;
					x = 0;
					while(true) {
						bool flag = true;
						x = t;
						REP(j, t, s.size()) {
							if(s[j] == v[i][j-x]) continue;
							else {
								flag = false;
								break;
							}
						}

						if(flag) break;
						t++;
					}

				} else {
					bool ch = false;
					rep(j, s.size()) {
						bool ch2 = true;
						rep(k, v[i].size()) {
							if(j + k >= s.size()) {
								ch2 = false;
								break;
							}

							if(s[j+k] == v[i][k]) continue;
							ch2 = false;
							break;
						}

						if(ch2) {
							ch = true;
						}
					}

					if(ch) {
						continue;
					}

					t = s.size() - v[i].size();
					while(true) {
						bool flag = true;
						x = t;
						REP(j, t, s.size()) {
							if(s[j] == v[i][j-x]) continue;
							else {
								flag = false;
								break;
							}
						}

						if(flag) break;
						t++;
					}
				}

				stringstream ss;
				ss << s;

				if(t == s.size()) {
					ss << v[i];
					s = ss.str();
				} else {
					int y = 0;
					REP(j, t, s.size()) {
						y++;
					}

					REP(j, y, v[i].size()) {
						ss << v[i][j];
					}

					s = ss.str();
				}

			}

			// rep(i, 4) {
			// 	cout << v[i] << " ";
			// }
			//
			// cout << " -> " << s << endl;

			ans = min(ans, (int)s.size());
		} while(next_permutation(v.begin(), v.end()));

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abc"; string Arg1 = "ab"; string Arg2 = "bc"; string Arg3 = "b"; int Arg4 = 3; verify_case(0, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arg0 = "a"; string Arg1 = "bc"; string Arg2 = "def"; string Arg3 = "ghij"; int Arg4 = 10; verify_case(1, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arg0 = "top"; string Arg1 = "coder"; string Arg2 = "opco"; string Arg3 = "pcode"; int Arg4 = 8; verify_case(2, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arg0 = "thereare"; string Arg1 = "arelots"; string Arg2 = "lotsof"; string Arg3 = "ofcases"; int Arg4 = 19; verify_case(3, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arg0 = "aba"; string Arg1 = "b"; string Arg2 = "b"; string Arg3 = "b"; int Arg4 = 3; verify_case(4, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arg0 = "x"; string Arg1 = "x"; string Arg2 = "x"; string Arg3 = "x"; int Arg4 = 1; verify_case(5, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FourStrings ___test;
    ___test.run_test(-1);

	// cout << ___test.shortestLength("b", "ab", "abc", "bc") << endl;
}
// END CUT HERE
