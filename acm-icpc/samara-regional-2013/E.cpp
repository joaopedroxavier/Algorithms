#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};

int vis[N][N];
int grid[N][N][3];
int n, m;

int sh_path(int g){
  queue<ii> bfs;
  bfs.push(mp(1,1));
  vis[1][1] = 1;
  while(!bfs.empty()){
    int x = bfs.front().first;
    int y = bfs.front().second;
    if(x == n and y == m) return vis[x][y];
    bfs.pop();
    for(int i=0;i<4;i++){
      int xn = x + dx[i];
      int yn = y + dy[i];
      if(!vis[xn][yn] and grid[x][y][g]){
        vis[xn][yn] = vis[x][y] + 1;
        bfs.push(mp(xn,yn));
      }
    }
  }
  return INF;
}

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
    char c;
    cin >> c;
    grid[i][j][0] = (c != '#');
  }
  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
    char c;
    cin >> c;
    grid[i][j][1] = (c != '#');
  }
  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
    grid[i][j][2] = grid[i][j][0] and grid[i][j][1];
  }

  int s0 = sh_path(0);
  memset(vis, 0, sizeof vis);
  int s1 = sh_path(1);
  memset(vis, 0, sizeof vis);
  int s2 = sh_path(2);

  cout << ((s0 == s1 and s0 == s2 and s0 < INF) ? "YES" : "NO") << endl;
	return 0;
}
