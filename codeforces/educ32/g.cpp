#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

const long double EPS = 1e-9;
const ll N=2e6+5;
const ll MOD=1e9+7;
const ll INF=0x3f3f3f3f;

ll a[N], total_weight;

ll trie[N][2], triesz[N], trien = 1;
ll n;

ll walk(ll u, ll i) {
  if(!trie[u][i]) trie[u][i] = ++trien;
  return trie[u][i];
}

ll par[N], sz[N]; 
set<ll> cc;
map<ll, ll> idx;

ll find(ll a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite(ll u, ll v) {
  if((u = find(u)) == (v = find(v))) return;
  if(sz[u] < sz[v]) swap(u, v);
  par[v] = u; sz[u] += sz[v];
}

void add(ll u) {
  ll t = 1; triesz[t]++;
  for(int j=30; j>=0; j--) {
    ll d = (u & (1<<j)) ? 1 : 0;
    t = walk(t, d), triesz[t]++;
  }
}

void rmv(ll u) {
  ll t = 1; triesz[t]--;
  for(int j=30; j>=0; j--) {
    ll d = (u & (1<<j)) ? 1 : 0;
    t = walk(t, d), triesz[t]--;
  }
}

ii connect(vector<ll> p) {
  for(ll u : p) rmv(a[u]);

  ll best = INF, res, nsrc = 0;
  for(ll u : p) {
    ll t = 1;
    ll m = 0;
    for(int j=30; j>=0; j--) {
      ll d = (a[u] & (1<<j)) ? 1 : 0;
      ll nt = walk(t, d);
      t = triesz[nt] ? nt : walk(t, d^=1);
      m += (1<<j) * d;
    }
    //prllf("%d %d %d\n", a[u], m, a[u] ^ m);
    if((m ^ a[u]) < best) nsrc = u, res = m; best = (m ^ a[u]);
  }

  for(ll u : p) add(a[u]);

  return mp(nsrc, idx[res]);
}



int main(){
  scanf("%lld", &n);

  for(int i=1; i<=n; i++) {
    cc.insert(i);
    scanf("%lld", &a[i]);
    idx[a[i]] = i; add(a[i]);
  }

  for(int i=1; i<=n; i++) par[i] = i;

  while(cc.size() > 1) {

    vector<ll> v(n+1);
    for(int i=1; i<=n; i++) v[i] = i;
    sort(v.begin()+1, v.end(), [](ll a, ll b){ return find(a) < find(b); });

    vector<ll> p;
    p.pb(v[1]);
    vector<ii> to_unite;

    for(int i=2; i<=n; i++) {
      if(find(v[i]) != find(v[i-1])) {
        to_unite.pb(connect(p));
        p.clear();
      }
      p.pb(v[i]);
    }

    to_unite.pb(connect(p));

    for(ii pp : to_unite) if(find(pp.first) != find(pp.second)) {
      total_weight += (a[pp.first] ^ a[pp.second]);
      //printf("connecting %d and %d with weight %d\n", pp.first, pp.second, a[pp.first] ^ a[pp.second]);
      unite(pp.first, pp.second);
    }
    
    cc.clear();
    for(int i=1; i<=n; i++) cc.insert(find(i));
  }

  printf("%lld\n", total_weight);


  return 0;
}

