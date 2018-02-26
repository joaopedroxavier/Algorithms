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
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m, s;
int evn[N], odd[N], pevn[N], podd[N];
vector<int> adj[N], adjt[N];
int ord[N], ordn, scc[N], sccn, vis[N];
map<int, int> sccsize;

void dfs(int u) {
  vis[u] = 1;
  for(int v : adj[u]) if(!vis[v]) dfs(v);
  ord[ordn++] = u;
}

void dfst(int u) {
  vis[u] = 0;
  for(int v : adjt[u]) if(vis[v]) dfst(v);
  scc[u] = sccn;
}

int main(){
  scanf("%d %d", &n, &m);

  for(int i=1; i<=n; i++) {
    int t;
    scanf("%d", &t);

    for(int j=0; j<t; j++) {
      int u;
      scanf("%d", &u);
      adj[i].pb(u);
      adjt[u].pb(i);
    }
  }

  sccn = ordn = 1;
  for(int i=1; i<=n; i++) if(!vis[i]) dfs(i);
  for(int i=n; i>0; i--) if(vis[ord[i]]) dfst(ord[i]), sccn++;

  scanf("%d", &s);

  memset(evn, 63, sizeof evn);
  memset(odd, 63, sizeof odd);

  priority_queue<ii> pq;
  pq.push(mp(0, s)); podd[s] = 0; pevn[s] = 0; evn[s] = 0;

  while(!pq.empty()) {
    int d = -pq.top().first;
    int u = pq.top().second;

    pq.pop();

    if(d&1) {
      for(int v : adj[u]) if(evn[v] > d + 1) {
        evn[v] = d + 1;
        pevn[v] = u;
        pq.push(mp(-(d+1), v));
      }
    }
    else {
      for(int v : adj[u]) if(odd[v] > d + 1) {
        odd[v] = d + 1;
        podd[v] = u;
        pq.push(mp(-(d+1), v));
      }
    }
  }

  for(int i=1; i<=n; i++) if(adj[i].empty() and podd[i]) {
    int u = i; int cnt = 1;
    vector<int> ans;

    while(u) {
      ans.pb(u);
      if(u == s and ans.size() % 2 == 0) break;
      if(cnt == 1) u = podd[u];
      else u = pevn[u];
      cnt ^= 1;
    }

    reverse(ans.begin(), ans.end());
    printf("Win\n");
    for(int i : ans) printf("%d ", i);
    printf("\n");
    return 0;
  }

  for(int i=1; i<=n; i++) sccsize[scc[i]]++;

  for(int i=1; i<=n; i++) if(sccsize[scc[i]] > 1 and (pevn[i] or podd[i])) {
    printf("Draw\n");
    return 0;
  }

  printf("Lose\n");

	return 0;
}

