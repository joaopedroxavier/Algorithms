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

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, m, d[N], memo[N];
vector<int> adj[N];

int max_conquer(int u) {
  if(~memo[u]) return memo[u];

  memo[u] = 0;
  for(int v : adj[u]) if(adj[v].size() > adj[u].size()) {
    memo[u] = max(memo[u], max_conquer(v));
  }
  return ++memo[u];
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  memset(memo, -1, sizeof memo);

  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++) {
    int u, v; scanf("%d %d", &u, &v);
    u++; v++;
    adj[u].push_back(v); adj[v].push_back(u);
  }
  
  int ans = 0;
  for(int i=1; i<=n; i++) ans = max(ans, max_conquer(i));
  printf("%d\n", ans);

	return 0;
}

