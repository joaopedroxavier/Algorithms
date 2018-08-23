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

int n, m, k;
vector<int> adj[N];
int cnt[N];
bool used[N], vis[N];
map<ii, int> idx;
ii ed[N];

bool fix(int u) {
  vis[u] = 1;
  for(int v : adj[u]) if(!vis[v]) {
    ii e = {u, v};
    if(!fix(v)) used[idx[e]] = !used[idx[e]], cnt[u]++;
  }
  return !(cnt[u] & 1);
}


int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d %d", &n, &m, &k);
  for(int i=0; i<m; i++) {
    int u, v; scanf("%d %d", &u, &v);
    cnt[u]++; cnt[v]++;
  }
  for(int i=0; i<k; i++) {
    int u, v; scanf("%d %d", &u, &v);
    adj[u].push_back(v); adj[v].push_back(u);
    idx[mp(u,v)] = idx[mp(v,u)] = i;
    ed[i] = {u, v};
  }

  bool ans = true;
  for(int i=1; i<=n; i++) if(!vis[i]) ans = ans and fix(i);

  if(!ans) return printf("NO\n"), 0;

  int amt = 0;
  for(int i=0; i<k; i++) if(used[i]) amt++;

  printf("YES\n%d\n", amt);
  for(int i=0; i<k; i++) if(used[i]){
    printf("%d %d\n", ed[i].st, ed[i].nd);
  }
	return 0;
}

