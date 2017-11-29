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
typedef pair<ll, ll> pll;

const long double EPS = 1e-9;
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll f[N], finv[N], pot[N];
ll inv[N];
ll n;

map<ll, vector<ll>> r, c;
set<ll> curr, curc;

ll x[N], y[N], vis[N];
ll rt[N], lf[N], up[N], dw[N];
bool cycle;

void dfs(int u, int par) {
  vis[u] = 1;
  curr.insert(x[u]);
  curc.insert(y[u]);

  if(vis[up[u]] and up[u] != par) cycle = true;
  if(vis[dw[u]] and dw[u] != par) cycle = true;
  if(vis[lf[u]] and lf[u] != par) cycle = true;
  if(vis[rt[u]] and rt[u] != par) cycle = true;

  if(!vis[up[u]] and up[u]) dfs(up[u], u);
  if(!vis[dw[u]] and dw[u]) dfs(dw[u], u);
  if(!vis[lf[u]] and lf[u]) dfs(lf[u], u);
  if(!vis[rt[u]] and rt[u]) dfs(rt[u], u);
}

int main(){
  scanf("%lld", &n);

  for(int i=1; i<=n; i++) {
    scanf("%lld %lld", &x[i], &y[i]);
    r[x[i]].pb(i); c[y[i]].pb(i);
  }

  for(auto m : r) {
    sort(m.second.begin(), m.second.end());
    int t = m.second.size();
    for(int i=0; i<t-1; i++) rt[m.second[i]] = m.second[i+1];
    for(int i=t-1; i>0; i--) lf[m.second[i]] = m.second[i-1];
  }

  for(auto m : c) {
    sort(m.second.begin(), m.second.end());
    int t = m.second.size();
    for(int i=0; i<t-1; i++) up[m.second[i]] = m.second[i+1];
    for(int i=t-1; i>0; i--) dw[m.second[i]] = m.second[i-1];
  }

  f[0] = 1; finv[0] = 1; pot[0] = 1;
  inv[1] = 1;

  ll p = MOD;
  for(ll i=2; i<N; i++) {
    inv[i] = (p - (p/i)*inv[p%i]%p)%p;
  }

  for(ll i=1; i<N; i++) {
    f[i] = (f[i-1] * i) % p;
    finv[i] = (finv[i-1] * inv[i]) % p;
    pot[i] = (pot[i-1] * 2) % p;
  }

  ll ans = 1;
  for(int i=1; i<=n; i++) if(!vis[i]) {
    curr.clear(); curc.clear(); cycle = false;
    dfs(i, i);
    ll t = (curr.size() + curc.size());
    ans = (ans * (cycle ? pot[t] : pot[t]-1)) % p;
  }

  printf("%lld\n", ans);

  return 0;
}

