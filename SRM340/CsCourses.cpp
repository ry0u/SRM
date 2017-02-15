// BEGIN CUT HERE

// END CUT HERE
#line 5 "CsCourses.cpp"
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
typedef pair<int, P> IP;

struct edge {
	int from,to;
	int cost;

	edge(int t,int c) : to(t),cost(c) {}
	edge(int f,int t,int c) : from(f),to(t),cost(c) {}

	bool operator<(const edge &e) const {
		return cost < e.cost;
	}
};

int d[100005], _prev[100005], preindex[100005];

vector<int> get_path(int t) {
	int index = -1;
	vector<int> path;
	for(;t!=-1;t=_prev[t]) {
		index = preindex[t];
		if(index != -1) path.push_back(index);
	}
	reverse(path.begin(),path.end());
	return path;
}

class CsCourses {
	public:
	vector <int> getOrder(vector <int> theoreticalValue, vector <int> practicalValue, vector <int> expire, int skillBound) {
		int n = theoreticalValue.size();

		rep(i, 100005) {
			d[i] = INF;
			_prev[i] = -1;
			preindex[i] = -1;
		}

		priority_queue<P, vector<P>, greater<P> > que;
		que.push(mp(0, 0));
		d[0] = 0;

		while(que.size()) {
			P p = que.top(); que.pop();
			int cost = p.fi;
			int a = p.se / 100;
			int b = p.se % 100;

			if(d[a * 100 + b] < cost) continue;

			// cout << " --------- in queue ----- : " << cost << " now:" << p.se << endl;

			rep(i, n) {
				if(theoreticalValue[i] <= a + 1 && practicalValue[i] <= b + 1) {
					int next = max(a, theoreticalValue[i]) * 100 + max(b, practicalValue[i]);
					if(cost + 1 <= expire[i] && d[next] == cost + 1) {
						vector<int> x = get_path(_prev[next]);
						vector<int> y = get_path(a * 100 + b);

						bool change = false;
						if(x.size() == y.size()) {
							rep(i, min(x.size(), y.size())) {
								if(x[i] == y[i]) continue;
								if(x[i] < y[i]) break;
								else {
									change = true;
									break;
								}
							}
						} else if(y.size() < x.size()) {
							change = true;
						}

						if(change) {
							_prev[next] = a * 100 + b;
							preindex[next] = i;
							que.push(mp(cost + 1, next));
						}
					}

					if(cost + 1 <= expire[i] && d[next] > cost + 1) {
						d[next] = cost + 1;
						_prev[next] = a * 100 + b;
						preindex[next] = i;
						que.push(mp(cost + 1, next));
					}
				}
			}
		}

		bool first = true;
		vector<int> ret;
		REP(i, skillBound, 55) {
			REP(j, skillBound, 55) {
				if(d[i * 100 + j] == INF) continue;

				vector<int> x = get_path(i * 100 + j);

				if(first) {
					ret = x;
					first = false;
				} else {
					if(ret.size() == x.size()) {
						rep(i, min(ret.size(), x.size())) {
							if(ret[i] == x[i]) continue;

							if(ret[i] < x[i]) break;
							else {
								swap(ret, x);
								break;
							}
						}
					} else if(ret.size() > x.size()) {
						ret = x;
					}
				}
			}
		}
		rep(i, ret.size()) cout << ret[i] << " ";
		cout << endl;

		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arr4[] = {0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, getOrder(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 5, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arr4[] = {2, 0, 1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, getOrder(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arr4[] = { }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, getOrder(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arr4[] = {2, 1, 0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, getOrder(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; int Arr4[] = {0, 1, 2, 3, 4, 5, 6 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, getOrder(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {0, 1, 2, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 1, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9, 9, 9, 9, 9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arr4[] = {4, 3 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(5, Arg4, getOrder(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    CsCourses ___test;

    ___test.run_test(-1);

	vector<int> ret = ___test.getOrder({0, 2, 3, 1}, {1, 1, 2, 1}, {3, 3, 4, 2}, 2);
	ret = ___test.getOrder({1, 2, 2, 0, 1, 0, 3, 1}, {2, 5, 6, 1, 4, 2, 6, 3}, {5, 7, 8, 1, 7, 3, 9, 6}, 3); // 3,  0, 7, 4, 1, 6
	ret = ___test.getOrder({12, 1, 5, 7, 16, 13, 6, 4, 9, 11, 8, 11, 3, 5, 10, 15, 5, 3, 14, 1, 8, 2, 15, 4, 17, 17, 8, 4, 0, 6, 5}, {21, 3, 12, 14, 25, 22, 14, 7, 18, 20, 15, 21, 5, 10, 19, 24, 13, 6, 23, 2, 17, 4, 25, 8, 26, 25, 16, 9, 1, 13, 11}, {25, 6, 14, 17, 31, 25, 15, 9, 24, 23, 17, 28, 8, 13, 24, 29, 16, 10, 30, 6, 21, 6, 33, 10, 31, 30, 23, 10, 6, 19, 11}, 17);

	ret = ___test.getOrder({0}, {1}, {1}, 0);
	ret = ___test.getOrder({9, 19, 16, 13, 15, 10, 14, 12, 18, 19, 1, 8, 6, 5, 17, 3, 7, 11, 12, 9, 20, 15, 5, 9, 18, 11, 2, 4, 9, 2, 21, 5, 17}, {9, 20, 16, 14, 15, 12, 14, 14, 18, 19, 1, 8, 6, 5, 17, 3, 7, 12, 13, 8, 20, 16, 6, 11, 17, 13, 1, 4, 10, 2, 20, 4, 16}, {13, 35, 30, 22, 24, 20, 27, 24, 31, 32, 3, 16, 9, 9, 31, 4, 10, 17, 22, 15, 34, 28, 10, 16, 31, 18, 6, 9, 15, 3, 33, 6, 29}, 20);
	ret = ___test.getOrder({3, 49, 26, 13, 35, 49, 6, 17, 32, 15, 50, 23, 45, 44, 1, 25, 3, 40, 2, 47, 4, 50, 48, 28, 18, 5, 7, 1, 6, 18, 20, 35, 5, 4, 2, 2, 36, 43, 3, 14, 30, 3, 5, 22, 20, 4, 45, 35, 27, 1}, {29, 17, 22, 8, 20, 35, 15, 31, 34, 39, 3, 5, 37, 32, 2, 26, 7, 41, 3, 3, 46, 32, 47, 23, 47, 9, 10, 23, 10, 36, 31, 20, 9, 8, 3, 4, 4, 11, 6, 38, 7, 5, 9, 48, 36, 7, 1, 32, 1, 1}, {16, 5, 33, 3, 48, 10, 47, 26, 11, 2, 13, 23, 7, 43, 4, 1, 14, 30, 8, 12, 19, 17, 7, 44, 17, 11, 16, 40, 20, 45, 8, 25, 20, 14, 9, 7, 7, 31, 12, 24, 16, 7, 18, 9, 37, 12, 15, 49, 13, 1}, 4);
	ret = ___test.getOrder({25, 5, 3, 2, 1, 12, 24, 8, 8, 17, 12, 11, 2, 13, 9, 38, 13, 15, 13, 38, 3, 6, 5, 9, 0, 9, 30, 7, 36, 9, 7, 3, 10, 11, 11, 9, 14, 15, 1, 4, 10, 10, 7, 12, 14, 14, 14, 6, 5, 33}, {21, 1, 2, 1, 40, 12, 50, 7, 47, 11, 13, 11, 19, 13, 8, 46, 14, 13, 13, 41, 3, 5, 4, 9, 0, 7, 50, 6, 42, 8, 6, 32, 10, 12, 12, 8, 15, 17, 1, 4, 34, 10, 6, 2, 34, 15, 16, 5, 4, 41}, {47, 34, 10, 9, 14, 25, 22, 15, 7, 25, 32, 26, 2, 31, 21, 4, 30, 10, 26, 29, 8, 9, 9, 23, 1, 19, 27, 16, 3, 16, 13, 12, 25, 26, 35, 19, 34, 37, 7, 12, 40, 21, 18, 39, 20, 35, 33, 17, 12, 34}, 7);
}

// END CUT HERE
