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

ll vis[N], c[N], n, m;
vi adj[N];
ll mincost = INF;

void dfs(int u) {
  vis[u] = 1;
  mincost = min(mincost, c[u]);
  for(int v : adj[u]) if(!vis[v]) dfs(v);
}

int main(){
  scanf("%lld %lld", &n, &m);

  for(int i=1; i<=n; i++) scanf("%lld", &c[i]);

  for(int i=0; i<m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].pb(v), adj[v].pb(u);
  }

  ll ans = 0;
  for(int i=1; i<=n; i++) if(!vis[i]) {
    mincost = INF;
    dfs(i);
    ans += mincost;
  }

  printf("%lld\n", ans);
  

	return 0;
}

