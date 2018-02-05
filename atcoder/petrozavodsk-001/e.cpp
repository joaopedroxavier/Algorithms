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

vi adj[N];
int n, vis[N], leaves[N], f[N], paths[N];
int ans;

int dfs(int u) {
  vis[u] = 1;
  for(int v : adj[u]) if(!vis[v]) {
    leaves[u] += dfs(v);
  }

  leaves[u] += (adj[u].size() == 1);
  return leaves[u];
}

void get_ans(int u) {
  vis[u] = 1;
  if(adj[u].size() <= 2) paths[u] = 1;

  for(int v : adj[u]) if(!vis[v]) {
    get_ans(v);
    paths[u] = paths[u] and paths[v];
    f[u] += paths[v];
  }
}

int main(){
  scanf("%d", &n);
  for(int i=1; i<n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].pb(v); adj[v].pb(u);
  }

  bool path = true; int l = 0;
  for(int i=0; i<n; i++) path = path and (adj[i].size() == 2 or adj[i].size() == 1);
  for(int i=0; i<n; i++) l += (adj[i].size() == 1);
  if(path and l == 2) return printf("1\n"), 0; 

  int root;
  for(int i=0; i<n; i++) if(adj[i].size() > 2){
    root = i;
  }

  get_ans(root);
  ans = 0;
  for(int i=0; i<n; i++) ans = ans + max(0, f[i] - 1);

  printf("%d\n", ans);

  return 0;
}

