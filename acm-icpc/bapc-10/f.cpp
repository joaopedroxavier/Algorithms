//
// 내가 나인 게 싫은 날
// 영영 사라지고 싶은 날
// 문을 하나 만들자 너의 맘 속에다
// 그 문을 열고 들어가면
// 이 곳이 기다릴 거야
// 믿어도 괜찮아 널 위로해줄 magic shop
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e3+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int dx[] = {-1, +0, +1, +0};
int dy[] = {+0, +1, +0, -1};
char m[] = {'W', 'N', 'E', 'S'};

int xend, yend;

int dir(char c) {
  if(c == 'N') return 1;
  if(c == 'S') return 3;
  if(c == 'W') return 0;
  if(c == 'E') return 2;

  return -1;
}

int vis[N][N], dist[N][N];
vector<int> adj[N][N];

void get_adj(int x, int y) {
  string s; cin >> s;
  if(adj[x][y].empty()) {
    for(char c : s) {
      if(~dir(c)) adj[x][y].push_back(dir(c));
      else xend = x, yend = y;
    }
  }
}

void dfs(int x, int y) {
  vis[x][y] = 1;

  get_adj(x, y);

  for(int i : adj[x][y]) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(!vis[nx][ny]) {
      cout << m[i] << endl;
      dfs(nx, ny);
      cout << m[(i+2)%4] << endl;
      get_adj(x, y);
    }
  }

}

int t;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  cin >> t;
  while(t--) {

    for(int i=0; i<N; i++) for(int j=0; j<N; j++) adj[i][j].clear();
    memset(vis, 0, sizeof vis);
    memset(dist, 63, sizeof dist);

    int xs = N/2, ys = N/2;

    dfs(xs, ys);

    if(!vis[xend][yend]) {
      cout << -1 << endl;
      continue;
    }

    queue<ii> q;
    dist[xs][ys] = 0;
    q.push({xs, ys});
    while(!q.empty()) {
      int x = q.front().st;
      int y = q.front().nd;

      q.pop();

      for(int i : adj[x][y]) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(dist[nx][ny] > dist[x][y] + 1) {
          dist[nx][ny] = dist[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }

    cout << dist[xend][yend] << endl;
  }
  return 0;
}

