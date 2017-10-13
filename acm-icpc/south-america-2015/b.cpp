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

int x, vis[N], b[N], nodeset[N], notzero;
vi adj[N];

bool match(int u){
  if(vis[u] == x) return 0;
  vis[u] = x;
  for(int v : adj[u]) if(nodeset[v] and (!b[v] or match(b[v]))) return b[v] = u;
  return false;
}

int n, q;

int main(){
  scanf("%d %d", &n, &q);

  for(int i=1; i<=n; i++){
    int s; scanf("%d", &s);
    if(s == n) notzero++;
    nodeset[i] = 1;

    for(int j=1; j<=s; j++){
      int t; scanf("%d", &t);
      adj[i].pb(n+t), adj[n+t].pb(i);
    }

    //if(s != n) for(int j=1; j<=n; j++) adj[i].pb(2*n + j), adj[2*n + j].pb(i);
  }

  for(int i=1; i<=q; i++){
    int s; scanf("%d", &s);
    memset(nodeset, 0, sizeof nodeset);
    memset(b, 0, sizeof b);

    for(int j=1; j<=s; j++){
      int t; scanf("%d", &t);
      nodeset[n+t] = 1;
    }

    for(int j=1; j<=n; j++) nodeset[j] = 1;
    //for(int j=1; j<=n-s; j++) nodeset[2*n + j] = 1;

    int ans = 0;
    for(int j=1; j<=n; j++) x++, ans += match(j);

    if(s == 0) printf("%s\n", notzero ? "N" : "Y");
    else printf("%s\n", ans >= s ? "Y" : "N");
  }

	return 0;
}

