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

const int N = 2e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, vis[N], a[N];
vector<int> adj[N];
ll c[N], dp[N];

set<int> cur, used;
ll mi = INF;
int cnt;

void dfs(int u) {
  if(cur.count(u)) return;
  cur.insert(u);

  mi = min(mi, c[u]);
  dfs(a[u]);
}

void fill(int u) {
  if(vis[u]) return;
  vis[u] = 1;

  for(int v : adj[u]) fill(v);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%lld", &c[i]);

  for(int i=1; i<=n; i++) {
    scanf("%d", &a[i]);
    adj[i].push_back(a[i]);
    adj[a[i]].push_back(i);
  }

  ll ans = 0;
  for(int i=1; i<=n; i++) if(!vis[i]) {
    int l = i, r = a[i];
    while(l != r) {
      l = a[l];
      r = a[a[r]];
    }

    mi = INF;
    dfs(l);
    fill(l);

    ans += mi;
  }

  printf("%lld\n", ans);

  return 0;
}

