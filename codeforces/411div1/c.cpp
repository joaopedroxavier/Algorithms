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
const int N=6e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m, col[N], ord[N], vis[N];
vector<int> ic[N], adj[N];
set<int> av[N];

void paint(int u) {
  for(int v : ic[u]) if(col[v]){
    av[u].erase(col[v]);
  }
  for(int v : ic[u]) if(!col[v]) {
    col[v] = *av[u].begin();
    av[u].erase(col[v]);
  }
}

void dfs(int u) {
  vis[u] = 1;
  paint(u);
  for(int v : adj[u]) if(!vis[v]){
    dfs(v);
  }
}

int main(){
  scanf("%d %d", &n, &m);

  int chn = 0;
  for(int i=1; i<=n; i++) {
    int t;
    scanf("%d", &t);
    chn = max(chn, t);
    for(int j=1; j<=t; j++) {
      int c;
      scanf("%d", &c);


      ic[i].pb(c);
      av[i].insert(j);
    }
  }

  for(int i=1; i<n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].pb(v); adj[v].pb(u);
  }

  dfs(1);

  for(int i=1; i<=m; i++) if(!col[i]) col[i] = 1;

  printf("%d\n", max(1, chn));
  for(int i=1; i<=m; i++) printf("%d ", col[i]);
  printf("\n");

  return 0;
}

