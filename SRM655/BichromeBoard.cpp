// BEGIN CUT HERE

// END CUT HERE
#line 5 "BichromeBoard.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int h = 0,w = 0;
bool used[55][55];
vector<string> s;

bool can(int y,int x)
{
	if(0 <= y && y < h && 0 <= x && x < w) return true;
	return false;
}

bool dfs(int y,int x)
{
	rep(i,4)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(can(ny,nx) && !used[ny][nx])
		{
			if(s[y][x] == 'B')
			{
				if(s[ny][nx] == 'B') return false;
				if(s[ny][nx] == '?') 
				{
					s[ny][nx] = 'W';
					used[ny][nx] = true;
					dfs(ny,nx);
				}
			}
			
			if(s[y][x] == 'W')
			{
				if(s[ny][nx] == 'W') 
				{
					return false;
				}
				if(s[ny][nx] == '?')
				{
					s[ny][nx] = 'B';
					used[ny][nx] = true;
					dfs(ny,nx);
				}
			}
		}
	}
	
	return true;
}

class BichromeBoard {
	public:
		string ableToDraw(vector<string> b) {
		h = b.size();
		w = b[0].size();

		s.resize(h);
		rep(i,h) s[i] = b[i];

		bool flag = true;
		bool ans = true;
		rep(i,h)
		{
			rep(j,w)
			{
				if(b[i][j] == 'B' || b[i][j] == 'W')
				{
					memset(used,0,sizeof(used));
					ans = false;
					if(!dfs(i,j))
					{
						flag = false;
						break;
					}
				}
			}

			if(!flag) break;
		}

		if(ans || flag) return "Possible";
		else return "Impossible";
	}
};

// BEGIN CUT HERE
int main() {
	BichromeBoard ___test;
	vector<string> v(3);
	v[0] = "W?W";
	v[1] = "??B";
	v[2] = "???";

	cout << ___test.ableToDraw(v) << endl;
}
// END CUT HERE
