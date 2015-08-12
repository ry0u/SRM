// BEGIN CUT HERE

// END CUT HERE
#line 5 "LuckySum.cpp"
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

vector<string> v;

ll func(string a, string b) {
    stringstream ss,ss1;
    ll s,t;

    ss << a;
    ss >> s;

    ss1 << b;
    ss1 >> t;

    return s+t;
}

class LuckySum {
	public:
	long long construct(string note) {

        v.clear();
        REP(i,1,note.size()+1) {

            rep(j,1<<i) {
                bitset<14> bit(j);

                string s = "";
                rep(k,i) s += " ";

                rep(k,i) {
                    if(bit[k] == 0) {
                        s[k] = '4';
                    }
                    else {
                        s[k] = '7';
                    }
                }
                v.push_back(s);
            }
        }

        vector<ll> t;
        rep(i,v.size()) {
            rep(j,v.size()) {
                t.push_back(func(v[i],v[j]));
            }
        }

        cout << t.size() << endl;
        
        sort(t.begin(),t.end());

        rep(i,v.size()) {
            rep(j,v.size()) {
                ll res = func(v[i],v[j]);

                stringstream ret;
                ret << res;
                string s = ret.str();

                if(s.size() != note.size()) continue;

                bool flag = true;
                rep(k,note.size()) {
                    if(note[k] == '?') continue;
                    if(s[k] == note[k]) continue;
                    flag = false;
                }

                if(flag) return res;
            }
        }

        return -1;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "?"; long long Arg1 = 8LL; verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { string Arg0 = "?1"; long long Arg1 = 11LL; verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { string Arg0 = "4?8"; long long Arg1 = 448LL; verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { string Arg0 = "2??"; long long Arg1 = -1LL; verify_case(3, Arg1, construct(Arg0)); }
	void test_case_4() { string Arg0 = "??????????????"; long long Arg1 = 11888888888888LL; verify_case(4, Arg1, construct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    LuckySum ___test;
    ___test.run_test(-1);
}
// END CUT HERE
