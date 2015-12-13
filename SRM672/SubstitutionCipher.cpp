// BEGIN CUT HERE

// END CUT HERE
#line 5 "SubstitutionCipher.cpp"
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

class SubstitutionCipher {
	public:
	string decode(string a, string b, string y) {
        map<char,char> m;
        set<char> A,B;
        rep(i,b.size()) {
            m[b[i]] = a[i];
            A.insert(a[i]);
            B.insert(b[i]);
        }

        if(A.size() == 25 && B.size() == 25) {
            char c;
            rep(i,26) {
                if(A.find('A' + i) == A.end()) {
                    c = 'A' + i;
                    break;
                }
            }

            string ret = "";
            rep(i,y.size()) {
                if(m.count(y[i]) != 0) {
                    ret += m[y[i]];
                } else {
                    ret += c;
                }
            }

            return ret;
        }
        
        string ret = "";
        bool flag = true;
        rep(i,y.size()) {
            if(m.count(y[i]) != 0) {
                ret += m[y[i]];
            } else {
                flag = false;
            }
        }

        if(flag) {
            return ret;
        } else {
            return "";
        }


	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "CAT"; string Arg1 = "DOG"; string Arg2 = "GOD"; string Arg3 = "TAC"; verify_case(0, Arg3, decode(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "BANANA"; string Arg1 = "METETE"; string Arg2 = "TEMP"; string Arg3 = ""; verify_case(1, Arg3, decode(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "THEQUICKBROWNFOXJUMPSOVERTHELAZYHOG"; string Arg1 = "UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZIPH"; string Arg2 = "DIDYOUNOTICESKIPPEDLETTER"; string Arg3 = "CHCXNTMNSHBDRJHOODCKDSSDQ"; verify_case(2, Arg3, decode(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    SubstitutionCipher ___test;
    ___test.run_test(-1);
}
// END CUT HERE
