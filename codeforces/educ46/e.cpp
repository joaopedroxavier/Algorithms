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

const int N = 3e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int par[N], art[N], low[N], num[N], ch[N], cnt;
set<ii> bridge;
vector<int> adj[N];

void articulation(int u) {
  low[u] = num[u] = ++cnt;
  for (int v : adj[u]) {
    if (!num[v]) {
      par[v] = u; ch[u]++;
      articulation(v);
      if (low[v] >= num[u]) art[u] = 1;
      if (low[v] >  num[u]) {
        bridge.insert({u,v});
        bridge.insert({v,u});
      }
      low[u] = min(low[u], low[v]);
    }
    else if (v != par[u]) low[u] = min(low[u], num[v]);
  }
}

int x;
int vis[N], visb[N], visc[N];
vector<int> adjc[N];

void dfs(int u) {
  vis[u] = x;
  for(int v : adj[u]) if(!vis[v] and !bridge.count({u,v})) {
    dfs(v);
  }
}

void dfsb(int u) {
  visb[u] = 1;
  for(int v : adj[u]) if(!visb[v]) {
    if(bridge.count({u,v})) {
      int cu = vis[u];
      int cv = vis[v];
      adjc[cu].push_back(cv);
      adjc[cv].push_back(cu);
    }
  }
}

int ans(int u) {
  queue<int> q;
  q.push(u);
  int last;
  while(!q.empty()) {
    int u = q.front();
    visb[u] = 1;
    last = u; q.pop();

    for(int v : adjc[u]) if(!visb[v]) {
      q.push(v);
    }
  }
  q.push(last); visc[last] = 1;
  while(!q.empty()) {
    int u = q.front();
    last = u;
    q.pop();

    for(int v : adjc[u]) if(!visc[v]) {
      visc[v] = visc[u] + 1;
      q.push(v);
    }
  }

  return visc[last] - 1;
}

int n, m;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++) {
    int u, v; scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i = 0; i < n; ++i) if (!num[i]) {
    articulation(i), art[i] = ch[i]>1;
  }

  for(int i=1; i<=n; i++) if(!vis[i]) {
    x++;
    dfs(i);
  }

  for(int i=1; i<=n; i++) if(!visb[i]) {
    dfsb(i);
  }

  int res = 0;
  memset(visb, 0, sizeof visb);
  for(int i=1; i<=n; i++) if(!visc[i]) {
    res = max(res, ans(i));
  }

  printf("%d\n", res);

  return 0;
}

