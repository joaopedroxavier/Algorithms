#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

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

int n, m, s, t, dist[N][N], vis[N];
int conn[N][N];
vector<int> adj[N];

void sh_path(int g) {
  priority_queue<pair<int, int>> pq;
  pq.push({0, g});
  dist[g][g] = 0;
  
  while(!pq.empty()) {
    int u = pq.top().second;
    int d = -pq.top().first;
    pq.pop();

    for(int v : adj[u]) {
      if(dist[g][v] > d+1) {
        dist[g][v] = d+1;
        pq.push({-dist[g][v], v});
      }
    }
  }
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d %d %d", &n, &m, &s, &t);
  memset(dist, 63, sizeof dist);
  for(int i=0; i<m; i++) {
    int u, v; scanf("%d %d", &u, &v);

    conn[u][v] = conn[v][u] = 1;
    adj[u].push_back(v); adj[v].push_back(u);
  }

  for(int i=1; i<=n; i++) sh_path(i);

  int ans = 0;

  /*
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      printf("%d ", dist[i][j]);
    }
    printf("\n");
  }
  */

  for(int i=1; i<=n; i++) {
    for(int j=i+1; j<=n; j++) if(!conn[i][j]) {
      int path1 = dist[s][i] + 1 + dist[j][t];
      int path2 = dist[s][j] + 1 + dist[i][t];
      int best = min(path1, path2);

      if(best >= dist[s][t]) ans++;
    }
  }

  printf("%d\n", ans);
	return 0;
}

