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
const int N=2e2+20;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, x[N], y[N];
int t, ans, vis[N], b[N];
vector<int> adj[N];

bool match(int u) {
  if(vis[u] == t) return 0;
  vis[u] = t;

  for(int v : adj[u])
    if(!b[v] or match(b[v])) return b[v] = u;

  return 0;
}

bool can_go(int i, int j, int k) { return abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k; }

bool check(int m) {
  for(int i=1; i<=2*n; i++) adj[i].clear();
  memset(vis, 0, sizeof vis);
  memset(b, 0, sizeof b);

  for(int i=1; i<=n; i++) {
    for(int j=n+1; j<=2*n; j++) if(can_go(i, j, m)) {
      adj[i].pb(j); adj[j].pb(i);
    }
  }

  t = 0; ans = 0;
  for(int i=1; i<=n; i++) ++t, ans += match(i);

  return ans == n;
}

int main(){
  scanf("%d", &n);

  for(int i=1; i<=n; i++) scanf("%d %d", &x[i], &y[i]);
  for(int i=n+1; i<=2*n; i++) scanf("%d %d", &x[i], &y[i]);

  int l = 0, r = 1e9;
  while(l < r) {
    int m = (l+r)/2;
    if(check(m)) r = m;
    else l = m+1;
  }

  printf("%d\n", l);

	return 0;
}

