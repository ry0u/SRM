// BEGIN CUT HERE

// END CUT HERE
#line 5 "LightsCube.cpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<P, int> PI;

vector<string> split(const string &str, char delim) {
	vector<string> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos) {
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}

int f(string s) {
	stringstream ss;
	ss << s;

	int x;
	ss >> x;

	return x;
}

int d[50][50][50], n;
int dx[6] = {1,-1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1,-1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1,-1};

bool can(int x, int y, int z) {
	if(0 <= x && x < n && 0 <= y && y < n && 0 <= z && z < n) return true;
	return false;
}

class LightsCube {
	public:
	vector <int> count(int N, vector <string> lights) {
		n = N;
		memset(d, -1, sizeof(d));
		queue<PI> que;
		rep(i, lights.size()) {
			vector<string> ret = split(lights[i], ' ');

			int x = f(ret[0]);
			int y = f(ret[1]);
			int z = f(ret[2]);

			d[x][y][z] = i;
			que.push(mp(mp(x, y), z));
		}

		while(que.size()) {
			PI p = que.front(); que.pop();

			int x = p.first.first;
			int y = p.first.second;
			int z = p.second;

			rep(i, 6) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];

				if(can(nx, ny, nz) && d[nx][ny][nz] == -1) {
					d[nx][ny][nz] = d[x][y][z];
					que.push(mp(mp(nx, ny), nz));
				}
			}
		}

		vector<int> v(lights.size());
		rep(i, N) {
			rep(j, N) {
				rep(k, N) {
					v[d[i][j][k]]++;
				}
			}
		}

		return v;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; string Arr1[] = {"0 0 0", "0 0 1", "0 1 0", "0 1 1", "1 0 0", "1 0 1", "1 1 0", "1 1 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 1, 1, 1, 1, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; string Arr1[] = {"1 1 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {27 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; string Arr1[] = {"0 0 0", "3 3 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {32, 32 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; string Arr1[] = {"0 2 4", "2 0 0", "3 4 4", "4 1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {38, 28, 32, 27 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 12; string Arr1[] = {"4 7 6", "8 0 0", "3 2 3", "7 7 2", "7 5 1",
 "10 11 5", "4 9 7", "6 1 0", "10 1 1", "9 7 11",
 "11 3 11", "9 0 3", "10 2 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {264, 18, 303, 236, 105, 124, 216, 44, 53, 146, 126, 80, 13 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 40; string Arr1[] = {"29 13 9", "4 10 34", "11 26 16", "2 33 22", "27 31 14", "36 20 8"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {14657, 12834, 12364, 5902, 12678, 5565 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    LightsCube ___test;

    ___test.run_test(-1);

}

// END CUT HERE
