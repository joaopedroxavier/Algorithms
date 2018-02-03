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
const int N=4e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m, t = 1;
int v[N], lz[4*N], st[4*N], tin[N], tout[N], vis[N];
vi adj[N], walk, ewalk;

void dfs(int u) {
  vis[u] = 1;
  tin[u] = t++; walk.pb(v[u]); ewalk.pb(u);
  for(int v : adj[u]) if(!vis[v]) dfs(v);
  tout[u] = t++; walk.pb(v[u]); ewalk.pb(u);
}

void build(int p, int l, int r) {
  if(l == r) { st[p] = walk[l]; return; }

  int m = (l+r)/2;
  build(2*p, l, m);
  build(2*p+1, m+1, r);

  st[p] = st[2*p] + st[2*p+1];
}

void push(int p, int l, int r) {
  if(lz[p]) {
    st[p] = (r-l+1) - st[p];

    if(l != r){ lz[2*p] ^= 1; lz[2*p+1] ^= 1; }
    lz[p] = 0;
  }
}

void update(int p, int l, int r, int i, int j) {
  push(p, l, r);
  if(j < l or i > r) return;
  if(l >= i and r <= j) { lz[p] ^= 1; push(p, l, r); return; }

  int m = (l+r)/2;
  update(2*p, l, m, i, j);
  update(2*p+1, m+1, r, i, j);
  st[p] = st[2*p] + st[2*p+1];
}

int query(int p, int l, int r, int i, int j) {
  push(p, l, r);
  if(j < l or i > r) return 0;
  if(l >= i and r <= j) return st[p];

  int m = (l+r)/2;
  return query(2*p, l, m, i, j) + query(2*p+1, m+1, r, i, j);
}

void pow(int u) { update(1, 1, 2*n, tin[u], tout[u]); }
int get(int u) { return query(1, 1, 2*n, tin[u], tout[u]) / 2; }

int main(){
  scanf("%d", &n);
  walk.pb(0);
  for(int i=2; i<=n; i++) {
    int v;
    scanf("%d", &v);
    adj[v].pb(i); adj[i].pb(v);
  }

  for(int i=1; i<=n; i++) scanf("%d", &v[i]);
  dfs(1);

  build(1, 1, 2*n);
  scanf("%d", &m);
  for(int i=0; i<m; i++) {
    char c[5]; int v;
    scanf("%s %d", c, &v);
    if(c[0] == 'g') printf("%d\n", get(v));
    else pow(v);
  }


	return 0;
}

