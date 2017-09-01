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

int vis[N], p[N], n, m, x;
bool can;
vi adj[N];

void dfs(int u){
  vis[u] = 1;
  if(u == 1) can = true;
  for(int v : adj[u]) if(!vis[v]) dfs(v);
}

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i=1;i<=n;i++){
    int u;
    cin >> u;
    p[u] = i;
  }

  cin >> m;
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      int u;
      cin >> u;
      adj[u].pb(j);
    }
  }

  cin >> x;
  dfs(p[x]);
  cout << ((can) ? "YES" : "NO") << endl;
	return 0;
}
