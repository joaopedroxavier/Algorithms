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

int anc[N][20], n;
ll height[N], depth[N], q;

int msb(int u){
  int b = 0;
  while((1<<b) <= u) b++;
  return b-1;
}

int eq_heights(int u, int v){
  int d = height[u]-height[v];
  while(d){
    u = anc[u][msb(d)];
    d = d - (1<<msb(d));
  }
  return u;
}

int lca(int u, int v){
  if(height[u] < height[v]) swap(u,v);
  u = eq_heights(u, v);
  if(u == v) return u;
  for(int i=19;i>=0;--i){
    if(anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
  }
  u = anc[u][0], v = anc[v][0];
  return u;
}

int main(){
	ios_base::sync_with_stdio(false);
  while(1){
    cin >> n;
    if(n == 0) break;
    memset(height, 0, sizeof(height));
    memset(depth, 0, sizeof(depth));
    memset(anc, 0, sizeof(anc));

    for(int i=1;i<n;++i){
      int v, w;
      cin >> v >> w;
      anc[i][0] = v;
      height[i] = height[v] + 1;
      depth[i] = depth[v] + w;
    }
    
    for(int j=1;j<20;++j){
      for(int i=1;i<n;++i){
        anc[i][j] = anc[anc[i][j-1]][j-1];
      }
    }

    cin >> q;
    for(int i=0;i<q;++i){
      int u, v;
      cin >> u >> v;
      cout << depth[u] + depth[v] - 2*depth[lca(u,v)];
      if(i < q-1) cout << ' ';
    }
    cout << endl;
    
  }
	return 0;
}

