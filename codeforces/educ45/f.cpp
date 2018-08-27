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

ll f[N], s[N], b[N];
int n, m, vis[N];
vector<int> adj[N];
map<ii, int> edge;

void solve(int u, int v, ll cost) {
  if(!edge.count({u,v})) swap(u,v), cost = -cost;
  ii uv = {u,v};
  f[edge[uv]] = cost;
}

ll dfs(int u) {
  vis[u] = 1;
  int sum = 0;
  for(int v : adj[u]) if(!vis[v]) {
    ll cost = dfs(v);
    sum += cost; solve(u,v,cost);
  }
  sum += s[u]; return sum;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  ll sum = 0;
  for(int i=1; i<=n; i++) scanf("%lld", &s[i]), sum += s[i];

  scanf("%d", &m);
  for(int i=1; i<=m; i++) {
    int u, v; scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    edge[mp(u,v)] = i;
  }
  
  if(sum != 0) return printf("Impossible\n"), 0;

  dfs(1);

  printf("Possible\n");
  for(int i=1; i<=m; i++) printf("%lld\n", f[i]);

	return 0;
}

