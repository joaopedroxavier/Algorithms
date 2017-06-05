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
const int N=1e4+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

vi adj[N];
int wt[N][N];
map<ii, bool> bridge;
int depth[N], cycle[N], vis[N];
int x, m, ans, len, src;
int par[N], art[N], low[N], num[N], ch[N], cnt;

void tarjan(int u) {
  low[u] = num[u] = ++cnt;
  for (int v : adj[u]) {
    if (!num[v]) {
      par[v] = u; ch[u]++;
      tarjan(v);
      if (low[v] >= num[u]) art[u] = 1;
      if(low[v] > num[u]) bridge[mp(u,v)] = bridge[mp(v,u)] = true;
      low[u] = min(low[u], low[v]);
    }
    else if (v != par[u]) low[u] = min(low[u], num[v]);
  }
}

int find_cycle_length(int u, int p){
  vis[u] = 1;
  for(int v : adj[u]){
    if(v != p and v == src){
      len += wt[u][v];
      cycle[u] = len;
      return cycle[u];
    }
    if(!bridge[mp(u,v)] and v != p){
      len += wt[u][v];
      cycle[u] = find_cycle_length(v, u);
      return cycle[u];
    }
  }
}

void gen_depth(int src){
  priority_queue<ii> dij;
  dij.push(mp(0,src));
  depth[src] = 0;
  while(!dij.empty()){
    int w = -dij.top().first;
    int u = dij.top().second;
    dij.pop();
    for(int v : adj[u]){
      if(depth[v] > w + wt[u][v]) depth[v] = w + wt[u][v], dij.push(mp(-depth[v], v));
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  while(1){
    memset(cycle, 0, sizeof(cycle));
    memset(vis, 0, sizeof(vis));
    memset(par, 0, sizeof(par));
    memset(num, 0, sizeof(num));
    for(int i=0;i<N;++i) adj[i].clear();
    bridge.clear();

    int s, t;
    cin >> s >> t;
    if(cin.eof()) break;

    for(int i=0;i<t;++i){
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].pb(v), adj[v].pb(u);
      wt[u][v] = wt[v][u] = w;
    }

    for (int i = 1; i <= s; ++i) if (!num[i])
      tarjan(i), art[i] = ch[i]>1;

    for (int i = 1; i <= s; ++i) if (!vis[i])
      src = i, len = 0, find_cycle_length(i, i);

    int q;
    cin >> q;
    for(int i=0;i<q;++i){
      ans = INF;
      cin >> x >> m;
      memset(depth, 63, sizeof(depth));
      gen_depth(x);
      for(int i=1;i<=s;++i) if(cycle[i] and cycle[i] >= m){
        ans = min(ans, 2*depth[i]+cycle[i]);
      }
      cout << ((ans == INF) ? -1 : ans) << endl;
    }
  }
  return 0;
}

