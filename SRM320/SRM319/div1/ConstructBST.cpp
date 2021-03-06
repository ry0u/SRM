#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define INF 1<<30
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

struct Node {
	int cntL, cntR;
	Node *left, *right;

	Node() {
		cntL = cntR = 0;
		left = right = NULL;
	}
};

set<int> S;
void build(int x, Node *root) {
	root->left = new Node();
	root->right = new Node();

	if(S.find(2 * x) != S.end()) {
		build(2 * x, root->left);
		root->cntL = (root->left->cntL + root->left->cntR + 1);
	}

	if(S.find(2 * x + 1) != S.end()) {
		build(2 * x + 1, root->right);
		root->cntR = (root->right->cntL + root->right->cntR + 1);
	}
}

ll C[2005][2005];
void combination(int size) {
	for (int i = 0; i < size; i++) C[i][0] = 1LL;
	for (int i = 1; i < size; i++) {
		for (int j = 1; j <= i; j++) {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]);
		}
	}
}

ll dfs(Node *node) {
	if(node == NULL) return 1;
	ll n = node->cntL, m = node->cntR;

	ll cnt1 = dfs(node->left);
	ll cnt2 = dfs(node->right);

	return cnt1 * cnt2 * C[n + m][n];
}

class ConstructBST {

    public:

    long long numInputs(vector <int> tree) {
		Node *root = new Node();
		S.clear();

		rep(i, tree.size()) {
			S.insert(tree[i]);
		}
		build(1, root);

		combination(2000);
		return dfs(root);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(0, Arg1, numInputs(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 3, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, numInputs(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 5, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 8LL; verify_case(2, Arg1, numInputs(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 2, 4, 6, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 6LL; verify_case(3, Arg1, numInputs(Arg0)); }
	void test_case_4() { int Arr0[] = {2, 4, 3, 62, 7, 15, 1, 31, 5, 14, 28, 57, 56, 114}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 96096LL; verify_case(4, Arg1, numInputs(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE

int main() {

    ConstructBST ___test;

    ___test.run_test(-1);

	cout << ___test.numInputs({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26}) << endl;

}

// END CUT HERE
