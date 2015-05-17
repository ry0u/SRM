// BEGIN CUT HERE

// END CUT HERE
#line 5 "RandomPancakeStackDiv2.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

class RandomPancakeStackDiv2 {
	public:
	double expectedDeliciousness(vector <int> d) {
		double ans = 0;
		int n = d.size();

		double p = 1;
		REP(i,1,n+1) p *= i;

		rep(i,1<<n)
		{
			bitset<10> bit(i);
			
			cout << bit << endl;
			int cnt = 0;

			rep(j,n)
			{
				int index = n-1-j;
				if(bit[j] == 1)
				{
					cnt += d[index];
				}
			}

			cout << cnt << " " << p << endl;
			ans += cnt/p;
		}
		
		cout << "ans:" << ans << endl;

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
