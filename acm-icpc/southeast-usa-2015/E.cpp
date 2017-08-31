#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define f first
#define s second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

char grid[N][N];
int vis[N][N];
int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};
int n, m, ans = INF;

int main(){
  while(scanf("%d %d", &n, &m) != EOF){
    memset(vis,0,sizeof(vis));
    ans = INF;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> grid[i][j];
    queue<pair<ii,int> > bfs;
    bfs.push(mp(mp(1,1),0));
    vis[1][1] = 1;
    while(!bfs.empty()){
      int x = (bfs.front()).f.f;
      int y = (bfs.front()).f.s;
      int w = (bfs.front()).s;
      if(x == n and y == m){
        ans = w;
        break;
      }
      bfs.pop();
      for(int i=0;i<4;i++){
        int k = grid[x][y] - '0';
        int xn = x + k*dx[i];
        int yn = y + k*dy[i];
        if(xn > 0 and xn <= n and yn > 0 and yn <= m){
          if(!vis[xn][yn]){
            vis[xn][yn] = 1;
            bfs.push(mp(mp(xn,yn),w+1));
          }
        }
      }
    }
    printf("%d\n", ((ans < INF) ? ans : -1));
  }
  return 0;
}

