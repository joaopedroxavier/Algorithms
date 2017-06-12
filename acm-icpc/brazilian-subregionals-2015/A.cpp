#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define fst first
#define snd second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<pair<int,int>,int> iii;


const long double EPS = 1e-9;
const int N=1e4+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int e[N], o[N], wt[N][N], v, c;
vi adj[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin >> c >> v;
  for(int i=0;i<v;++i){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].pb(v), adj[v].pb(u);
    wt[u][v] = wt[v][u] = w;
  }

  memset(e, 63, sizeof(e));
  memset(o, 63, sizeof(o));

  priority_queue<iii> dij;
  dij.push(mp(mp(0,0),1));
  e[1] = 0;
  while(!dij.empty()){
    int u = (dij.top()).snd;
    int w = -(dij.top()).fst.fst;
    int p = (dij.top()).fst.snd;
    dij.pop();
    for(int v : adj[u]){
      if(p%2==1 and e[v] > w + wt[u][v]){
        e[v] = w + wt[u][v];
        dij.push(mp(mp(-e[v],p+1),v));
      }
      else if(p%2==0 and o[v] > w + wt[u][v]){
        o[v] = w + wt[u][v];
        dij.push(mp(mp(-o[v],p+1),v));
      }
    }
  }

  cout << ((e[c] < INF) ? e[c] : -1) << endl;

  return 0;
}

