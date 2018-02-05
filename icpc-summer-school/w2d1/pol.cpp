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
const int N=3e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, sz[N], vis[N], ant[N];
ll ans, diam, cent;
map<int, int> sub;
vector<int> sub_dif;
vi adj[N];

int dfs(int u, int h) {
  vis[u] = 1;
  ans += h;
  for(int v : adj[u]) if(!vis[v]) sz[u] += dfs(v, h+1);
  
  bool iscent = true;
  for(int v : adj[u]) iscent = iscent and sz[v] <= n/2;
  iscent = iscent and n - sz[u] - 1 <= n/2;

  if(iscent) cent = u;
  return sz[u] += 1;
}

void createmap() {
  for(int v : adj[cent]) {
    sub[sz[v]]++;
  }
}

void process() {
  map<int, int> newsub;
  for(auto i : sub) if(i.second > 2) {
    sub[2*i.first] += (sub[i.first] - 1)/2;
    sub[i.first] -= ((sub[i.first] - 1)/2)*2;
  }
  for(auto i : sub) {
    for(int j=0; j<i.second; j++) sub_dif.pb(i.first);
  }
}

void knapsack() {
  bitset<N> fmota;
  fmota[0] = 1;
  for(int i : sub_dif) {
    fmota |= (fmota << i);
  }
  ll ma = 0;
  for(int i=0; i<=(n-1)/2; i++) if(fmota[i]) ma = i;
  ans += ma*(n-ma-1);
}

int main(){
  scanf("%d", &n);

  for(int i=1; i<n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].pb(v), adj[v].pb(u);
  }

  dfs(1, 0);

  ans = 0;
  memset(vis, 0, sizeof vis);
  memset(sz, 0, sizeof sz);

  dfs(cent, 0);
  createmap();
  process();
  knapsack();

  printf("%d %lld\n", n-1, ans);

  return 0;
}

