#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define y1 asdwejkf

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii, int> iii;

const long double EPS = 1e-9;
const int N=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int grid[N][N];
int dist[N][N];
int fr[N][N];
int vis[N][N];

int n, m, k;
int x1, x2, y1, y2;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      char c;
      cin >> c;
      fr[i][j] = (c == '.');
      dist[i][j] = INF;
    }
  }

  cin >> x1 >> y1 >> x2 >> y2;

  queue<ii> q;
  q.push({x1, y1});
  dist[x1][y1] = 0;
  while(!q.empty()) {
    ii u = q.front();
    int p;
    int x = u.first;
    int y = u.second;
    q.pop();
    if(x == x2 and y == y2) return cout << dist[x][y] << endl, 0;

    p = 1;
    while((dist[x-p][y] >= dist[x][y] + 1) and fr[x-p][y] and p <= k) {
      if(!vis[x-p][y]) {
        dist[x-p][y] = dist[x][y] + 1;
        q.push({x-p, y});
        vis[x-p][y] = 1;
      }
      p++;
    }

    p = 1;
    while((dist[x+p][y] >= dist[x][y] + 1) and fr[x+p][y] and p <= k) {
      if(!vis[x+p][y]) {
        dist[x+p][y] = dist[x][y] + 1;
        q.push({x+p, y});
        vis[x+p][y] = 1;
      }
      p++;
    }

    p = 1;
    while((dist[x][y-p] >= dist[x][y] + 1) and fr[x][y-p] and p <= k) {
      if(!vis[x][y-p]) {
        dist[x][y-p] = dist[x][y] + 1;
        q.push({x, y-p});
        vis[x][y-p] = 1;
      }
      p++;
    }

    p = 1;
    while((dist[x][y+p] >= dist[x][y] + 1) and fr[x][y+p] and p <= k) {
      if(!vis[x][y+p]) {
        dist[x][y+p] = dist[x][y] + 1;
        q.push({x, y+p});
        vis[x][y+p] = 1;
      }
      p++;
    }
  }

  cout << -1 << endl;
  return 0;
}

