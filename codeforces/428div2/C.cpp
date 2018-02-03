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
long double expected[N];
int vis[N], n;

void dfs(int u){
  vis[u] = 1;
  for(int v : adj[u]){
    if(!vis[v]){
      dfs(v);
      expected[u] += expected[v];
    }
  }
  if(adj[u].size() != 1 and u != 1)
    expected[u] = expected[u] / (adj[u].size()-1) + 1;
  else if(u == 1)
    expected[u] = expected[u] / adj[u].size() + 1;
}

int main(){
  scanf("%d", &n);
  if(n == 1){ printf("0.0000000000\n"); return 0; }
  for(int i=1;i<n;i++){
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].pb(v), adj[v].pb(u);
  }
  dfs(1);
  printf("%.12Lf\n", expected[1]);
	return 0;
}
