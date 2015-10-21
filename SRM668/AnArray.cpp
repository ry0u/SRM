// BEGIN CUT HERE

// END CUT HERE
#line 5 "AnArray.cpp"
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

using namespace std;
typedef long long ll;

vector<ll> prime_factor(ll n) {
    vector<ll> res;
    if(n == 1) return res;

    for(ll i = 2; i*i <= n; i++) {
        while(n%i == 0) {
            res.push_back(i);
            n /= i;
        }
    }

    if(n != 1) res.push_back(n);
    return res;
}

map<ll,ll> prime_factor_map(ll n) {
    map<ll,ll> res;
    for(ll i=2; i*i <= n; i++) {
        while(n%i == 0) {
            res[i]++;
            n /= i;
        }
    }

    if(n != 1) res[n] = 1;
    return res;
}

vector<ll> divisor(ll n) {
    vector<ll> res;
    for(ll i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i != n/i) res.push_back(n/i);
        }
    }
    return res;
}

int cnt[1000000000];

class AnArray {
	public:
	int solveProblem(vector <int> A, int K) {
        vector<ll> a(A.begin(), A.end());
        int n = A.size();
        sort(a.begin(),a.end());

        memset(cnt,0,sizeof(cnt));

        vector<ll> ret = prime_factor(K);
        vector< vector<ll> > v(n);

        rep(i,n) {
            vector<ll> res = divisor(a[i]);
            res.push_back(a[i]);
            rep(j,res.size()) {
                cnt[res[j]]++;
            }

            copy(res.begin(),res.end(),back_inserter(v[i]));
        }
        ll ans = 0;

        rep(i,n) {
            REP(j,i+1,n) {
                if(a[i] * a[j] % K == 0) {
                    ans += n - 1 - j;
                    continue;
                }

                // cout << "i:" << i << ":" << a[i] << " || j:" << j << ":" << a[j] << endl;

                map<ll,ll> m = prime_factor_map(K);
                map<ll,ll> d = prime_factor_map(a[i]);
                map<ll,ll> d2 = prime_factor_map(a[j]);

                map<ll,ll>::iterator ite;
                for(ite = d.begin(); ite != d.end(); ite++) {
                    m[ite->first] -= ite->second;
                }
                for(ite = d2.begin(); ite != d2.end(); ite++) {
                    m[ite->first] -= ite->second;
                }

                ll res = 1;
                for(ite = m.begin(); ite != m.end(); ite++) {
                    if(ite->second > 0) {
                        res *= ite->first * ite->second;
                    }
                }

                // cout << "--------- ite ------------" << endl;
                // for(ite = m.begin(); ite != m.end(); ite++) {
                //     cout << ite->first << " " << ite->second << endl;
                // }


                // cout << "res:" << res << " " << cnt[res] << endl;

                rep(k,v[i].size()) {
                    cnt[v[i][k]]--;
                }
                rep(k,v[j].size()) {
                    cnt[v[j][k]]--;
                }

                ans += cnt[res];

                rep(k,v[i].size()) {
                    cnt[v[i][k]]++;
                }

                rep(k,v[i].size()) {
                    cnt[v[j][k]]++;
                }
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
	void test_case_0() { int Arr0[] = {31, 1, 3, 7, 2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 1; verify_case(0, Arg2, solveProblem(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4, 5, 2, 25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 2; verify_case(1, Arg2, solveProblem(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100000000, 100000000, 100000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000; int Arg2 = 1; verify_case(2, Arg2, solveProblem(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {269, 154, 94, 221, 171, 154, 50, 210, 258, 358, 121, 159, 8, 47, 290, 125, 291, 293, 338, 248, 295, 160, 268, 227, 99, 4, 273}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 360; int Arg2 = 114; verify_case(3, Arg2, solveProblem(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 220; verify_case(4, Arg2, solveProblem(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    AnArray ___test;
    ___test.run_test(-1);
}
// END CUT HERE
