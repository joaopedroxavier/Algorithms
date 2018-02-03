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
const int N=1e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m, know[N][N];
vi adj[N], cpy[N], ord;
vi ans; int mn;

void check() {
  memset(know, 0, sizeof know);
  for(int i=1; i<=n; i++) cpy[i] = adj[i];

  int ed = (n*(n-1))/2 - m;
  for(int i=1; i<=n; i++) {
    know[i][i] = 1;
    for(int v : adj[i]) know[i][v] = know[v][i] = 1;
  }

  vi tmp;
  for(int i=0; i<n; i++) {
    int u = ord[i], c = ed;
    for(int v : cpy[u]) {
      for(int w : cpy[u]) if(!know[v][w]) {
        know[v][w] = know[w][v] = 1;
        cpy[v].pb(w); cpy[w].pb(v);
        ed--;
      }
    }
    if(c > ed) {
      tmp.pb(u);
    }
  }

  if(tmp.size() < ans.size()) ans = tmp;
}

int main(){
  srand(time(0));
  scanf("%d %d", &n, &m);

  for(int i=0; i<m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[v].pb(u); adj[u].pb(v);
  }

  for(int i=1; i<=n; i++) ord.pb(i);
  ans = ord;

  for(int t=1; t<=10000; t++) {
    random_shuffle(ord.begin(), ord.end());
    check();
  }

  printf("%d\n", (int) ans.size());
  for(int v : ans) printf("%d ", v);
  printf("\n");

  return 0;
}

