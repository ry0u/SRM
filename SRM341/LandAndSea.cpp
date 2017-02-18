// BEGIN CUT HERE

// END CUT HERE
#line 5 "LandAndSea.cpp"
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

int h, w;
int id[55][55];
int dx[4] = { 1, 0,-1, 0};
int dy[4] = { 0, 1, 0,-1};
int dx2[8] = { 1, 1, 0,-1,-1,-1, 0, 1};
int dy2[8] = { 0, 1, 1, 1, 0,-1,-1,-1};

bool inside(int y, int x) {
	if(0 <= y && y < h && 0 <= x && x < w) return true;
	return false;
}

int counter = 0;
bool visited[55][55];
vector<string> s;
void dfs(int y, int x) {
	rep(i, 8) {
		int ny = y + dy2[i];
		int nx = x + dx2[i];

		if(inside(ny, nx) && !visited[ny][nx] && s[ny][nx] == 'x') {
			id[ny][nx] = counter;
			visited[ny][nx] = true;
			dfs(ny, nx);
		}
	}
}

int myid = -1;
bool outflag = false;
map<int, int> m;
void dfs2(int y, int x) {
	if(outflag) return;

	rep(i, 4) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		

		if(visited[ny][nx]) continue;
		if(!inside(ny, nx)) {
			outflag = true;
			return;
		}

		if(s[ny][nx] == '.') {
			visited[ny][nx] = true;
			dfs2(ny, nx);
		} else {
			int t = id[ny][nx];

			if(t != myid) {
				visited[ny][nx] = true;
				m[id[ny][nx]]++;
			} else {
				visited[ny][nx] = true;
				dfs2(ny, nx);
			}

		}
	}
}

vector<int> G[55 * 55], out;
bool used[55 * 55];
void tposo(int cur) { // topologicalsort-dfs
	used[cur] = true;
	rep(i,G[cur].size()) {
		int v = G[cur][i];
		if(!used[v]) tposo(v);
	}

	out.push_back(cur);
}


class LandAndSea {
	public:
	vector <int> howManyIslands(vector <string> seaMap) {
		s = seaMap;
		h = seaMap.size();
		w = seaMap[0].size();

		counter = 0;
		memset(id, -1, sizeof(id));
		memset(visited, false, sizeof(visited));
		rep(i, 55) G[i].clear();
		out.clear();

		vector<P> start;
		rep(i, h) {
			rep(j, w) {
				if(visited[i][j]) continue;
				if(s[i][j] == '.') continue;

				id[i][j] = counter;
				visited[i][j] = true;
				start.push_back(mp(i, j));

				dfs(i, j);
				counter++;
			}
		}

		int indeg[55 * 55];
		memset(indeg, 0, sizeof(indeg));

		rep(i, counter) {
			m.clear();
			myid = i;
			outflag = false;
			memset(visited, false, sizeof(visited));

			visited[start[i].fi][start[i].se] = true;
			dfs2(start[i].fi, start[i].se);

			if(outflag) continue;
			int parent = -1, vmax = 0;

			each(it, m) {
				if(it->second > vmax) {
					parent = it->first;
					vmax = it->second;
				}
			}

			G[i].push_back(parent);
			indeg[parent]++;
		}

		memset(used, 0, sizeof(used));
		rep(i, counter) {
			if(!used[i]) tposo(i);
		}
		reverse(out.begin(), out.end());

		map<int, int> ans;
		vector<int> dp(counter);
		rep(i, out.size()) {
			int id = out[i];
			ans[dp[id]]++;
			rep(j, G[id].size()) {
				dp[G[id][j]] = max(dp[G[id][j]], dp[id] + 1);
			}
		}

		vector<int> res(ans.size());
		rep(i, ans.size()) res[i] = ans[i];
		return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"x"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, howManyIslands(Arg0)); }
	void test_case_1() { string Arr0[] = {
"xxxxx",
"x...x",
"x.x.x",
"x...x",
"xxxxx"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, howManyIslands(Arg0)); }
	void test_case_2() { string Arr0[] = {
"xxxxx",
"x...x",
"x.x.x",
"x...x",
"xxxxx",
"xxxxx",
"x...x",
"x.x.x",
"x...x",
"xxxxx"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, howManyIslands(Arg0)); }
	void test_case_3() { string Arr0[] = {
"..",
".."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, howManyIslands(Arg0)); }
	void test_case_4() { string Arr0[] = {
"............",
".......xxxx.",
"..xxx.x...x.",
"..x..x..x.x.",
"..x.x.x...x.",
"..xx...xxx.."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, howManyIslands(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    LandAndSea ___test;

    ___test.run_test(-1);

	vector<int> ret = ___test.howManyIslands({"xxx.x...xxxxx",
			"xxxx....x...x",
			"........x.x.x",
			"..xxxxx.x...x",
			"..x...x.xxx.x",
			"..x.x.x...x..",
			"..x...x...xxx",
			"...xxxxxx....",
			"x............"});
	rep(i, ret.size()) cout << ret[i] << " ";
	cout << endl;

	ret = ___test.howManyIslands({"....x....xxx.......x..........x.....", "x.x...x.xxx.....xx..x..x............", ".x.............x.xx.x..x..x....xx.x.", "......xx.x.xx..x..x.x.....xxx.....xx", ".xx..x....x..............x...x......", "x...x..xxx....x.xxx...x.....x..x.x.x", "..xx......x.xx.x.....xx.....x....x..", "...xx....xx.........x.........xx....", ".......x...xx..........xx...xx......", "x.xx......x..........x.x..x..x.x...x", "..........x....x...........x....xx..", "x..x...x...x.x............xx........", "............xx..................xx..", ".........x.......x....xx.xx...x.x.x.", "...............x.x..xx........x..x..", ".........x.x.......xxx.......x....x.", "......x........xx...x....x..........", "........x..xx..x....xxxxx..x.....x..", "xx.x...x...xx........x..........xxxx", "...x..x.......x.x.....x......xx...x.", "xx...xx.........xx.....x...xxxx.....", "......x........x.x.....xx.x...xx.x.x", ".......xxx...x........x....x......x.", "xx..........xx...xx..........x....x.", "..............x......x.......x...x..", ".x.xxxx...xxx......x..x.....xx......", "x..xx.x..x.x....x..xx......x..x.....", "..x....x...x.......x.x......xx...xx.", "xx......x...x.x..x......x.x...xx.x..", "...x........x.xx.xx......x......x.x.", "..x............x.....x..x..x.....x..", ".x...x...x.....x...x........x.......", "x.xx.x..x...xx....x.xxx.x....x...xx.", ".x...x...x......x..x..x.x.....x.x...", "x.x.x.x.....x.x.x..x.xxx...x...x..x.", ".xx.x.x..x..x....xxxx.x..x..........", ".x....xx......x...x..............x..", "xx..xxx...x...x.x..............xx.xx", "xx..x.xxx..x.....x....x.xx..x.......", "..x......x..x....x...x.....x.x..x.x.", "......xx....x..x.....xxx.x..x.x....x", ".x.x............x...x.....x.x.x.x...", "....x.x..x...x..x.x...x.......x.x...", "...x.x.x...x.x..x..x.x.x...x...x....", ".......x..xx......x..x.x.x....x....x", "..x....x....x...x............xx..xxx", "x......x.....x.xx..x..............xx", "x..xx..xx................x.x.x.xx...", "..x....x..x.xx.x..............x....."});
	rep(i, ret.size()) cout << ret[i] << " ";
	cout << endl;
}

// END CUT HERE
