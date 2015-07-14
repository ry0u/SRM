// BEGIN CUT HERE

// END CUT HERE
#line 5 "GeometricProgressions.cpp"
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

vector<int> func(int n) {
    vector<int> ret;
    if(n == 0 || n == 1) {
        ret.push_back(n);
        return ret;
    }

    int a = 2;
    while(n >= a*a) {
        if(n%a == 0) {
            n /= a;
            ret.push_back(a);
        }
        else {
            a++;
        }
    }

    if(n > 1) ret.push_back(n);

    return ret;
}

class GeometricProgressions {
	public:
	int count(int b1, int q1, int n1, int b2, int q2, int n2) {
        map<vector<pair<int,int> >,int> m;

        vector<int> B1 = func(b1);
        vector<int> Q1 = func(q1);
        vector<int> B2 = func(b2);
        vector<int> Q2 = func(q2);

        map<int,int> cnt;
        rep(i,B1.size()) {
            cnt[B1[i]]++;
        }

        vector<pair<int,int> > v;
        map<int,int>::iterator ite;
        for(ite = cnt.begin();ite != cnt.end();ite++) {
            v.push_back(make_pair(ite->first,ite->second));
        }

        m[v]++;

        if(q1 == 0) {
            if(b1 != 0 && n1 != 1) {
                vector<pair<int,int> > res;
                res.push_back(make_pair(0,1));
                m[res]++;
            }
        }
        else if(b1 != 0 && q1 != 1) {
            rep(i,n1-1) {
                rep(j,Q1.size()) cnt[Q1[j]]++;
        
                vector<pair<int,int> > res;
                map<int,int>::iterator ite;
                for(ite = cnt.begin();ite != cnt.end();ite++) {
                    res.push_back(make_pair(ite->first,ite->second));
                }
                m[res]++;
            }
        }

        map<int,int> cnt2;
        rep(i,B2.size()) {
            cnt2[B2[i]]++;
        }

        vector<pair<int,int> > v2;
        for(ite = cnt2.begin();ite != cnt2.end();ite++) {
            v2.push_back(make_pair(ite->first,ite->second));
        }

        m[v2]++;

        if(q2 == 0) {
            if(b2 != 0 && n2 != 1) {
                vector<pair<int,int> > res;
                res.push_back(make_pair(0,1));
                m[res]++;
            }
        }
        else if(b2 != 0 && q2 != 1) {
            rep(i,n2-1) {
                rep(j,Q2.size()) cnt2[Q2[j]]++;

                vector<pair<int,int> > res;
                map<int,int>::iterator ite;
                for(ite = cnt2.begin();ite != cnt2.end();ite++) {
                    res.push_back(make_pair(ite->first,ite->second));
                }

                m[res]++;
            }
        }

        return m.size();
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 5; int Arg3 = 6; int Arg4 = 2; int Arg5 = 5; int Arg6 = 6; verify_case(0, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 5; int Arg3 = 2; int Arg4 = 3; int Arg5 = 5; int Arg6 = 9; verify_case(1, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; int Arg4 = 0; int Arg5 = 1; int Arg6 = 2; verify_case(2, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 100500; int Arg3 = 48; int Arg4 = 1024; int Arg5 = 1000; int Arg6 = 100500; verify_case(3, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    GeometricProgressions ___test;
    ___test.run_test(-1);
    
    cout << ___test.count(6,8,1843,0,5,12317) << endl;
    cout << ___test.count(8,1,7377,6,0,18757) << endl;
    cout << ___test.count(1,1,1,0,0,1) << endl;
    cout << ___test.count(0,4,30337,1,0,3603) << endl;
    cout << ___test.count(7,4,5,8,0,1) << endl; // ans 6
    cout << ___test.count(12,0,1,42,31,1) << endl; // ans 3
}
// END CUT HERE
