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

int n, m, k;
ll adj[N], val[N];

int main(){
  scanf("%d %d %d", &n, &m, &k);
  srand(time(0));

  for(int i=1; i<=n; i++) {
    ll a = rand();
    a <<= 32; a |= rand();
    val[i] = a;
  }

  for(int i=0; i<m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[v] ^= val[u], adj[u] ^= val[v];
  }

  for(int i=0; i<k; i++) {
    int t;
    scanf("%d", &t);

    ll accum = 0;
    vector<int> qry;
    for(int j=0; j<t; j++) {
      int u;
      scanf("%d", &u);
      qry.pb(u); accum ^= val[u];
    }

    for(auto i : qry) {
      adj[i] ^= (accum ^ val[i]);
    }
  }

  for(int i=1; i<=n; i++) {
    printf("%s\n", adj[i] ? "NIE" : "TAK");
  }

	return 0;
}

