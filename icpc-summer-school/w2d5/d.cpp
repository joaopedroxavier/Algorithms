#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define st first
#define nd second

using namespace std;
typedef long long ll;

const int N = 1e6+5;

int n, sz[N], vis[N], berries, ans;
vector<int> adj[N];

int dfs(int u) {
  vis[u] = 1;
  for(int v : adj[u]) if(!vis[v]) sz[u] += dfs(v);

  berries += (adj[u].size() == 1 and u != 1);
  return sz[u] += (adj[u].size() == 1 and u != 1);
}

int main(){
  scanf("%d", &n);
  for(int i=1; i<n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].pb(v), adj[v].pb(u);
  }


  dfs(1);
  memset(vis, 0, sizeof vis);
  for(int i=2; i<=n; i++) {
    sz[i] = min(sz[i], berries - sz[i]);
    ans = max(ans, sz[i]);
  }

  printf("%d\n", ans);
}
