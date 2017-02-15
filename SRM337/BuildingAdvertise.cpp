// BEGIN CUT HERE

// END CUT HERE
#line 5 "BuildingAdvertise.cpp"
#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,k,n) for(int i=k;i<(int)(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct RMQ {
	int n;
	vector<int> dat;
	RMQ(int n_) {
		n = 1;
		while(n < n_) n *= 2;

		dat.resize(n*4);
		rep(i,n*4) dat[i] = INF;
	}
	void update(int k,int a) {
		int i = k+n-1;
		dat[i] = a;

		while(i > 0) {
			i = (i-1) / 2;
			dat[i] = min(dat[i*2+1],dat[i*2+2]);
		}
	}
	//query(a,b,0,0,n) [a,b)
	int _query(int a,int b,int k,int l,int r)
	{
		if(r <= a || b <= l) return INF;

		if(a <= l && r <= b) return dat[k];
		else { 
			int vl = _query(a,b,k*2+1,l,(l+r)/2);
			int vr = _query(a,b,k*2+2,(l+r)/2,r);
			return min(vl,vr);
		}
	}

	//[a,b)
	int query(int a,int b) {
		return _query(a,b,0,0,n);
	}
};

class BuildingAdvertise {
	public:
	long long getMaxArea(vector <int> h, int n) {
		vector<ll> R(n);
		int j = 0, m = h.size(), s= 0;

		rep(i, n) {
			R[i] = h[j];
			s = (j+1) % m;
			h[j] = ((h[j] ^ h[s]) + 13) % 835454957;
			j = s;
		}

		RMQ rmq(n);
		rep(i, n) {
			rmq.update(i, R[i]);
		}

		ll ans = 0;
		rep(i, n) {
			// [i, n)
			int l = i, r = n;
			while(r - l > 1) {
				int mid = (r + l) / 2;
				if(rmq.query(i, mid+1) < R[i]) {
					r = mid;
				} else {
					l = mid;
				}
			}

			// (-1, i]
			int right = r;
			l = -1, r = i;
			while(r - l > 1) {
				int mid = (r + l) / 2;
				if(rmq.query(mid, i+1) < R[i]) {
					l = mid;
				} else {
					r = mid;
				}
			}
			int left = r;

			ans = max(ans, R[i] * (right - left));
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,6,5,6,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; long long Arg2 = 15LL; verify_case(0, Arg2, getMaxArea(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5,0,7,0,2,6,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; long long Arg2 = 7LL; verify_case(1, Arg2, getMaxArea(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1048589,2097165}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100000; long long Arg2 = 104858900000LL; verify_case(2, Arg2, getMaxArea(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,7,2,5,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; long long Arg2 = 8LL; verify_case(3, Arg2, getMaxArea(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    BuildingAdvertise ___test;

    ___test.run_test(-1);

}

// END CUT HERE
