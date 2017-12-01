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
int vis[N], n, t;
ll sum[2];

void dfs(int u, int c){
  vis[u] = 1;
  sum[c]++;
  for(int v : adj[u]) if(!vis[v]) dfs(v, (c+1)%2);
}

int main(){
  scanf("%d", &n);

  for(int i=1; i<n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].pb(v), adj[v].pb(u);
  }
  dfs(1, 0);

  printf("%lld\n", sum[0] * sum[1] - (n-1));

	return 0;
}

