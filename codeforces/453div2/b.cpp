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

int n, cl[N], vis[N]; 
vector<int> adj[N];
int ans;

void dfs(int u, int c) {
  vis[u] = 1;
  if(cl[u] == c) {
    for(int v : adj[u]) if(!vis[v]) dfs(v, c);
  }
  else {
    ans++;
    for(int v : adj[u]) if(!vis[v]) dfs(v, cl[u]);
  }
}

int main(){
  scanf("%d", &n);
  for(int i=2; i<=n; i++) {
    int u;
    scanf("%d", &u);
    adj[i].pb(u); adj[u].pb(i);
  }

  for(int i=1; i<=n; i++) scanf("%d", &cl[i]);
  dfs(1,0);
  printf("%d\n", ans);

	return 0;
}

