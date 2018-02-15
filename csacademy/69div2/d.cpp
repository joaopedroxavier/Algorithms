#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, total, vis[N], sz[N];
int centroid;
vector<int> adj[N], leaves[N];

int dfs(int u) {
  vis[u] = 1;

  bool candidate = true;
  for(int v : adj[u]) if(!vis[v]) {
    sz[u] += dfs(v);
    if(sz[v] > total/2) candidate = false;
  }
  if(total - sz[u] > total/2) candidate = false;

  if(candidate) centroid = u;

  return sz[u] + (adj[u].size() == 1);
}

void get_leaves(int u, int p) {
  vis[u] = 1;
  for(int v : adj[u]) if(!vis[v] and v != centroid) get_leaves(v, p);

  if(adj[u].size() == 1) leaves[p].push_back(u);
}

int main(){
  scanf("%d", &n);

  for(int i=1; i<n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);

    adj[u].push_back(v); adj[v].push_back(u);
  }

  for(int i=1; i<=n; i++) total += (adj[i].size() == 1);

  dfs(1);

  memset(vis, 0, sizeof vis);
  for(int v : adj[centroid]) get_leaves(v, v);

  priority_queue<ii> order;
  for(int v : adj[centroid]) order.push(make_pair(leaves[v].size(), v));

  printf("%d\n", (total+1)/2);

  while(!order.empty()) {
    int u = order.top().second;

    if(order.size() == 1) {
      for(int v : leaves[u]) printf("%d %d\n", v, centroid);
      break;
    }
    order.pop();
    int v = order.top().second;

    order.pop();
    printf("%d %d\n", leaves[u].back(), leaves[v].back());

    leaves[u].pop_back(); leaves[v].pop_back();

    if(!leaves[u].empty()) order.push(make_pair(leaves[u].size(), u));
    if(!leaves[v].empty()) order.push(make_pair(leaves[v].size(), v));
  }

	return 0;
}

