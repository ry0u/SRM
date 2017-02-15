// BEGIN CUT HERE

// END CUT HERE
#line 5 "BusTrip.cpp"
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
typedef pair<P, P> PP;

class BusTrip {
	public:
	int returnTime(int N, vector <string> buses) {
		vector<vector<int> > v(buses.size());
		rep(i, buses.size()) {
			int m = 1;
			rep(j, buses[i].size()) {
				if(buses[i][j] == ' ') m++;
			}

			stringstream ss(buses[i]);
			vector<int> ret;
			rep(j, m) {
				int x;
				ss >> x;
				ret.push_back(x);
			}
			v[i] = ret;
		}

		rep(i, v.size()) {
			cout << "i:" << i << " |";
			rep(j, v[i].size()) cout << v[i][j] << " ";
			cout << endl;
		}

		int last[55];
		memset(last, -1, sizeof(last));

		int d[55];
		rep(i, 55) d[i] = INF;

		priority_queue<PP, vector<PP>, greater<PP> > que;
		rep(i, v.size()) {
			que.push(mp(mp(0, i), mp(v[i][0], 0)));
		}

		while(que.size()) {
			PP p = que.top(); que.pop();
			int t = p.fi.fi;
			int bus_id = p.fi.se;
			int cur = p.se.fi;
			int index = p.se.se;

			cout << " -------- in queue: " << t << " " << bus_id << " " << cur << " " << index << " que.size():" << que.size() << endl;

			int next_index = (index + 1) % v[bus_id].size();
			int next = v[bus_id][next_index];
			int cost = abs(next - cur);

			cout << "end" << endl;

			if(d[cur] == t && last[cur] == bus_id) {
			} else {
				if((cur == 0 || d[cur] < t) && d[next] > t + cost) {
					d[next] = t + cost;
					last[next] = bus_id;

					cout << "->>>>>>> GO: " << cur << " -> " << next << " " << t + cost << endl;
				}
			}

			que.push(mp(mp(t + cost, bus_id), mp(next, next_index)));

			// rep(i, N) {
			// 	cout << "i;" << i << " eq:" << d[i] << ", " << t << " eq:" << last[i] << ", " << id << endl;
			// 	if(d[i] == t && last[i] == id) continue;
			// 	if((d[i] == INF || d[i] <= t) && d[next] > t + cost) {
			// 		d[next] = t + cost;
			// 		last[next] = id;
			// 		cout << "UPDATE:" << t + cost << endl;
			// 	}
			// }

			cout << "que.size():" << que.size() << endl;
			rep(i, N) {
				cout << i << " " << d[i] << " " << last[i] << endl;
			}

			if(last[0] != -1 && d[0] != INF) {
				cout << "check:";
				cout << last[0] << " " << d[0] << endl;
				return d[0];
			}
		}

		// priority_queue<P, vector<P>, greater<P> > que;
		// que.push(mp(time, cur));
		//
		// while(que.size()) {
		// 	P p = que.top(); que.pop();
		// }


	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"0 1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(0, Arg2, returnTime(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 51; string Arr1[] = {"0 5 10 15 20 25 30 35 40 50"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; verify_case(1, Arg2, returnTime(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"0 1 2", "2 1 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, returnTime(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; string Arr1[] = {"0 1 2 3 4", "3 1 2 0", "4 1 2 3 0", "1 2 0 3 4", "4 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(3, Arg2, returnTime(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 25; string Arr1[] = {"24 14 9 7 2", "21 4 18 24 7 1 2 11 8 9 14 16 5 17 13 23 19 15 22", "12 22 24 9 1 5 10 8 7 18 16 19 4 13 17", 
 "14 5 17 9 23 7 16 22 10 4 6", "19 8 1 9 24 3 5 22 16 7 6 4 10 23 17 0 13 15", 
 "2 16 10 13 14 1 11 20 0 24 22 23 19 4 18", "19 15 18 0", "15 9 22 5 20 8 23 14 24 18 21 6 13 19", 
 "2 6 19 3 21 10 20 22 24 13 16 15 8 18 17 14 5", "19 10 1 7 5 11 21 8 14 0 17 23 12 2 3 16"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 157; verify_case(4, Arg2, returnTime(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100; string Arr1[] = {"0 10 30 45 60 46 39 31 20", "9 20 0 86"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(5, Arg2, returnTime(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    BusTrip ___test;

    ___test.run_test(2);

}

// END CUT HERE
