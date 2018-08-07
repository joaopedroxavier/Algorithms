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
const int N=5e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m, girth, level[N];
vi adj[N];

int sh_cyclelen(int u){
  int s = INF;
  queue<ii> bfs;
  bfs.push(mp(u,-1));
  level[u] = 1;
  while(!bfs.empty()){
    int v = bfs.front().first;
    int p = bfs.front().second;
    bfs.pop();
    for(int w : adj[v]){
      if(level[w] and w != p) s = min(s, level[v]+level[w]-1);
      else if(!level[w]) level[w] = level[v]+1, bfs.push(mp(w,v));
    }
  }
  return s;
}

int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  for(int q=1;q<=t;++q){
    cin >> n >> m;
    for(int i=0;i<n;++i) adj[i].clear();

    cout << "Case " << q << ": ";
    for(int i=0;i<m;++i){
      int u, v;
      cin >> u >> v;
      adj[u].pb(v), adj[v].pb(u);
    }

    girth = INF;
    for(int i=0;i<n;++i){
      memset(level, 0, sizeof(level));
      int sh = sh_cyclelen(i);
      girth = min(girth, sh);
    }

    if(girth == INF) cout << "impossible" << endl;
    else cout << girth << endl;
  }
  return 0;
}

