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

int n, x = 1, vis[N], a[N];
int u[N], sieve[N];
ll h[N], ans[N];
ll cnt;
vector<int> adj[N];
vector<int> nodes[N];

void dfs(int u, int i) {
  cnt++;
  vis[u] = x;
  for(int v : adj[u]) if(a[v] % i == 0 and vis[v] != x) dfs(v, i);
}

int mob(int u) {
  int cnt = 0;
  while(u > 1) {
    int v = u/sieve[u];
    if(sieve[v] == sieve[u]) return 0;
    u = v;
    cnt++;
  }
  return cnt & 1 ? -1 : 1;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);

  for(int i=1; i<=n; i++) {
    scanf("%d", &a[i]);
    for(int j=1; j*j <= a[i]; j++) if(a[i] % j == 0) {
      nodes[j].push_back(i);
      if(j*j != a[i]) nodes[a[i]/j].push_back(i);
    }
  }

  for(int i=1; i<n; i++) {
    int u, v; scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i=2; i<N; i++) if(!sieve[i]) {
    sieve[i] = i;
    for(int j=2*i; j<N; j+=i) sieve[j] = i;
  }

  for(int i=1; i<N; i++) {
    u[i] = mob(i);
  }

  for(int i=1; i<=2e5; i++) {
    for(int u : nodes[i]) if(vis[u] != x) {
      cnt = 0;
      dfs(u, i);
      h[i] += (cnt * (cnt-1)) / 2;
    }
    x++;
  }

  for(int i=1; i<=n; i++) ans[a[i]]++;

  for(int i=1; i<=2e5; i++) {
    for(int j=i; j<=2e5; j+=i) {
      ans[i] += h[j] * u[j/i];
    }
    if(ans[i]) printf("%d %lld\n", i, ans[i]);
  }

  return 0;
}

