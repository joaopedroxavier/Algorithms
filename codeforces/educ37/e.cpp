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

int sz[N], par[N], dg[N];
int vis[N];
int n, m;

set<int> nadj[N];

int find(int p) { return par[p] == p ? p : par[p] = find(par[p]); }

void unite(int a, int b) {
  if((a = find(a)) == (b = find(b))) return;

  if(sz[a] > sz[b]) swap(a,b);
  sz[b] += sz[a]; par[a] = b;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);

  for(int i=1; i<=n; i++) {
    par[i] = i;
    sz[i] = 1;
    dg[i] = n;
  }

  for(int i=0; i<n; i++) {
    int u, v; scanf("%d%d", &u, &v);
    dg[u]--; dg[v]--;

    nadj[u].insert(v);
    nadj[v].insert(u);
  }

  int f = 0;
  for(int i=1; i<=n; i++) if(dg[i] >= n/2) {
    if(!f) f = i;
    else unite(i, f);
  }

  for(int i=1; i<=n; i++) if(dg[i] < n/2) {
    for(int j=1; j<=n; j++) if(!nadj[i].count(j)) {
      unite(i,j);
    }
  }

  map<int, int> cc;
  for(int i=1; i<=n; i++) {
    int p = find(i);
    cc[p]++;
  }

  printf("%d\n", (int) cc.size());
  for(auto it : cc) printf("%d ", it.second);
  printf("\n");

	return 0;
}

