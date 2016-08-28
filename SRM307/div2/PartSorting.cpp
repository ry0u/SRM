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

bool used[1000005];

class PartSorting {

    public:

    vector <int> process(vector <int> data, int nSwaps) {
		int n = data.size();
		vector<int> v = data;
		sort(v.begin(), v.end());

		memset(used, 0, sizeof(used));

		int id = 0;
		while(nSwaps) {
			for(int i = n - 1; i >= 0; i--) {
				if(used[v[i]]) continue;
				int len = 0;
				REP(j, id, n) {
					if(data[j] == v[i]) break;
					len++;
				}

				if(len <= nSwaps) {
					for(int j = len - 1; j >= 0; j--) {
						swap(data[id+j], data[id+j+1]);
					}
					nSwaps -= len;
					used[v[i]] = true;
					id++;
					break;
				} else continue;
			}

			bool flag = true;
			rep(i, n) {
				if(used[v[i]]) continue;
				flag = false;
			}

			if(flag) break;
		}

		return data;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {10, 20, 30, 40, 50, 60, 70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arr2[] = {20, 10, 30, 40, 50, 60, 70 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, process(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3, 5, 1, 2, 4}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = {5, 3, 2, 1, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, process(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {19, 20, 17, 18, 15, 16, 13, 14, 11, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arr2[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, process(Arg0, Arg1)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    PartSorting ___test;

    ___test.run_test(-1);

}

// END CUT HERE
