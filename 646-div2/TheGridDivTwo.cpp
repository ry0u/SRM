#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int f[2010][2010];
bool used[2010][2010];
const int G = 1000;

struct Data
{
	int x;
	int y;
	int c;

	Data(int x,int y,int c) : x(x),y(y),c(c) {}

};

class TheGridDivTwo {
	public:
	int find(vector <int> x, vector <int> y, int k) {
		rep(i,2010) rep(j,2010) used[i][j] = false;
		memset(f,0,sizeof(f));

		rep(i,x.size())
		{
			f[y[i]+G][x[i]+G] = INF;
		}

		used[G][G] = true;
		queue<Data> que;
		que.push(Data(G,G,k));

		while(que.size())
		{
			Data data = que.front();
			que.pop();

			if(data.c == 0) break;

			rep(i,4)
			{
				int ny = data.y + dy[i];
				int nx = data.x + dx[i];

				if(0 <= ny && ny <= 2000 && 0 <= nx && nx <= 2000 && !used[ny][nx] && f[ny][nx] == 0)
				{
					used[ny][nx] = true;
					que.push(Data(nx,ny,data.c-1));
				}
			}
		}

		int ans = 0;
		rep(i,2010)
		{
			rep(j,2010)
			{
				if(used[i][j]) ans = max(ans,j);
			}
		}

		return ans - G;
	}	
};	

// BEGIN CUT HERE
int main() {
  TheGridDivTwo ___test;
  vector<int> x(4);
  x[0] = 1;
  x[1] = 1;
  x[2] = 1;
  x[3] = 1;

  vector<int> y(4);
  y[0] = -2;
  y[1] = -1;
  y[2] = 0;
  y[3] = 1;

  int k = 4;

  std::cout << ___test.find(x,y,k) << std::endl;
  return 0;
}
// END CUT HERE

