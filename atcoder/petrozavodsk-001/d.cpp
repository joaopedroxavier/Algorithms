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
const ll LINF=0x3f3f3f3f3f3f3f3f;

int n, m;
ll cc, mi[N], best[N], vis[N], cst[N], ord[N];
set<int> thebest;
vi adj[N];

void dfs(int u) {
  vis[u] = cc;
  if(cst[u] < mi[cc]) {
    best[cc] = u;
    mi[cc] = cst[u];
  }
  for(int v : adj[u]) if(vis[v] != cc) dfs(v);
}

int main(){
  scanf("%d %d", &n, &m);

  for(int i=0; i<n; i++) scanf("%lld", &cst[i]), mi[i] = LINF, ord[i] = i;

  memset(vis, -1, sizeof vis);

  for(int i=0; i<m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].pb(v), adj[v].pb(u);
  }

  for(int i=0; i<n; i++) if(vis[i] == -1) {
    dfs(i);
    cc++;
  }

  for(int i=0; i<cc; i++) thebest.insert(best[i]);

  if(2*(cc-1) > n) return printf("Impossible\n"), 0;

  sort(mi, mi+cc);
  sort(ord, ord+n, [](int i, int j) { return cst[i] < cst[j]; });

  ll ans = 0;
  ll need = 2*(cc-1);
  for(int i=0; i<cc; i++) if(need) ans += mi[i], need--;
  for(int i=0; i<n; i++) if(need > 0 and !thebest.count(ord[i])){
    need--;
    ans += cst[ord[i]];
  }

  printf("%lld\n", ans);

  return 0;
}

