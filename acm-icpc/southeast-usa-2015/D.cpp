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

ll y[N], x[N], r[N];
vi adj[N];
int color[N], vis[N];
bool deu_ruim;
int n;

ll dist(int i, int j){ return (y[j]-y[i])*(y[j]-y[i]) + (x[j]-x[i])*(x[j]-x[i]); }

ll gcd(ll a, ll b){ return (b == 0) ? a : gcd(b, a%b); }

void dfs(int x, int c){
  vis[x] = 1;
  if(color[x] == 2) color[x] = c;
  for(int y : adj[x]){
    if(!vis[y]) dfs(y, (c+1)%2);
    else if(color[y] != (c+1)%2){
      deu_ruim = true;
      return;
    }
  }
}

int main(){
  while(scanf("%d", &n) != EOF){
    for(int i=0;i<=n;++i) adj[i].clear();
    memset(vis, 0, sizeof(vis));

    for(int i=1;i<=n;++i) scanf("%lld %lld %lld", &x[i], &y[i], &r[i]);
    for(int i=1;i<=n;++i){
      for(int j=1;j<=n;++j){
        if(dist(i,j) == (r[i]+r[j])*(r[i]+r[j])) adj[j].pb(i), adj[i].pb(j);
      }
    }
    for(int i=1;i<=n;++i) color[i] = 2;
    deu_ruim = false;
    dfs(1, 0);
    ll g = gcd(r[n], r[1]);
    if(deu_ruim) printf("-1\n");
    else if(!vis[n]) printf("0\n");
    else printf("%lld %lld\n", r[n]/g, ((color[1] == color[n]) ? r[1]/g : -r[1]/g));
  }
  return 0;
}

