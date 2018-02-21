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
const ll LINF=0x3f3f3f3f3f3f3f3f;

int n, m;
ll dist[N], sh, x;
map<ii, ll> wt;
vector<int> adj[N];

ll sh_path(int m) {
  for(int i=1; i<=n; i++) dist[i] = 1e15;

  priority_queue<pair<ll, int>> pq;
  pq.push(mp(0, 1));
  dist[1] = 0;

  while(!pq.empty()) {
    int u = pq.top().second;
    ll cost = -pq.top().first;

    pq.pop();

    for(int v : adj[u]) if(wt[mp(u,v)] <= m) {
      if(dist[v] > cost + wt[mp(u,v)]) {
        dist[v] = cost + wt[mp(u,v)];
        pq.push(mp(-dist[v], v));
      }
    }
  }

  return dist[n];
}

bool check(int m) { return sh_path(m) * (ll)100 <= (ll)(100 + x) * sh; }

int main(){
  scanf("%d %d %lld", &n, &m, &x);

  for(int i=0; i<m; i++) {
    int u, v; ll w;
    scanf("%d %d %lld", &u, &v, &w);

    adj[u].pb(v); adj[v].pb(u);
    wt[mp(u,v)] = wt[mp(v,u)] = w;
  }

  sh = sh_path(INF);

  int l=1, r=INF;
  while(l < r) {
    int m = (l+r)/2;
    if(check(m)) r = m;
    else l = m+1;
  }

  printf("%d\n", l);

	return 0;
}

