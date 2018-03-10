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

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, m, par[N], rec[N], vis[N];
ll dist[N];

vector<int> adj[N];
vector<ll> d[N];

set<ii> roads;

void sh_path() {
  memset(dist, 63, sizeof dist);
  memset(par, -1, sizeof par);
  memset(rec, -1, sizeof rec);

  priority_queue<pair<ll, int>> pq;
  pq.push({1,1});
  dist[1] = 0;

  while(!pq.empty()) {
    int u = pq.top().second;
    ll w = -pq.top().first;

    pq.pop();

    for(int i=0; i < (int) adj[u].size(); i++) {
      int v = adj[u][i];
      ll wt = d[u][i];
      if(dist[v] > w + wt) {
        par[v] = u;
        dist[v] = w + wt;
        pq.push({-dist[v], v});
      }
    }
  }
}

void dfs(int u) {
  vis[u] = 1;
  for(int v : adj[u]) {
    if(!vis[v] and par[u] != v) {
      rec[v] = u;
      dfs(v);
    }
  }
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);

  for(int i=0; i<m; i++) {
    int u, v; ll w;
    scanf("%d %d %lld", &u, &v, &w);

    adj[u].pb(v); adj[v].pb(u);
    d[u].pb(w); d[v].pb(w);
  }

  sh_path();
  memset(vis, 0, sizeof vis);
  dfs(0);

  if(rec[1] == -1) return printf("impossible\n"), 0;

  vector<int> ans;
  int i=1;
  while(i != 0) {
    ans.pb(i);
    i = rec[i];
  }
  ans.pb(0);
  reverse(ans.begin(), ans.end());

  printf("%d ", (int) ans.size());
  for(auto i : ans) printf("%d ", i);
  printf("\n");
  return 0;
}

