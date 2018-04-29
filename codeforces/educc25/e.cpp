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

int n, m, outc[N], ans[N];
vector<int> adj[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++) {
    int u, v; scanf("%d %d", &u, &v);
    adj[v].push_back(u); outc[u]++;
  }

  priority_queue<int> pq;
  for(int i=1; i<=n; i++) if(!outc[i]) pq.push(i);

  int cnt = n;
  while(!pq.empty()) {
    int u = pq.top();
    pq.pop();

    ans[u] = cnt--;
    for(int v : adj[u]) {
      outc[v]--;
      if(!outc[v]) pq.push(v);
    }
  }

  for(int i=1; i<=n; i++) printf("%d ", ans[i]);
  printf("\n");

	return 0;
}

