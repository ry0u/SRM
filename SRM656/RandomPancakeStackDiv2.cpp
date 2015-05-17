// BEGIN CUT HERE

// END CUT HERE
#line 5 "RandomPancakeStackDiv2.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

class RandomPancakeStackDiv2 {
	public:
	double expectedDeliciousness(vector <int> d) {
		double ans = 0;
		int n = d.size();

		vector<int> P;
		rep(i,n) P.push_back(i);

		do{
			bool flag = true;
			int cnt = d[P[0]];
			int top = P[0]+1;
			double p = 1.0/n;

			REP(i,1,n)
			{
				if(flag && top < P[i]+1) flag = false;
				if(flag) cnt += d[P[i]];
				
				p *= 1.0 / (n-i);
				top = P[i]+1;
			}

			ans += p*cnt;

		}while(next_permutation(P.begin(),P.end()));

		return ans;
	}
};

// BEGIN CUT HERE
int main() {
	RandomPancakeStackDiv2 ___test;
	vector<int> v(3);
	v[0] = 1;
	v[1] = 1;
	v[2] = 1;
	cout << ___test.expectedDeliciousness(v) << endl;
}
// END CUT HERE
