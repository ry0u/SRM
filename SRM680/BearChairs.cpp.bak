// BEGIN CUT HERE

// END CUT HERE
#line 5 "BearChairs.cpp"
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

class BearChairs {
	public:
	vector <int> findPositions(vector <int> atLeast, int d) {
		int n = atLeast.size();
		vector<int> ans, v;

		rep(i, n) {
			int t = atLeast[i];
			if(v.size() == 0) {
				v.push_back(t);
				ans.push_back(t);
			} else {
				bool flag = true;

				if(v[0] - t >= d) {
					v.push_back(t);
					ans.push_back(t);
					sort(v.begin(), v.end());
					flag = false;
				}

				if(flag) {
					rep(j, v.size()-1) {
						if(v[j+1] - v[j] >= 2*d) {
							if(t <= v[j]) {
								flag = false;
								v.push_back(v[j] + d);
								ans.push_back(v[j] + d);
								sort(v.begin(), v.end());
								break;
							} else if(max(v[j] + d, t) <= v[j+1] - d) {
								flag = false;
								v.push_back(max(v[j]+d, t));
								ans.push_back(max(v[j]+d, t));
								sort(v.begin(), v.end());
								break;
							}
						}
					}
				}

				if(flag) {
					int last = v[v.size()-1];
					int a = max(last + d, t);
					v.push_back(a);
					ans.push_back(a);
				}
			}
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,21,11,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arr2[] = {1, 21, 11, 31 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findPositions(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,21,11,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; int Arr2[] = {1, 21, 32, 43 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, findPositions(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1000000,1000000,1000000,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000; int Arr2[] = {1000000, 2000000, 3000000, 4000000 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, findPositions(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1000000,1000000,1000000,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999999; int Arr2[] = {1000000, 1999999, 2999998, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, findPositions(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    BearChairs ___test;
    ___test.run_test(-1);

	vector<int> v = {250, 135, 150, 150, 97, 263, 182, 246, 258, 190, 145, 253, 119, 142, 98, 132, 136, 229, 159, 137, 238, 231, 189, 264, 133, 224, 229, 147, 181, 162, 265, 162, 201, 98, 216, 202, 218, 254, 132, 207, 175, 133, 192, 151};

	int t = 10;

	vector<int> v2 = {104, 120, 213, 132, 177, 255, 216, 155, 99, 146, 108, 94, 214, 200, 210, 221, 229, 224, 191, 215, 129, 101, 121, 146, 163, 198, 115, 89, 98, 206, 172, 212, 146, 113, 263, 242, 97, 109, 217, 206, 173, 243, 219, 115, 172, 249, 156, 221, 202, 265, 256, 151, 187, 197, 215, 170};

	int t2 = 11;


	vector<int> ret = ___test.findPositions(v2, t2);
	rep(i, v2.size()) cout << v2[i] << " ";
	cout << endl;

	rep(i, ret.size()) cout << ret[i] << " ";
	cout << endl;

	vector<int> ans = {104, 120, 213, 132, 177, 255, 224, 155, 143, 166, 188, 199, 235, 266, 277, 288, 299, 310, 321, 332, 343, 354, 365, 376, 387, 398, 409, 89, 420, 431, 442, 453, 464, 475, 486, 497, 508, 519, 530, 541, 552, 563, 574, 585, 596, 607, 618, 629, 640, 651, 662, 673, 684, 695, 706, 717};

	rep(i, ans.size()) cout << ans[i] << " ";
	cout << endl;
	
	
	//{250, 135, 150, 260, 97, 270, 182, 280, 290, 300, 310, 320, 119, 330, 340, 350, 360, 229, 370, 380, 390, 400, 410, 420, 430, 440, 450, 460, 470, 162, 480, 490, 201, 500, 216, 510, 520, 530, 540, 550,
}
// END CUT HERE
