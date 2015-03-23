// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

class RobotOnMoonEasy {
	public:
	string isSafeCommand(vector <string> board, string s) {
		int h = board.size();
		int w = board[0].size();
		int x=0,y=0,nexty=0,nextx=0;
		bool flag = true;

		rep(i,h)
		{
			rep(j,w)
			{
				if(board[i][j] == 'S')
				{
					y = i;
					x = j;
				}
			}
		}


		rep(i,s.size())
		{
			nexty = y;
			nextx = x;
			if(s[i] == 'U') nexty--;
			if(s[i] == 'D') nexty++;
			if(s[i] == 'L') nextx--;
			if(s[i] == 'R') nextx++;

			if(0 <= nexty && nexty < h && 0 <= nextx && nextx < w)
			{
				if(board[nexty][nextx] == '.')
				{
					board[y][x] = '.';
					board[nexty][nextx] = 'S';
					y = nexty;
					x = nextx;
				}
			}
			else 
			{
				flag = false;
			}

		}

		if(flag) return "Alive";
		else return "Dead";

	}
};

// BEGIN CUT HERE
int main() {
	RobotOnMoonEasy ___test;
	vector<string> v(4);
	v[0] = ".....";
 	v[1] = ".###.";
 	v[2] = "..S..";
 	v[3] = "...#.";
	string s = "URURU";

	cout << ___test.isSafeCommand(v,s) << endl;
	
}
// END CUT HERE
