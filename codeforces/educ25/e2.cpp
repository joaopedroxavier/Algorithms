#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

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

int n, m, cnt, cntcc, inc[N], outc[N], ans[N], vis[N];
int cc[N];
vector<int> adj[N], adjt[N];
set<int> ccv[N];

void dfs(int u, int c) {
  ccv[c].insert(u);
  cc[u] = c;
  vis[u] = 1;
  for(int v : adjt[u]) if(!vis[v]){
    dfs(v, c);
  }
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++) {
    int u, v; scanf("%d %d", &u, &v);
    adj[u].push_back(v); inc[v]++;
    adjt[v].push_back(u); outc[u]++;
  }

  for(int i=1; i<=n; i++) if(!vis[i] and !outc[i]) {
    cc[i] = ++cntcc;
    dfs(i, cc[i]);
  }


  for(int i=1; i<=n; i++) if(!ans[i]) {
    int c = cc[i];
    priority_queue<int> pq;
    for(int j : ccv[c]) if(!inc[j]) pq.push(-j);

    while(!pq.empty()) {
      int u = -pq.top();
      pq.pop();

      ans[u] = ++cnt;
      ccv[c].erase(u);
      for(int v : adj[u]) {
        inc[v]--;
        if(!inc[v]) pq.push(-v);
      }
      if(u == i) break;
    }
  }

  for(int i=1; i<=n; i++) printf("%d ", ans[i]);
  printf("\n");

  return 0;
}

