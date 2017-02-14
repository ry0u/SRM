#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<int(n);i++)
#define rep(i,n) for(int i=0;i<int(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

class EncodedSum {

    public:

    long long maximumSum(vector <string> numbers) {
		vector<vector<int> > s(numbers.size());
		rep(i, numbers.size()) {
			s[i].resize(numbers[i].size());
			rep(j, numbers[i].size()) {
				s[i][j] = int(numbers[i][j] - 'A');
			}
		}

		bool flag[10];
		memset(flag, 0, sizeof(flag));

		vector<ll> x(10);
		rep(i, s.size()) {
			ll t = 1;
			flag[ s[i][0] ] = true;
			for(int j = s[i].size()-1; j >= 0; j--) {
				x[ s[i][j] ] += t;
				t *= 10;
			}
		}

		vector<P> v;
		vector<int> a(10);
		rep(i, 10) {
			v.push_back(P(x[i], i));
			a[i] = 9 - i;
		}

		sort(v.begin(), v.end(), greater<P>());

		ll ans = 0;
		for(int i = v.size()-1; i >= 0; i--) {
			if(flag[ v[i].second ] && a[i] == 0) {
				swap(a[i], a[i-1]);
			}
			ans += v[i].first * a[i];
		}

		return ans;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABC",
 "BCA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1875LL; verify_case(0, Arg1, maximumSum(Arg0)); }
	void test_case_1() { string Arr0[] = {"ABCDEFGHIJ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9876543210LL; verify_case(1, Arg1, maximumSum(Arg0)); }
	void test_case_2() { string Arr0[] = {"ABCDEFGHIJ", 
 "J"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9876543202LL; verify_case(2, Arg1, maximumSum(Arg0)); }
	void test_case_3() { string Arr0[] = {"A", 
 "BB", 
 "CCC", 
 "DDDD", 
 "EEEEE", 
 "FFFFFF", 
 "GGGGGGG", 
 "HHHHHHHH", 
 "IIIIIIIII", 
 "AJJJJJJJJJ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9973936905LL; verify_case(3, Arg1, maximumSum(Arg0)); }
	void test_case_4() { string Arr0[] = {"GHJIDDD",
 "AHHCCCA",
 "IIJCEJ",
 "F",
 "HDBIGFJAAJ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9888114550LL; verify_case(4, Arg1, maximumSum(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    EncodedSum ___test;

    ___test.run_test(-1);

	cout << ___test.maximumSum({"BHJECHGFEJGC", "DDFIHHGHBECI", "DGBIDEEGEFFJ", "DHGABIDEGIIF", "BGBIDDCCBEFD", "DAJJDCGBDEJH", "DHJIABFJGEJB", "BHBHBFDBBEFD", "BFHFEBIBBAGJ", "DDGAIBIEDHAG", "BGBCBBCBJGAD", "DECEJFECHDFI", "DJBCFIJBCCDI", "BHEACAEGHGAB", "DFFCHJEDCIFA", "BBJAEHBBEFDD", "DIAECJIHDGDI", "DAFIFHIJJFIH", "DAJBAFHECFEJ", "BEDFCGAFCGGB", "BGDGJDIBDIEA", "BEEAECAJICBI", "DCACFCHDGBCI", "BIHDHHBACGCE", "BEAGDFBBAGBE", "BDHBADIIJBBF", "DGAFHFFCGFFH", "DICCIIJEJBCH", "DJAFBFJIEHCB", "BGHGDGDCIBDA", "DAEDAGIIDCFJ", "BFFGHBEDGHHC", "DFGEICBDCJJC", "DCIGBCIBBEIC", "DGDEJFFDJIHD", "BBHBJDJABDFC", "BBBHDDEFJIEB", "BAAAFJCBGDIG", "DHIGAICIGJCA", "DGBABDGCIIAF", "DCJBDGBDCJHF", "BBCDCCADFBGC", "BEICJJCGGHGD", "BEACEAEIAEGB", "DBJHJCFEIIGD", "DIJDBEHFJFJE", "DBCEIGDBIDHC", "DFFJGBACCJAC", "BDIBJDEJHFGC", "DBEGGFHCBIEC"}) << endl;
}

// END CUT HERE
