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
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int vis[N], par[N];
ll n, sz[N], ans;
vector<int> adj[N];

ll dfs(int u) {
  vis[u] = 1;

  vector<ll> s[5];

  for(int v : adj[u]) {
    if(!vis[v]) {
      par[v] = u;
      ll d = dfs(v);
      sz[u] += d;
    }
  }

  sz[u]++;

  for(int v : adj[u]) {
    if(v == par[u]) s[0].push_back(n-sz[u]);
    else s[0].push_back(sz[v]);
  }

  if(adj[u].size() >= 3) {

    for(int i=1; i<5; i++) s[i].resize(s[0].size());

    s[1][0] = s[0][0];
    for(int i=1; i<(int)s[0].size(); i++) {
      s[1][i] = s[1][i-1] + s[0][i];
    }

    for(int i=2; i<=4; i++) {
      for(int j=0; j<i-1; j++) {
        s[i][j] = 0;
      }
      for(int j=i-1; j<(int)s[i-1].size(); j++) {
        ll d = s[0][j];
        s[i][j] = s[i-1][j-1] * d + s[i][j-1];
      }
    }

    if(adj[u].size() > 3) ans += s[4].back();
    ans += s[3].back();
  }

  return sz[u];
}

ll comb(ll n) {
  if(n < 4) return 0;
  ll p = 1;
  ll ans = 1;
  for(ll i=n; i>=n-3; i--) {
    ans = ans * i;
    while(ans % p == 0 and p < 5) {
      ans /= p;
      p++;
    }
  }
  return ans;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(int i=1; i<n; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);
  ll tot = comb(n);

  cout << 2ll * (tot - ans) << endl;
  return 0;
}

