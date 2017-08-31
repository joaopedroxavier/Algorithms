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
const int N=5e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

vector<int> adj[N];
int t[N][N], dur[N][N], vis[N], par[N];
int s[N], p[N], f[N], h[N];
int n, m, x;

bool match(int u){
  if(vis[u] == x) return false;
  vis[u] = x;
  for(int v : adj[u]){
    if(!par[v] || match(par[v])) return (par[v] = u);
  }
  return false;
}

int main(){
  while(scanf("%d %d", &n, &m) != EOF){
    for(int i=0;i<=m;i++) adj[i].clear();
    memset(par, 0, sizeof(par));
    memset(vis, 0, sizeof(vis));
    for(int i=1;i<=n;i++) scanf("%d", &p[i]);
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        scanf("%d", &dur[i][j]);
        if(i!=j) dur[i][j] += p[j];
        t[i][j] = dur[i][j];
      }
    }
    for(int i=1;i<=m;i++){
      scanf("%d %d %d", &s[i], &f[i], &h[i]);
    }
    for(int k=1;k<=n;k++){
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
        }
      }
    }
    for(int i=1;i<=m;i++){
      for(int j=1;j<=m;j++){
        if(h[i] + dur[s[i]][f[i]] + t[f[i]][s[j]] <= h[j] and i != j) adj[i].pb(j);
      }
    }
    int maxmatching = 0;
    x = 0;
    for(int i=1;i<=m;i++) x++, maxmatching += match(i);
    int minpathcover = m - maxmatching;
    printf("%d\n", minpathcover);

  }
	return 0;
}

