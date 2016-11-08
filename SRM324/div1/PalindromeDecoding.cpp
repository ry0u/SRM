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

class PalindromeDecoding {

    public:

    string decode(string code, vector <int> position, vector <int> length) {
		int m = position.size();

		rep(i, m) {
			string a = code.substr(0, position[i]);
			string b = code.substr(position[i], length[i]);
			string c = code.substr(position[i] + length[i]);
			string d = b;
			reverse(d.begin(), d.end());

			code = a + b + d + c;
		}
		return code;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ab"; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "abba"; verify_case(0, Arg3, decode(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "Misip"; int Arr1[] = {2,3,1,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Mississippi"; verify_case(1, Arg3, decode(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "XY"; int Arr1[] = {0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 4, 8, 16}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "XYYXXYYXXYYXXYYXXYYXXYYXXYYXXYYX"; verify_case(2, Arg3, decode(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "TC206"; int Arr1[] = {1,2,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "TCCC2006"; verify_case(3, Arg3, decode(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "nodecoding"; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "nodecoding"; verify_case(4, Arg3, decode(Arg0, Arg1, Arg2)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    PalindromeDecoding ___test;

    ___test.run_test(-1);

}

// END CUT HERE
