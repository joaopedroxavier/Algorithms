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
typedef pair<ll, ll> pll;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll ds[N], dt[N];
vector<int> adj[N], ch[N];
map<ii, ll> wt;
int n, m, s, t, par[N], vis[N], nxt[N];

void dij(ll* dist, int sc) {
  priority_queue<pair<ll, int>> pq;
  pq.push({0, sc}); dist[sc] = 0;
  while(!pq.empty()) {
    auto t = pq.top();
    ll d = -t.st; int u = t.nd;

    pq.pop();

    for(int v : adj[u]) {
      int w = wt[mp(u,v)];
      if(dist[v] > d + w) {
        dist[v] = d + w;
        if(sc == s) par[v] = u;
        pq.push({-dist[v], v});
      }
    }
  }
}

ll mi = LINF, ma;
int x;

void dfs(int u, int fb) {
  if(u == fb) return;
  vis[u] = x;

  for(int v : ch[u]) if(!vis[v]) {
    dfs(v, fb);
  }
}

vector<int> gr[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);
  scanf("%d %d", &s, &t);

  for(int i=0; i<m; i++) {
    int u, v, w; scanf("%d %d %d", &u, &v, &w);
    adj[u].push_back(v);
    adj[v].push_back(u);
    wt[mp(u,v)] = wt[mp(v,u)] = w;
  }

  memset(ds, 63, sizeof ds);
  memset(dt, 63, sizeof dt);

  dij(ds, s);

  for(int i=1; i<=n; i++) if(par[i]) ch[par[i]].push_back(i);

  int v = t;
  while(v != s) {
    nxt[par[v]] = v;
    v = par[v];
  }

  dij(dt, t);

  for(int i=1; i<=n; i++) {
    for(int v : ch[i]) par[v] = i;
  }

  v = s;
  while(v != t) {
    x++;
    dfs(v, nxt[v]);
    v = nxt[v];
  }
  x++; dfs(v, 0);

  for(int i=1; i<=n; i++) gr[vis[i]].push_back(i);

  /*
  for(int i=1; i<=x; i++) {
    printf("%d: ", i);
    for(int v : gr[i]) printf("%d ", v);
    printf("\n");
  }

  for(int i=1; i<=n; i++) {
    printf("ds %d %lld\n", i, ds[i]);
  }

  for(int i=1; i<=n; i++) {
    printf("dt %d %lld\n", i, dt[i]);
  }
  */

  // pistolei
  multiset<pll> pr;
  map<ll, ll> qt;
  for(int i=1; i<x; i++) {
    while(!pr.empty() and (*pr.begin()).st <= i) {
      ll num = (*pr.begin()).nd;
      pr.erase(pr.begin());
      qt[num]--;
      if(qt[num] == 0) qt.erase(num);
    }
    for(int u : gr[i]) {
      for(int v : adj[u]) {
        if(nxt[u] != v and vis[v] > vis[u]) {
          ll term = ds[u] + wt[mp(u,v)] + dt[v];
          //printf("%d %d %lld\n", u, v, term);
          pr.insert(mp(vis[v], term));
          qt[term]++;
        }
      }
    }
    ll num = (qt.begin())->st;
    ma = max(ma, pr.empty() ? LINF : num);
  }

  printf("%lld\n", ma == LINF ? -1 : ma);

  return 0;
}

