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
int n, vis[N], f[N][2], t = 3;

void dfs(int u){
  vis[u] = 1;
  bool fst = 1;
  for(int v : adj[u]) if(!vis[v]){
    if(fst) f[v][1] = f[u][0], f[v][0] = t++, fst = false; 
    else f[v][1] = f[u][1], f[v][0] = t++;
    dfs(v);
  }
}

int main(){
  scanf("%d", &n);
  if(n == 2) return printf("1 2\n2 1\n"), 0;
  for(int i=1;i<n;i++){
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].pb(v), adj[v].pb(u);
  }
  f[1][0] = 1, f[1][1] = 2;
  dfs(1);

  for(int i=1;i<=n;i++) printf("%d %d\n", f[i][0], f[i][1]);

	return 0;
}

