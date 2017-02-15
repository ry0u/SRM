// BEGIN CUT HERE

// END CUT HERE
#line 5 "AnagramList.cpp"
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

ll fact[25];

class AnagramList {
	public:
	string getAnagram(string s, int cnt) {
		memset(fact, 0, sizeof(fact));
		fact[0] = fact[1] = 1;
		REP(i, 2, 25) {
			fact[i] = i * fact[i-1];
		}

		map<char, int> m;
		rep(i, s.size()) {
			m[s[i]]++;
		}

		int sum = s.size();
		string ans = "";

		priority_queue<char, vector<char>, greater<char> > que;
		rep(i, s.size()) {
			que.push(s[i]);
		}

		while(m.size()) {
			bool flag = true;
			vector<char> v;
			each(it, m) v.push_back(it->fi);

			rep(i, v.size()) {
				m[v[i]]--;
				ll t = fact[sum - 1];
				each(it, m) {
					t /= fact[it->se];
				}

				if(cnt < t) {
					ans += v[i];
					sum--;
					flag = false;

					if(m[v[i]] == 0) {
						m.erase(v[i]);
					}

					break;
				} else {
					cnt -= t;
					m[v[i]]++;
				}
			}

			if(flag) return "";
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "tree"; int Arg1 = 1; string Arg2 = "eetr"; verify_case(0, Arg2, getAnagram(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "tree"; int Arg1 = 6; string Arg2 = "reet"; verify_case(1, Arg2, getAnagram(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "tree"; int Arg1 = 12; string Arg2 = ""; verify_case(2, Arg2, getAnagram(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abcabfebda"; int Arg1 = 5000; string Arg2 = "aadfcabbbe"; verify_case(3, Arg2, getAnagram(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "sdoijgfasdkhaiw"; int Arg1 = 2000000000; string Arg2 = "adsdghwiiokfjas"; verify_case(4, Arg2, getAnagram(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {

    AnagramList ___test;

    ___test.run_test(-1);

}

// END CUT HERE
