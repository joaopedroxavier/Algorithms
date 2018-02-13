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

int n, m, vis[N], par[N];
int curpar[N];
vector<int> adj[N];
vector<int> ans;

void dfs(int u, int p) {
  vis[u] = 1;

  ans.pb(u);
  curpar[u] ^= 1;
  for(int v : adj[u]) if(!vis[v]) {
    dfs(v, u);
  }

  if(~p and curpar[u] != par[u]) {
    ans.pb(p);
    ans.pb(u);
    curpar[u] ^= 1;
    curpar[p] ^= 1;
  }

  if(~p) ans.pb(p), curpar[p] ^= 1;
}

int main(){
  scanf("%d %d", &n, &m);

  for(int i=0; i<m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);

    adj[u].pb(v); adj[v].pb(u);
  }

  for(int i=1; i<=n; i++) scanf("%d", &par[i]);

  int root = -1;
  for(int i=1; i<=n; i++) if(par[i]) {
    root = i;
    dfs(i, -1);
    break;
  }

  if(~root) {
    if(curpar[root] != par[root]) ans.pop_back(), curpar[root] ^= 1;
    for(int i=1; i<=n; i++) if(curpar[i] != par[i]) return printf("-1\n"), 0;
    printf("%d\n", (int)ans.size());
    for(int i : ans) printf("%d ", i);
    printf("\n");
  }

  else {
    printf("0\n");
  }

  return 0;
}

