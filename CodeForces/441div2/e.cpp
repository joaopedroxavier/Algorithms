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
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m;
vector<int> in[N];
bool bad, cap[N];

vi adj[N], adjt[N];
int ord[N], ordn, scc[N], sccn, vis[N], cnt;

void dfs(int u) {
    vis[u] = 1;
      for (int v : adj[u]) if (!vis[v]) dfs(v);
        ord[ordn++] = u;
}

void dfst(int u) {
    vis[u] = 1;
      for (int v : adjt[u]) if (!vis[v]) dfst(v);
        scc[u] = sccn;
}

bool check() {
  sccn = ordn = 1;
  for(int i = 1; i <= m; ++i) {
    if(!vis[2*i]) dfs(2*i);
    if(!vis[2*i+1]) dfs(2*i+1);
  }
  memset(vis, 0, sizeof vis);
  for(int i = 2*m+1; i > 0; --i) {
    if (!vis[ord[i]]) dfst(ord[i]), sccn++;
  }
  for(int i = 1; i <= m; i++) {
    if (scc[2*i] == scc[2*i+1]) return false;
  }
  return true;
}

void dfsp(int u) {
  vis[u] = 1;
  if(u%2 == 0) printf("%d ", u/2);
  for(int v : adj[u]) if(!vis[v]) dfsp(v);
}

void dfsc(int u) {
  vis[u] = 1;
  if(u%2 == 0) cnt++;
  for(int v : adj[u]) if(!vis[v]) dfsc(v);
}

void connect(int i, int j) {
  adj[i].pb(j); adjt[j].pb(i);
}

void process(int i, int j) {
  vector<int> v = in[i], w = in[j];
  for(int p=0; p < (int) v.size(); p++) {
    if(p == (int) w.size()){ bad = true; return; }
    if(v[p] < w[p]){ connect(2*w[p], 2*v[p]); connect(2*v[p]+1, 2*w[p]+1); return; }
    if(v[p] > w[p]){ cap[v[p]] = 1; connect(2*v[p]+1, 2*v[p]), connect(2*w[p], 2*w[p]+1); return; }
  }
}

int main(){
  scanf("%d %d", &n, &m);
  sccn = ordn = 1;

  for(int t, i=0; i<n; i++) {
    scanf("%d", &t);
    for(int u, j=0; j<t; j++) {
      scanf("%d", &u);
      in[i].pb(u);
    }
  }

  for(int i=0; i<n-1; i++) {
    process(i, i+1);
    if(bad) return printf("No\n"), 0;
  }

  bad = !check();
  if(bad) return printf("No\n"), 0;

  printf("Yes\n");

  memset(vis, 0, sizeof vis);
  for(int i=1; i<=m; i++) if(cap[i] and !vis[2*i]) dfsc(2*i);
  printf("%d\n", cnt);

  memset(vis, 0, sizeof vis);
  for(int i=1; i<=m; i++) if(cap[i] and !vis[2*i]) dfsp(2*i);
  if(cnt) printf("\n");

  return 0;
}

