#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e6+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, k, vis[N], par[N];
vector<int> adj[N];
int lift[N][25], add[N];
int stay = 0;

void dfs(int u) {
  vis[u] = 1;
  for(int v : adj[u]) if(!vis[v]) par[v] = u, dfs(v);
}

bool can_add(int u) {
  int amount = 0;
  for(int i=24; i>=0; i--) {
    int p = lift[u][i];
    if(p and !add[p]) {
      amount += 1<<i;
      u = p;
    }
  }
  return stay + amount + 1 <= n - k;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &k);

  for(int i=1; i<n; i++) {
    int u, v; scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(n);
  for(int i=1; i<=n; i++) lift[i][0] = par[i];
  
  for(int i=1; i<25; i++) {
    for(int j=1; j<=n; j++) lift[j][i] = lift[lift[j][i-1]][i-1];
  }

  add[n] = 1, stay = 1;
  for(int i=n-1; i>0; i--) if(!add[i] and can_add(i)) {
    int p = i;
    while(!add[p]) {
      add[p] = 1;
      p = lift[p][0];
      stay++;
    }
  }

  vector<int> ans;
  for(int i=1; i<=n; i++) if(!add[i]) ans.push_back(i);

  for(int i : ans) printf("%d ", i);
  printf("\n");

	return 0;
}

