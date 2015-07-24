// BEGIN CUT HERE

// END CUT HERE
#line 5 "ChessFloor.cpp"
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

using namespace std;
typedef long long ll;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N = 0;
bool used[40][40];

bool can(int y,int x) {
    if(0 <= y && y < N && 0 <= x && x < N) return true;
    return false;
}


class ChessFloor {
	public:
	int minimumChanges(vector <string> f) {
        int n = f.size();
        N = n;
        int ans = INF;

        map<char,int> m;
        rep(i,n) rep(j,n) m[f[i][j]]++;

        if(m.size() == 1) {
            return (int)((n*n)/2 + 0.5);
        }

        rep(i,26) {
            rep(j,26) {
                char a = 'a' + i;
                char b = 'a' + j;

                if(a == b) continue;

                int cnt1 = 0,cnt2 = 0;
                vector<string> v(f.begin(),f.end());
                rep(y,n) {
                    rep(x,n) {
                        if(y%2 == 0) {
                            if(x%2 == 0 && v[y][x] != a) {
                                cnt1++;
                            }
                            if(x%2 == 1 && v[y][x] != b) {
                                cnt1++;
                            }
                        }
                        else {
                            if(x%2 == 0 && v[y][x] != b) {
                                cnt1++;
                            }
                            if(x%2 == 1 && v[y][x] != a) {
                                cnt1++;
                            }
                        }
                    }
                }

                vector<string> v2(f.begin(),f.end());
                rep(y,n) {
                    rep(x,n) {
                        if(y%2 == 0) {
                            if(x%2 == 0 && v2[y][x] != b) {
                                cnt2++;
                            }
                            if(x%2 == 1 && v2[y][x] != a) {
                                cnt2++;
                            }
                        }
                        else {
                            if(x%2 == 0 && v2[y][x] != a) {
                                cnt2++;
                            }
                            if(x%2 == 1 && v2[y][x] != b) {
                                cnt2++;
                            }
                        }
                    }
                }

                ans = min(ans,min(cnt1,cnt2));

            }
        }
        return ans;
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"aba",
 "bbb",
 "aba"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimumChanges(Arg0)); }
	void test_case_1() { string Arr0[] = {"wbwbwbwb",
 "bwbwbwbw",
 "wbwbwbwb",
 "bwbwbwbw",
 "wbwbwbwb",
 "bwbwbwbw",
 "wbwbwbwb",
 "bwbwbwbw"}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minimumChanges(Arg0)); }
	void test_case_2() { string Arr0[] = {"zz",
 "zz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minimumChanges(Arg0)); }
	void test_case_3() { string Arr0[] = {"helloand",
 "welcomet",
 "osingler",
 "oundmatc",
 "hsixhund",
 "redandsi",
 "xtythree",
 "goodluck"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 56; verify_case(3, Arg1, minimumChanges(Arg0)); }
	void test_case_4() { string Arr0[] = {"jecjxsengslsmeijrmcx",
 "tcfyhumjcvgkafhhffed",
 "icmgxrlalmhnwwdhqerc",
 "xzrhzbgjgabanfxgabed",
 "fpcooilmwqixfagfojjq",
 "xzrzztidmchxrvrsszii",
 "swnwnrchxujxsknuqdkg",
 "rnvzvcxrukeidojlakcy",
 "kbagitjdrxawtnykrivw",
 "towgkjctgelhpomvywyb",
 "ucgqrhqntqvncargnhhv",
 "mhvwsgvfqgfxktzobetn",
 "fabxcmzbbyblxxmjcaib",
 "wpiwnrdqdixharhjeqwt",
 "xfgulejzvfgvkkuyngdn",
 "kedsalkounuaudmyqggb",
 "gvleogefcsxfkyiraabn",
 "tssjsmhzozbcsqqbebqw",
 "ksbfjoirwlmnoyyqpbvm",
 "phzsdodppzfjjmzocnge"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 376; verify_case(4, Arg1, minimumChanges(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ChessFloor ___test;
    // ___test.run_test(-1);
    vector<string> v(3);
    v[0] = "aba";
    v[1] = "bbb";
    v[2] = "bbb";
    cout << ___test.minimumChanges(v) << endl;
}
// END CUT HERE
