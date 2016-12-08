// BEGIN CUT HERE

// END CUT HERE
#line 5 "RailroadSeatNumeration.cpp"

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

string f(int x) {
	stringstream ss;
	ss << (x - 1) / 4 + 1;

	if(x % 4 == 1) ss << 1;
	if(x % 4 == 2) ss << 3;
	if(x % 4 == 3) ss << 4;
	if(x % 4 == 0) ss << 6;

	return ss.str();
}

class RailroadSeatNumeration {
	public:
	string getInternational(vector <int> tickets) {
		int n = tickets.size();

		bool a = true;
		rep(i, n) {
			int x = tickets[i];
			if(1 <= x && x <= 36) continue;
			else a = false;
		}

		bool b = true;
		rep(i, n) {
			int x = tickets[i];
			if(1 <= (x / 10) && (x / 10) <= 9 && (x % 10 == 1 || x % 10 == 3 || x % 10 == 4 || x % 10 == 6)) continue;
			else b = false;
		}

		if(a && b) return "AMBIGUOUS";
		if(!a && !b) return "BAD DATA";

		string ans = "";
		if(a) {
			rep(i, n) {
				if(i) ans += " ";
				ans += f(tickets[i]);
			}
		}

		if(b) {
			rep(i, n) {
				if(i) ans += " ";
				stringstream ss;
				ss << tickets[i];
				ans += ss.str();
			}
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "11"; verify_case(0, Arg1, getInternational(Arg0)); }
	void test_case_1() { int Arr0[] = {11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AMBIGUOUS"; verify_case(1, Arg1, getInternational(Arg0)); }
	void test_case_2() { int Arr0[] = {45}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BAD DATA"; verify_case(2, Arg1, getInternational(Arg0)); }
	void test_case_3() { int Arr0[] = {5, 7, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "21 24 23"; verify_case(3, Arg1, getInternational(Arg0)); }
	void test_case_4() { int Arr0[] = {21, 24, 23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AMBIGUOUS"; verify_case(4, Arg1, getInternational(Arg0)); }
	void test_case_5() { int Arr0[] = {8, 28}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "26 76"; verify_case(5, Arg1, getInternational(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    RailroadSeatNumeration ___test;

    ___test.run_test(-1);
	cout << ___test.getInternational({44}) << endl;
	cout << ___test.getInternational({36, 3, 19, 20, 5}) << endl;
}

// END CUT HERE
