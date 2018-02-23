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
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

struct edge { int v, c, f; };
int n, m, src, snk, ans, h[N], ptr[N];

vector<edge> edgs;
vector<int> g[N];

void add_edge(int u, int v, int c) {
  int k = edgs.size();
  edgs.push_back({v, c, 0});
  edgs.push_back({u, 0, 0});
  g[u].push_back(k);
  g[v].push_back(k+1);
}

bool bfs() {
  memset(h, 0, sizeof h);
  queue<int> q;
  h[src] = 1;
  q.push(src);

  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int i : g[u]) {
      int v = edgs[i].v;
      if(!h[v] and edgs[i].f < edgs[i].c) {
        q.push(v), h[v] = h[u] + 1;
      }
    }
  }
  return h[snk];
}

int dfs(int u, int flow) {
  if(!flow or u == snk) return flow;
  for(int &i = ptr[u]; i < (int) g[u].size(); i++) {
    edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
    int v = dir.v;
    if(h[v] != h[u] + 1) continue;
    int inc = min(flow, dir.c - dir.f);
    inc = dfs(v, inc);
    if(inc) {
      dir.f += inc, rev.f -= inc;
      return inc;
    }
  }
  return 0;
}

int dinic() {
  int flow = 0;
  while(bfs()) {
    memset(ptr, 0, sizeof ptr);
    while(int inc = dfs(src, INF)) flow += inc;
  }
  return flow;
}

int main(){
  scanf("%d %d", &n, &m);


  for(int i=1; i<=n; i++) {
    int u;
    while(scanf("%d", &u), u) add_edge(i, n+u, 1);
  }

  src = 0, snk = n+m+1;

  for(int i=1; i<=n; i++) add_edge(src, i, 1);
  for(int i=1; i<=m; i++) add_edge(n+i, snk, 1);

  ans = dinic();
  printf("%d\n", ans);

  for(int i=0; i < (int) edgs.size(); i++) if(edgs[i].f == 1) {
    int a = edgs[i].v, b = edgs[i^1].v;
    if(a == src or a == snk or b == src or b == snk) continue;
    if(a > n) swap(a, b);
    printf("%d %d\n", a, b-n);
  }

  return 0;
}

