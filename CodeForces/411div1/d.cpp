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

int n, m, q, vis[N];
vector<ll> adj[N], ps[N], dst[N], vtx;
ll par[N], sz[N];

ll d[N][4];
map<ii, double> check;

int find(int u) { return u == par[u] ? u : par[u] = find(par[u]); }

void unite(int u, int v) {
  if((u = find(u)) == (v = find(v))) return;

  if(sz[v] < sz[u]) swap(u, v);
  sz[v] += sz[u]; par[u] = v;
}

int bfs(int a, int t) {
  queue<int> b;
  b.push(a); d[a][t] = 0;
  int last;

  while(!b.empty()) {
    int u = b.front(); last = u;

    vis[u] = t+1; vtx.pb(u);
    b.pop();

    for(int v : adj[u]) if(vis[v] != t+1) {
      b.push(v);
      d[v][t] = d[u][t] + 1;
    }
  }
  return last;
}

int main(){
  scanf("%d %d %d", &n, &m, &q);

  for(int i=1; i<=n; i++) par[i] = i, sz[i] = 1;

  for(int i=0; i<m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);

    adj[u].pb(v); adj[v].pb(u);
    unite(u, v);
  }

  for(int i=1; i<=n; i++) if(i == find(i)){
    vtx.clear();
    int p = i;
    p = bfs(p, 0);
    vtx.clear();
    p = bfs(p, 1);
    vtx.clear();
    p = bfs(p, 2);
    for(int v : vtx) d[v][3] = max(d[v][1], d[v][2]), dst[i].pb(d[v][3]);
    sort(dst[i].begin(), dst[i].end());

    ps[i].pb(dst[i][0]);
    for(int j=1; j < (int) dst[i].size(); j++) {
      ll s = ps[i].back();
      ps[i].pb(s + dst[i][j]);
    }
  }

  for(int i=0; i<q; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u = find(u), v = find(v);

    if(sz[u] > sz[v]) swap(u, v);
    if(u == v) printf("-1\n");
    else if(check.count(mp(u, v))) printf("%.9lf\n", check[mp(u,v)]);
    else {
      ll ans = 0;

      for(ll a : dst[u]) {
        ll maxw = max(dst[u].back(), dst[v].back());
        auto it = lower_bound(dst[v].begin(), dst[v].end(), maxw - a);
        ll p = it - dst[v].begin();
        ans = ans + p * max(dst[u].back(), dst[v].back());
        ans = ans + (a + 1) * ((ll) ps[v].size() - max((ll)0, p)) + ps[v].back() - (p == 0 ? 0 : ps[v][p-1]);
      }
      double expv = ans;
      double div = sz[u] * sz[v];

      printf("%.9lf\n", expv / div);
      check[mp(u,v)] = expv/div;
    }
  }

  return 0;
}


