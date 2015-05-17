// BEGIN CUT HERE

// END CUT HERE
#line 5 "CatsOnTheLineDiv2.cpp"
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

class CatsOnTheLineDiv2 {
	public:
	string getAnswer(vector <int> position, vector <int> count, int time) {
		int cnt[5005];
		int GETA = 2000;
		int N = 0;

		memset(cnt,0,sizeof(cnt));

		int n = position.size();
		rep(i,n)
		{
			cnt[position[i] + GETA] += count[i];
			N += count[i];
		}

		bool can[5005];
		int t[5005];
		memset(can,0,sizeof(can));
		memset(t,0,sizeof(t));
		
		rep(i,n)
		{
			int p = position[i] + GETA;
			REP(j,p-time,p+time+1)
			{
				if(0 <= j && j <= 4000) 
				{
					t[j]++;
				}
			}
		}

		rep(i,n)
		{
			int p = position[i] + GETA;
			REP(j,p-time,p+time+1)
			{
				if(t[j] == 1)
				{
					t[j]--;
					
					if(count[i] > 0)
					{
						count[i]--;
						N--;
					}
				}
			}
		}
		
		int cnt2 = 0;
		string res = "";
		stringstream ss;
		rep(i,4001)
		{
			if(t[i] > 0) cnt2++;
		}

		if(cnt2 >= N) return "Possible";
		else return "Impossible";
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "Possible"; verify_case(0, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; string Arg3 = "Impossible"; verify_case(1, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; string Arg3 = "Impossible"; verify_case(2, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {5, 0, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; string Arg3 = "Impossible"; verify_case(3, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {5, 1, -10, 7, 12, 2, 10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 4, 2, 7, 1, 4, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; string Arg3 = "Possible"; verify_case(4, Arg3, getAnswer(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CatsOnTheLineDiv2 ___test;
    ___test.run_test(-1);

	vector<int> v(2);
	v[0] = -1000;
	v[1] = -999;

	vector<int> v2(2);
	v[0] = 1000;
	v[1] = 1000;

	cout << ___test.getAnswer(v,v2,999) << endl;
}
// END CUT HERE
