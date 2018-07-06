//
// Elohim Essaim, Elohim Essaim, I implore you...
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

int x, vis[N], b[N], ans;
vector<int> adj[N];

bool match(int u) {
  if(vis[u] == x) return 0;
  vis[u] = x;
  for(int v : adj[u])
    if(!b[v] or match(b[v])) return b[v] = u;
  return 0;
}

int n, m, t;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  srand(time(0));

  scanf("%d", &t);
  while(t--) {
    memset(vis, 0, sizeof vis);
    memset(b, 0, sizeof b);
    x = 0; ans = 0;
    for(int i=0; i<N; i++) adj[i].clear();

    scanf("%d %d", &m, &n);

    for(int i=1; i<=m; i++) {
      int u, v; scanf("%d %d", &u, &v);
      u++; v++;

      adj[i].push_back(m+u);
      adj[i].push_back(m+v);
      adj[m+u].push_back(i);
      adj[m+v].push_back(i);
    }

    vector<int> v;
    for(int i=1; i<=m+n; i++) v.push_back(i);
    random_shuffle(v.begin(), v.end());

    for(int i : v) ++x, ans += match(i);
    printf("%s\n", ans == 2*m ? "successful hashing" : "rehash necessary");
  }

	return 0;
}

