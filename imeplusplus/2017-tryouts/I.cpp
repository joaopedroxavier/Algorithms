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

vi sons[N], dads[N];
int anc[N], desc[N], vis[N], tin[N], tout[N];
map<ii, int> check;
int a, b, e, p, cnt, x;

void dfs(int u, int x){
  cnt++, vis[u] = x;
  for(int v : sons[u]) if(vis[v] != x) dfs(v, x);
}
void dfss(int u, int x){
  cnt++, vis[u] = x;
  for(int v : dads[u]) if(vis[v] != x) dfss(v, x);
}

int main(){
  ios_base::sync_with_stdio(false);
  while(1){
    cin >> a >> b >> e >> p;
    if(cin.eof()) break;
    for(int i=0;i<e;++i) sons[i].clear(), dads[i].clear();
    memset(vis, 0, sizeof(vis));
    for(int i=0;i<p;++i){
      int u, v;
      cin >> u >> v;
      sons[u].pb(v), dads[v].pb(u);
    }

    for(int i=0;i<e;++i){
      cnt = 0;
      x++;
      dfs(i, x);
      desc[i] = cnt-1;
    }
    for(int i=0;i<e;++i){
      cnt = 0;
      x++;
      dfss(i, x);
      anc[i] = cnt-1;
    }

    int ans1 = 0, ans2 = 0, ans3 = 0;
    for(int i=0;i<e;++i){
      if(anc[i] >= b) ans3++;
      if(desc[i] >= e-b) ans2++;
      if(desc[i] >= e-a) ans1++;
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;
  }
	return 0;
}

