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

const int N = 2e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, d[N], p[N], db[N], da[N];
vector<int> adj[N];

void dfs(int u) {
  for(int v : adj[u]) {
    dfs(v);
    if(db[v]) d[u]--;
  }
  if(d[u]&1) da[u] = 1;
  else db[u] = 1;
}

void destroy(int u) {
  for(int v : adj[u]) if(db[v]) destroy(v);
  printf("%d\n", u);
  for(int v : adj[u]) if(da[v]) destroy(v);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);

  int rt = 0;
  for(int i=1; i<=n; i++) {
    int u; scanf("%d", &u);
    if(u) {
      adj[u].push_back(i);
      d[u]++; d[i]++;
    } else rt = i;
  }

  dfs(rt);
  if(da[rt]) return printf("NO\n"), 0;

  printf("YES\n");
  destroy(rt);

	return 0;
}

