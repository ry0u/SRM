// BEGIN CUT HERE

// END CUT HERE
#line 5 "MovingAvg.cpp"

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

class MovingAvg {
	public:
	double difference(int k, vector <double> data) {
		int n = data.size();
		vector<double> v;

		rep(i, n - k + 1) {
			double sum = 0;
			rep(j, k) sum += data[i + j];
			v.push_back(sum / k);
		}

		double vmin = v[0], vmax = v[0];
		rep(i, v.size()) {
			vmin = min(vmin, v[i]);
			vmax = max(vmax, v[i]);
		}

		return vmax - vmin;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; double Arr1[] = {3,8,9,15}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.5; verify_case(0, Arg2, difference(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; double Arr1[] = {17,6.2,19,3.4}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 4.533333333333335; verify_case(1, Arg2, difference(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; double Arr1[] = {6,2.5,3.5}; vector <double> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(2, Arg2, difference(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    MovingAvg ___test;

    ___test.run_test(-1);

}

// END CUT HERE
