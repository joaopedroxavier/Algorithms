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

int a[N], dp[N], vis[N], n;
set<int> g[N];
vector<int> adj[N];

int gcd(int a, int b){ return b ? gcd(b,a%b) : a; }

void dfs(int u){
  vis[u] = 1;
  for(int v : adj[u]) if(!vis[v]){
    set<int> s = g[u];
    dp[v] = gcd(a[v], dp[u]);
    for(auto it : s) g[v].insert(gcd(a[v], it));
    g[v].insert(dp[u]);
    dfs(v);
  }
}

int main(){
  scanf("%d", &n);
  for(int i=1;i<=n;i++) scanf("%d", &a[i]);
  for(int i=1;i<n;i++){
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].pb(v), adj[v].pb(u);
  }
  dp[1] = a[1], g[1].insert(a[1]), g[1].insert(0);
  dfs(1);
  for(int i=1;i<=n;i++) printf("%d%c", *prev(g[i].end()), (i == n) ? '\n' : ' ');

	return 0;
}

