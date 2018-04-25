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

const int N = 2e5+20;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

vector<int> adj[N], switches[N];
int st[N], scc[N], vis[N], sccn;
int n, m;

void dfs(int u) {
  vis[u] = 1;
  for(int v : adj[u]) if(!vis[v])
    scc[v] = scc[u], dfs(v);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);

  for(int i=1; i<=n; i++) {
    scanf("%d", &st[i]);
  }

  for(int i=1; i<=m; i++) {
    int x; scanf("%d", &x);
    for(int j=0; j<x; j++) {
      int u; scanf("%d", &u);
      switches[u].push_back(i);
    }
  }

  for(int i=1; i<=n; i++) {
    if(st[i]) {
      int u = switches[i][0];
      int v = switches[i][1];
      adj[2*u].push_back(2*v);
      adj[2*u+1].push_back(2*v+1);
      adj[2*v].push_back(2*u);
      adj[2*v+1].push_back(2*u+1);
    }
    else {
      int u = switches[i][0];
      int v = switches[i][1];
      adj[2*u].push_back(2*v+1);
      adj[2*u+1].push_back(2*v);
      adj[2*v].push_back(2*u+1);
      adj[2*v+1].push_back(2*u);
    }
  }

  for(int i=1; i<=m; i++) {
    if(!vis[2*i]) scc[2*i] = ++sccn, dfs(2*i);
    if(!vis[2*i+1]) scc[2*i+1] = ++sccn, dfs(2*i+1);
  }

  bool ans = true;
  for(int i=1; i<=m; i++) ans = ans and scc[2*i] != scc[2*i+1];

  printf("%s\n", ans ? "YES" : "NO");

	return 0;
}

