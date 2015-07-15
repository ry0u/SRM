// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxPlayingGame.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

class FoxPlayingGame {
	public:
	double theMax(int nA, int nB, int paramA, int paramB) {
        double A = paramA / 1000.0;
        double B = paramB / 1000.0;

        double res = nA * A;
        if(res > 0) {
            if(B <= -1) {
                nB -= nB%2;
                rep(i,nB) {
                    res *= B;
                }
            }else if(B >= 1) {
                rep(i,nB) {
                    res *= B;
                }
            }
        }else {
            if(0 <= B && B < 1.0) {
                rep(i,nB) {
                    res *= B;
                }
            }
            else if(-1.0 < B && B < 0) {
                if(nB != 0) res *= B;
            }
            else if(B <= -1) {
                if(nB%2 == 0) nB--;
                rep(i,nB) {
                    res *= B;
                }
            }
        }

        return res;

	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 3000; int Arg3 = 2000; double Arg4 = 240.0; verify_case(0, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2000; int Arg3 = 100; double Arg4 = 6.0; verify_case(1, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 3; int Arg2 = -2000; int Arg3 = 2000; double Arg4 = -8.0; verify_case(2, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 2000; int Arg3 = -2000; double Arg4 = 160.0; verify_case(3, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 50; int Arg2 = 10000; int Arg3 = 2000; double Arg4 = 5.62949953421312E17; verify_case(4, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 41; int Arg1 = 34; int Arg2 = 9876; int Arg3 = -1234; double Arg4 = 515323.9982341775; verify_case(5, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main() {
  FoxPlayingGame ___test;
  // ___test.run_test(-1);
  cout << fixed;
  cout.precision(20);
  
  // cout << ___test.theMax(1,2,-3000,-4000) << endl;
  // cout << ___test.theMax(23,34,-9422,-180) << endl; // 39.00708
  // cout << ___test.theMax(23,35,-3581,-599) << endl; // 49.335437
  //   cout << ___test.theMax(40,45,-1,1) << endl; //-4.0000000000000037E-137
  //   cout << ___test.theMax(40,45,-1000,1000) << endl; 
    cout << ___test.theMax(10,0,-1,-200) << endl; // -0.01
}
// END CUT HERE
