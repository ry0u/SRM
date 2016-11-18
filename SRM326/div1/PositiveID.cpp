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

class PositiveID {

    public:

    int maximumFacts(vector <string> suspects) {
		int n = suspects.size();

		vector<set<string> > v(n);
		rep(i, n) {
			vector<string> ret = split(suspects[i], ',');
			rep(j, ret.size()) {
				v[i].insert(ret[j]);
			}
		}

		int ans = 0;
		rep(i, n) {
			REP(j, i+1, n) {
				int cnt = 0;
				each(it, v[i]) {
					if(v[j].find(*it) != v[j].end()) {
						cnt++;
					}
				}

				ans = max(ans, cnt);
			}
		}

		return ans;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"blond,tall,skinny",
"short,skinny,blond,tattooed",
"scarred,bald"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, maximumFacts(Arg0)); }
	void test_case_1() { string Arr0[] = {"gigantic,fluorescent,loud,male"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, maximumFacts(Arg0)); }
	void test_case_2() { string Arr0[] = {"medium,average,nondescript",
"medium,average,nondescript"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, maximumFacts(Arg0)); }
	void test_case_3() { string Arr0[] = {"big,tall,loud,happy,male,scarred,tattooed,dirty",
"short,male,beard,quiet,happy,tanned,handsome",
"female,pretty,blond,quiet",
"somnambulistic",
"happy,tiny,stout,male,tanned,beard,blond"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, maximumFacts(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    PositiveID ___test;

    ___test.run_test(-1);

}

// END CUT HERE
