//
// 내가 나인 게 싫은 날
// 영영 사라지고 싶은 날
// 문을 하나 만들자 너의 맘 속에다
// 그 문을 열고 들어가면
// 이 곳이 기다릴 거야
// 믿어도 괜찮아 널 위로해줄 magic shop
//
#include <bits/stdc++.h>

using namespace std;

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

int vis[N], h[N], par[N];
ll n, dp[N], sz[N], wt[N];

vector<int> adj[N];

ll dfs(int u) {
  vis[u] = 1;

  vector<ll> sub;
  for(int v : adj[u]) if(!vis[v]) {
    par[v] = u;
    h[v] = h[u] + 1;

    sz[u] += dfs(v);
    sub.push_back(sz[v]);
  }

  sub.push_back(n-sz[u]-1);
  while(sub.size() < 3) sub.push_back(0);

  ll a = sub[0], b = sub[1], c = sub[2];
  dp[u] = 2 * (a*b + b*c + a*c) + 2 * (n-1) + 1;

  sz[u]++; return sz[u];
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  int t; scanf("%d", &t);

  while(t--) {
    memset(vis, 0, sizeof vis);
    memset(sz, 0, sizeof sz);

    scanf("%lld", &n);
    for(int i=1; i<=n; i++) {
      adj[i].clear();
      scanf("%lld", &wt[i]);
    }

    for(int i=1; i<n; i++) {
      int u, v; scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    if(n == 1) {
      if(wt[1] == 0) printf("0\n");
      else printf("1 1\n");
      continue;
    }

    dfs(1);

    ll ans = 0;
    for(int i=1; i<=n; i++) ans += dp[i] * wt[i];

    if(ans == 0) {
      printf("0\n");
      continue;
    }
    else {
      int best = 1;
      int div = 0;
      for(int i=1; i<=n; i++) {
        if(h[i] > h[best]) best = i;
        if(abs(ans) % abs(dp[i]) == 0) div = i;
      }
      if(div) {
        printf("1 %d\n", div);
      }
      else {
        printf("2 %d %d\n", best, par[best]);
      }
    }
  }

	return 0;
}

