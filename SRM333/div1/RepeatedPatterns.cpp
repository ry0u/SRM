// BEGIN CUT HERE

// END CUT HERE
#line 5 "RepeatedPatterns.cpp"

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

class RepeatedPatterns {
	public:
	long long findZeroSegment(string P1, string P2, string zeroCount) {
		bool az = true, bz = true;
		rep(i, P1.size()) {
			if(P1[i] == '0') continue;
			az = false;
		}

		rep(i, P2.size()) {
			if(P2[i] == '0') continue;
			bz = 0;
		}

		int afront = 0, aback = 0;
		rep(i, P1.size()) {
			if(P1[i] == '0') afront++;
			else break;
		}

		for(int i = P1.size()-1; i >= 0; i--) {
			if(P1[i] == '0') aback++;
			else break;
		}

		int bfront = 0, bback = 0;
		rep(i, P2.size()) {
			if(P2[i] == '0') bfront++;
			else break;
		}

		for(int i = P2.size()-1; i >= 0; i--) {
			if(P2[i] == '0') bback++;
			else break;
		}

		ll zc;
		stringstream ss;
		ss << zeroCount;
		ss >> zc;

		if(az && bz) {
			return 0;
		} else if(az) {
			if(zc <= 1000000 * P1.size() + bfront) {
				return 0;
			} else if(zc <= bback + 1000000 * P1.size() + bfront) {
				return 1000000 * P1.size() + P2.size() - bback;
			} else {
				return -1;
			}
		} else if(bz) {
			if(zc <= afront) {
				return 0;
			} else if(zc <= aback + afront) {
				return P1.size() - aback;
			} else {
				ll cnt = 1;
				ll res = 0;
				while(true) {
					res += P1.size() * 1000000;
					if(res + P2.size() * cnt <= 1e16 && zc <= aback + bfront * cnt) {
						return res - aback;
					}
					if(res + P2.size() * cnt + P1.size() * 1000000 <= 1e16 && zc <= aback + bfront * cnt + afront) {
						return res - aback;
					}
					res += P2.size() * cnt; cnt++;

					if(res >= 1e16) break;
				}
				return -1;
			}
		} else {
			int alen = 0, len = 0, aid = 0;
			for(int i = P1.size()-1; i >= 0; i--) {
				if(P1[i] == '0') {
					len++;
					if(alen <= len) {
						alen = len;
						aid = i;
					}
				} else {
					len = 0;
				}
			}

			len = 0;
			int blen = 0, bid = 0;
			for(int i = P2.size()-1; i >= 0; i--) {
				if(P2[i] == '0') {
					len++;
					if(blen <= len) {
						blen = len;
						bid = i;
					}
				} else {
					len = 0;
				}
			}

			if(zc <= afront) {
				return 0;
			} else if(zc <= alen) {
				return aid;
			} else if(zc <= aback + afront) {
				return P1.size() - aback;
			} else if(zc <= aback + bfront) {
				return P1.size() * 1000000 - aback;
			} else if(zc <= blen) {
				return P1.size() * 1000000 + bid;
			} else if(zc <= bback + afront) {
				return P1.size() * 1000000 + P2.size() - bback;
			} else if(zc <= bback + bfront) {
				return P1.size() * 1000000LL + P2.size() + P1.size() * 1000000 + P2.size() - bback;
			}
			return -1;
		}
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "111010100001010"; string Arg1 = "010000001000"; string Arg2 = "3"; long long Arg3 = 7LL; verify_case(0, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "1101010010"; string Arg1 = "0001000"; string Arg2 = "3"; long long Arg3 = 9999999LL; verify_case(1, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "1101010010"; string Arg1 = "0001000"; string Arg2 = "5"; long long Arg3 = 20000011LL; verify_case(2, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "10101010"; string Arg1 = "101010101010"; string Arg2 = "9876543219876"; long long Arg3 = -1LL; verify_case(3, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "11111111111111111111111111"; string Arg1 = "0"; string Arg2 = "9876543219876"; long long Arg3 = -1LL; verify_case(4, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    RepeatedPatterns ___test;

    ___test.run_test(-1);
	cout << ___test.findZeroSegment("1", "0", "1") << endl; // 1000000
	cout << ___test.findZeroSegment("1", "0", "87654321") << endl; //
	cout << ___test.findZeroSegment("00000000000000000000000000000000000000000000000001", "10000000000000000000000000000000000000000000000000", "98") << endl;
	cout << ___test.findZeroSegment("0", "00000100000", "1000008") << endl; // 1000006
	cout << ___test.findZeroSegment("1", "0", "140424892") << endl;
	cout << ___test.findZeroSegment("00011", "1100", "5") << endl;
}

// END CUT HERE
