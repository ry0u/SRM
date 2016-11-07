// BEGIN CUT HERE

// END CUT HERE
#line 5 "RoadsAndFools.cpp"

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

class RoadsAndFools {
	public:
	string determineOrientation(int length, vector <int> frontSides) {
		int n = frontSides.size();
		vector<P> v(n);
		rep(i, n) {
			v[i].first = frontSides[i];
			v[i].second = length - frontSides[i];
		}
		rep(i, n) {
			if(v[i].first > v[i].second) swap(v[i].first, v[i].second);
		}

		bool flag = true;
		rep(i, n-1) {
			if(v[i].first < v[i+1].first) continue;
			else if(v[i].first >= v[i+1].first && v[i].first < v[i+1].second) {
				swap(v[i+1].first, v[i+1].second);
			}
			else flag = false;
		}

		if(!flag) return "NO SOLUTION";

		int cnt = 0;
		rep(i, n) {
			if(v[i].first == v[i].second) continue;
			swap(v[i].first, v[i].second);

			bool flag = true;
			rep(j, n-1) {
				if(v[j].first < v[j+1].first) continue;
				flag = false;
			}
			cnt += flag;
			
			swap(v[i].first, v[i].second);
		}

		if(cnt != 0) return "MULTIPLE SOLUTIONS";

		stringstream ss;
		rep(i, n) {
			if(i) ss << " ";
			ss << v[i].first;
		}

		return ss.str();
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1 2 3"; verify_case(0, Arg2, determineOrientation(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {5, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "MULTIPLE SOLUTIONS"; verify_case(1, Arg2, determineOrientation(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1 4"; verify_case(2, Arg2, determineOrientation(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {4, 4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NO SOLUTION"; verify_case(3, Arg2, determineOrientation(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "MULTIPLE SOLUTIONS"; verify_case(4, Arg2, determineOrientation(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 10; int Arr1[] = {5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "5"; verify_case(5, Arg2, determineOrientation(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    RoadsAndFools ___test;

    ___test.run_test(-1);

}

// END CUT HERE
