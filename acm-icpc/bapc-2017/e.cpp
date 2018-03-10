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

int n, blue, red;
ll x[N], y[N];

vector<int> adj[N];
int w, vis[N], b[N];

ll dist(int i, int j) {
  return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

bool match(int u) {
  if(vis[u] == w) return 0;
  vis[u] = w;
  for(int v : adj[u])
    if(!b[v] or match(b[v])) return b[v] = u;
  return 0;
}

bool check(ll d) {
  for(int i=1; i<=red+blue; i++) adj[i].clear();
  memset(b, 0, sizeof b);
  memset(vis, 0, sizeof vis);

  for(int i=1; i<=blue; i++) {
    for(int j=blue+1; j<=blue+red; j++) if(dist(i,j) < d) {
      adj[i].pb(j); adj[j].pb(i);
    }
  }

  int mcbm = 0;
  for(int i=1; i<=blue; i++) ++w, mcbm += match(i);
  return red+blue-mcbm >= n;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d %d", &n, &blue, &red);
  for(int i=1; i<=blue+red; i++) {
    scanf("%lld %lld", &x[i], &y[i]);
  }

  ll l = 0, r = 1e18;
  while(l < r) {
    ll m = (l+r+1)/2;
    if(check(m)) l = m;
    else r = m-1;
  }

  ld ans = l;
  ans = sqrt(ans);
  printf("%.12Lf\n", ans);
	return 0;
}

