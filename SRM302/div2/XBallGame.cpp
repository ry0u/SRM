// BEGIN CUT HERE

// END CUT HERE
#line 5 "XBallGame.cpp"

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

class XBallGame {
	public:
	vector <string> newStatistics(vector <string> v) {
		int n = v.size();

		vector<string> name(n), op(n);
		map<string, set<string> > m;

		rep(i, n) {
			vector<string> ret = split(v[i], '-');

			name[i] = ret[0];
			op[i] = ret[1];
			m[name[i]].insert(op[i]);
		}

		vector<string> ret(n);
		rep(i, n) {
			ret[i] = v[i];

			each(it, m[name[i]]) {
				if(*it == op[i]) continue;
				ret[i] += ',';
				ret[i] += *it;
			}
		}

		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"John-DH", 
 "Jack-SP", 
 "Sam-OF", 
 "John-SP", 
 "John-RP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"John-DH,RP,SP", "Jack-SP", "Sam-OF", "John-SP,DH,RP", "John-RP,DH,SP" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, newStatistics(Arg0)); }
	void test_case_1() { string Arr0[] = {"John-DH", 
 "Jack-SP", 
 "Sam-OF", 
 "John-SP", 
 "John-RP", 
 "John-RA", 
 "John-RZ", 
 "Jack-OF", 
 "Sam-SP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"John-DH,RA,RP,RZ,SP", "Jack-SP,OF", "Sam-OF,SP", "John-SP,DH,RA,RP,RZ", "John-RP,DH,RA,RZ,SP", "John-RA,DH,RP,RZ,SP", "John-RZ,DH,RA,RP,SP", "Jack-OF,SP", "Sam-SP,OF" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, newStatistics(Arg0)); }
	void test_case_2() { string Arr0[] = {"PFwL-GE", "PFwL-EV","agXL-SR", "PFwL-CS", "PFwL-FE", "PFwL-MS", "agXL-VS", "agXL-AL", "PFwL-BI", "PFwL-DK", 
 "PFwL-MW", "PFwL-DS", "agXL-XJ", "agXL-PJ", "agXL-CK", "PFwL-KI", "agXL-KP", "agXL-EL", "PFwL-EA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"PFwL-GE,BI,CS,DK,DS,EA,EV,FE,KI,MS,MW", "PFwL-EV,BI,CS,DK,DS,EA,FE,GE,KI,MS,MW", "agXL-SR,AL,CK,EL,KP,PJ,VS,XJ", "PFwL-CS,BI,DK,DS,EA,EV,FE,GE,KI,MS,MW", "PFwL-FE,BI,CS,DK,DS,EA,EV,GE,KI,MS,MW", "PFwL-MS,BI,CS,DK,DS,EA,EV,FE,GE,KI,MW", "agXL-VS,AL,CK,EL,KP,PJ,SR,XJ", "agXL-AL,CK,EL,KP,PJ,SR,VS,XJ", "PFwL-BI,CS,DK,DS,EA,EV,FE,GE,KI,MS,MW", "PFwL-DK,BI,CS,DS,EA,EV,FE,GE,KI,MS,MW", "PFwL-MW,BI,CS,DK,DS,EA,EV,FE,GE,KI,MS", "PFwL-DS,BI,CS,DK,EA,EV,FE,GE,KI,MS,MW", "agXL-XJ,AL,CK,EL,KP,PJ,SR,VS", "agXL-PJ,AL,CK,EL,KP,SR,VS,XJ", "agXL-CK,AL,EL,KP,PJ,SR,VS,XJ", "PFwL-KI,BI,CS,DK,DS,EA,EV,FE,GE,MS,MW", "agXL-KP,AL,CK,EL,PJ,SR,VS,XJ", "agXL-EL,AL,CK,KP,PJ,SR,VS,XJ", "PFwL-EA,BI,CS,DK,DS,EV,FE,GE,KI,MS,MW" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, newStatistics(Arg0)); }
	void test_case_3() { string Arr0[] = {"a-AA", "a-ZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a-AA,ZZ", "a-ZZ,AA" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, newStatistics(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    XBallGame ___test;

    ___test.run_test(-1);

}

// END CUT HERE
