// BEGIN CUT HERE

// END CUT HERE
#line 5 "TrainRobber.cpp"

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
typedef pair<double, int> P;

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

class TrainRobber {
	public:
	double finalPosition(int length, int nCarriages, vector <string> offset, vector <string> period, int trainSpeed, int robberSpeed, int nBridges) {
		vector<double> off, per;
		rep(i, offset.size()) {
			vector<string> ret = split(offset[i], ' ');
			rep(j, ret.size()) {
				double x;
				stringstream ss(ret[j]);
				ss >> x;
				off.push_back(x);
			}
		}

		rep(i, period.size()) {
			vector<string> ret = split(period[i], ' ');
			rep(j, ret.size()) {
				double x;
				stringstream ss(ret[j]);
				ss >> x;
				per.push_back(x);
			}
		}

		priority_queue<P, vector<P>, greater<P> > que;
		rep(i, off.size()) {
			que.push(mp(off[i], i));
		}

		int cnt = 0;
		double cur = 0;

		rep(i, nBridges) {
			P p = que.top(); que.pop();
			double next = p.first;
			int id = p.second;

			// double s = (next - cur) / (robberSpeed + trainSpeed);
			// double t = (double)length / robberSpeed;
			// int tmp = s / t;
			int tmp = ll(next - cur)  * robberSpeed / (length * ll(robberSpeed + trainSpeed));
			if(cnt + tmp >= nCarriages) {
				double len = (nCarriages - cnt) * length;
				return cur + len / robberSpeed * (robberSpeed + trainSpeed);
			}

			cur = next;
			cnt += tmp;
			que.push(mp(next + per[id], id));
		}

		return cur;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 4; string Arr2[] = {"3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"4", "2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; int Arg5 = 1; int Arg6 = 100; double Arg7 = 14.0; verify_case(0, Arg7, finalPosition(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 4; string Arr2[] = {"3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"4 2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; int Arg5 = 1; int Arg6 = 1; double Arg7 = 3.0; verify_case(1, Arg7, finalPosition(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 10; string Arr2[] = {"8 23"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"15 13"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 10; int Arg5 = 10; int Arg6 = 10; double Arg7 = 75.0; verify_case(2, Arg7, finalPosition(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 100; string Arr2[] = {"1 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"1 1"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 100; int Arg5 = 100; int Arg6 = 100; double Arg7 = 50.0; verify_case(3, Arg7, finalPosition(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1000000; string Arr2[] = {"10", "15 63"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"23 42 11"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 10; int Arg5 = 1000; int Arg6 = 1000; double Arg7 = 6355.0; verify_case(4, Arg7, finalPosition(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    TrainRobber ___test;

    ___test.run_test(-1);

	cout << fixed;
	cout.precision(10);
	cout << ___test.finalPosition(1, 1, {"3 4"}, {"4 2"}, 1, 1, 8) << endl;
	cout << ___test.finalPosition(49, 29, {"516"}, {"4492"}, 20, 62, 55) << endl;
	cout << ___test.finalPosition(1, 959375, {"1000000"}, {"1000000"}, 40027, 945253, 2) << endl;
	cout << ___test.finalPosition(500000, 1, {"1000000"}, {"1000000"}, 59049, 59049, 2) << endl;

}

// END CUT HERE
