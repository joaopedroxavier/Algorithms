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

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

struct Edge {
  int u, v;
  ll wt;
};

int t, n, q, anc[N][20], h[N], vis[N];
int u, v;
ll extra, d[N];
vector<Edge> adj[N];

int par[N], sz[N];

int find(int p) { return par[p] == p ? p : par[p] = find(par[p]); }

bool unite(int a, int b) {
  a = find(a), b = find(b);
  if(a == b) return false;

  if(sz[a] > sz[b]) swap(a, b);
  sz[b] += sz[a]; par[a] = b;

  return true;
}

void dfs(int u) {
  vis[u] = 1;

  for(Edge e : adj[u]) if(!vis[e.v]) {
    anc[e.v][0] = u;

    d[e.v] = d[u] + e.wt;
    h[e.v] = h[u] + 1;

    dfs(e.v);
  }
}

void move_up(int &a, int ht) {
  for(int i=0; i<19; i++) if(ht & (1<<i)) {
    a = anc[a][i];
  }
}

int lca(int a, int b) {
  if(h[a] < h[b]) swap(a, b);

  move_up(a, h[a] - h[b]);

  if(a == b) return a;

  for(int i=19; i>=0; i--) if(anc[a][i] != anc[b][i]) {
    a = anc[a][i];
    b = anc[b][i];
  }

  return anc[a][0];
}

ll dist(int a, int b) {
  return d[a] + d[b] - 2*d[lca(a,b)];
}

ll query(int a, int b) {
  ll straight = dist(a, b);
  ll other = extra + min(dist(a, u) + dist(v, b), dist(a, v) + dist(u, b));
  return min(straight, other);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &t);

  while(t--) {
    memset(vis, 0, sizeof vis);

    scanf("%d %d", &n, &q);

    for(int i=1; i<=n; i++) {
      adj[i].clear();
      par[i] = i, sz[i] = 1;
    }

    for(int i=0; i<n; i++) {
      int a, b; ll w;
      scanf("%d %d %lld", &a, &b, &w);

      if(unite(a, b)) {
        adj[a].push_back({a, b, w});
        adj[b].push_back({b, a, w});
      }
      else {
        extra = w;
        u = a; v = b;
      }
    }

    dfs(1);

    for(int i=1; i<20; i++) {
      for(int j=1; j<=n; j++) anc[j][i] = anc[anc[j][i-1]][i-1];
    }

    for(int i=0; i<q; i++) {
      int a, b; scanf("%d %d", &a, &b);
      printf("%lld\n", query(a,b));
    }
  }
	return 0;
}

