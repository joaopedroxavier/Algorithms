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

const int N = 2e6+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, a[N], b[N], vis[N];
int val[N], t;
int v, e, d[N];
vector<int> adj[N], av;

void dfs(int u) {
  vis[u] = 1;
  av.push_back(u); v++;
  for(int v : adj[u]) {
    e++;
    if(!vis[v]) dfs(v);
  }
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);

  vector<int> ord;
  for(int i=0; i<n; i++) {
    scanf("%d %d", &a[i], &b[i]);

    ord.push_back(a[i]);
    ord.push_back(b[i]);
  }

  sort(ord.begin(), ord.end());
  ord.resize(unique(ord.begin(), ord.end()) - ord.begin());
  t = ord.size();

  for(int i=0; i < (int) ord.size(); i++) {
    val[i] = ord[i];
  }
  for(int i=0; i<n; i++) {
    a[i] = lower_bound(ord.begin(), ord.end(), a[i]) - ord.begin();
    b[i] = lower_bound(ord.begin(), ord.end(), b[i]) - ord.begin();
  }

  for(int i=0; i<n; i++) {
    adj[a[i]].push_back(b[i]);
    adj[b[i]].push_back(a[i]);
  }

  int ans = 0;
  for(int i=0; i<t; i++) if(!vis[i]) {
    v = 0, e = 0;
    dfs(i);
    e /= 2;
    //printf("%d %d\n", v, e);
    if(v < e) return printf("-1\n"), 0;

    sort(av.begin(), av.end());
    ans = max(ans, av[e-1]);
    av.clear();
  }

  printf("%d\n", val[ans]);

  return 0;
}

