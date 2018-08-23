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

const int N = 1e6+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

map<int, deque<int>> d;
vector<int> adj[N];
int n, ans[N];
int dom[N], dsup[N];

int find(int p) { return dsup[p] == p ? p : dsup[p] = find(dsup[p]); }

void merge(int u, int v) {
  u = find(u); v = find(v);
  int szu = (int) d[u].size();
  int szv = (int) d[v].size();

  if(szu > szv) swap(u, v), swap(szu, szv);

  for(int i=0; i<szu; i++) {
    d[v][i] += d[u][i];
    if(d[v][i] > d[v][dom[v]] or (i < dom[v] and d[v][i] == d[v][dom[v]])) dom[v] = i;
  }

  dsup[u] = v;
  d[u].clear(); d.erase(u);
}

int compare(int u, int v) {
  u = find(u); v = find(v);
  int szu = (int) d[u].size();
  int szv = (int) d[v].size();

  return szu > szv ? u : v;
}

void dfs(int u, int p) {
  int l = u;
  for(int v : adj[u]) if(v != p) {
    dfs(v, u);
    if(l != u) {
      merge(v, l);
    }
    if(l == u) l = v;
  }

  if(l == u) { d[u].push_back(1); dom[u] = ans[u] = 0; return; }

  l = find(l);
  if(d[l][dom[l]] == 1) { ans[u] = dom[l] = 0; }
  else { ans[u] = dom[l] = dom[l] + 1; }

  dsup[u] = l;

  d[l].push_front(1);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=1; i<n; i++) {
    int u, v; scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1; i<=n; i++) dsup[i] = i;
  dfs(1, 0);
  for(int i=1; i<=n; i++) printf("%d\n", ans[i]);

	return 0;
}

