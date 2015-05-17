// BEGIN CUT HERE

// END CUT HERE
#line 5 "MutaliskEasy.cpp"
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
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;

int ans = INF;
int memo[100][100][100] = {0};
vector<vector<int> > K(6);

bool check(int a,int b,int c)
{
	vector<int> v(3);
	v[0] = a;
	v[1] = b;
	v[2] = c;

	bool flag = true;
	rep(i,v.size())
	{
		if(v[i] > 0) flag = false;
	}

	return flag;
}

void dfs(int a,int b,int c,int cnt)
{
	if(a < 0) a = 0;
	if(b < 0) b = 0;
	if(c < 0) c = 0;
	
	if(memo[a][b][c] <= cnt) return;
	memo[a][b][c] = cnt;

	vector<int> v(3);
	v[0] = a;
	v[1] = b;
	v[2] = c;
	
	sort(v.begin(),v.end(),greater<int>());
	a = v[0];
	b = v[1];
	c = v[2];
	
	if(check(a,b,c))
	{
		ans = min(ans,cnt);
		return;
	}

	rep(i,6)
	{
		dfs(a-K[i][0],b-K[i][1],c-K[i][2],cnt+1);
	}
}

class MutaliskEasy {
	public:
	int minimalAttacks(vector <int> x) {

		rep(i,6) K[i].resize(3);
		K[0][0] = 9,K[0][1] = 3,K[0][2] = 1;
		K[1][0] = 9,K[1][1] = 1,K[1][2] = 3;
		K[2][0] = 3,K[2][1] = 9,K[2][2] = 1;
		K[3][0] = 3,K[3][1] = 1,K[3][2] = 9;
		K[4][0] = 1,K[4][1] = 9,K[4][2] = 3;
		K[5][0] = 1,K[5][1] = 3,K[5][2] = 9;


		int n = x.size();
		sort(x.begin(),x.end(),greater<int>());
		ans = INF;

		rep(i,100) rep(j,100) rep(k,100) memo[i][j][k] = INF;

		queue<pair<vector<int>,int> > que;
		vector<int> v(3);

		if(n == 1)
		{
			dfs(x[0],0,0,0);
			v[0] = x[0];
			v[1] = 0;
			v[2] = 0;
		}
		if(n == 2)
		{
			dfs(x[0],x[1],0,0);
			v[0] = x[0];
			v[1] = x[1];
			v[2] = 0;
		}
		if(n == 3)
		{
			dfs(x[0],x[1],x[2],0);
			v[0] = x[0];
			v[1] = x[1];
			v[2] = x[2];
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {12,10,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimalAttacks(Arg0)); }
	void test_case_1() { int Arr0[] = {54,18,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, minimalAttacks(Arg0)); }
	void test_case_2() { int Arr0[] = {55,60,53}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(2, Arg1, minimalAttacks(Arg0)); }
	void test_case_3() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, minimalAttacks(Arg0)); }
	void test_case_4() { int Arr0[] = {60, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(4, Arg1, minimalAttacks(Arg0)); }
	void test_case_5() { int Arr0[] = {60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(5, Arg1, minimalAttacks(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MutaliskEasy ___test;
    ___test.run_test(-1);
	vector<int> v(3);
	v[0] = 10;
	v[1] = 10;
	v[2] = 10;

	cout << ___test.minimalAttacks(v) << endl;
}
// END CUT HERE



