// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheKingsRoadsDiv2.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

vector<int> G[1050];
bool used[1050];

void dfs(int i)
{
	if(used[i]) return;
	used[i] = true;

	rep(j,G[i].size())
	{
		dfs(G[i][j]);
	}
}

class TheKingsRoadsDiv2 {
	public:
	string getAnswer(int h, vector <int> a, vector <int> b) {
		int n = pow(2.0,h);
		int m = a.size();

		rep(i,m)
		{
			if(a[i] == b[i]) continue;

			a[i]--;
			b[i]--;

			G[a[i]].push_back(b[i]);
			G[b[i]].push_back(a[i]);
		}

		rep(i,1050) used[i] = false;
		
		dfs(0);

		bool flag = true;
		rep(i,n-1)
		{
			if(!used[i]) flag = false;
		}

		if(flag) return "Correct";
		else return "Incorrect";
	}
};

// BEGIN CUT HERE
int main() {
	TheKingsRoadsDiv2 ___test;
	    
	int n = 3;

	vector<int> a(7);
	int A[7] = {1, 2, 3, 7, 1, 5, 4};
	vector<int> b(7);
	int B[7] = {6, 7, 4, 3, 3, 5, 7};

	rep(i,7)
	{
		a[i] = A[i];
		b[i] = B[i];
	}

	cout << ___test.getAnswer(n,a,b) << endl;

}
// END CUT HERE
