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
typedef pair<int, ii> iii;

const long double EPS = 1e-9;
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, end1, end2, dist[N], vis[N], p[N];
vector<int> adj[N];
vector<iii> ans;
set<int> path;

void shpath(int x) {
  memset(dist, 0, sizeof dist);
  memset(vis, 0, sizeof vis);
  memset(p, 0, sizeof p);

  queue<int> bfs;
  bfs.push(x); dist[x] = 0; end1 = x;

  while(!bfs.empty()) {
    int u = bfs.front();
    vis[u] = 1; end2 = u;
    bfs.pop();
    for(int v : adj[u]) if(!vis[v]) bfs.push(v), p[v] = u, dist[v] = dist[u] + 1;
  }
}

int main(){
  scanf("%d", &n);

  for(int i=1; i<n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].pb(v); adj[v].pb(u);
  }

  shpath(1);
  shpath(end2);

  path.insert(end1);
  for(int u = end2; u != end1; u = p[u]) path.insert(u);

  vector<ii> d1, d2, d;
  for(int i=1; i<=n; i++) d1.pb({dist[i], i});

  shpath(end2);
  for(int i=1; i<=n; i++) d2.pb({dist[i], i});
  for(int i=1; i<=n; i++) d.pb(max(d1[i-1], d2[i-1]));

  sort(d.begin(), d.end(), [](ii a, ii b){ return a > b; });
  ll cost = 0;
  for(ii p : d) if(!path.count(p.second)) {
    int u = p.second, v = p.first;
    cost += v;
    ans.pb({u, {(v == d2[u-1].first ? end1 : end2), u}});
  }

  for(int u = end2; u != end1; u = p[u]) {
    cost += dist[u];
    ans.pb({u, {end1, u}});
  }

  printf("%lld\n", cost);
  for(iii a : ans) {
    printf("%d %d %d\n", a.first, a.second.first, a.second.second);
  }

  return 0;
}

