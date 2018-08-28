//
// 내가 나인 게 싫은 날
// 영영 사라지고 싶은 날
// 문을 하나 만들자 너의 맘 속에다
// 그 문을 열고 들어가면
// 이 곳이 기다릴 거야
// 믿어도 괜찮아 널 위로해줄 magic shop
//
#include <bits/stdc++.h>

using namespace std;

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
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

struct edge {
  int u, v;
  ll wt;
  bool operator<(edge e) const { return u == e.u ? v < e.v : u < e.u; }
};

int n, m;
int vis[N];
ll x[N];

vector<edge> adj[N];
vector<edge> ed;
set<edge> used, notused;

void dfs(int u, ll p) {
  vis[u] = 1; x[u] = p;

  for(auto e : adj[u]) {
    ed.push_back(e);
    if(!vis[e.v]) {
      dfs(e.v, p ^ e.wt);
      used.insert(e);
    }
  }
}

vector<bitset<62>> num, base;

int gauss() {
  int sz = (int) num.size();

  int bs = 0;
  for(int i=0; i<62; i++) {
    bool found = false;
    for(int j=bs; j<sz; j++) if(num[j][i]) {
      found = true;
      swap(num[j], num[bs]);
    }
    for(int j=bs+1; j<sz; j++) if(num[j][i]) {
      num[j] ^= num[bs];
    }
    if(found) base.push_back(num[bs]), bs++;
  }
  return base.size();
}

bool has[N];

bool contains(set<edge> &s, edge e) {
  edge rev = {e.v, e.u, e.wt};
  return s.count(rev) or s.count(e);
}

ll solve(vector<edge> &ed) {
  memset(has, 0, sizeof has);
  vector<int> vtx;

  for(auto e : ed) {
    vtx.push_back(e.u);
    vtx.push_back(e.v);
  }

  sort(vtx.begin(), vtx.end());
  ll n = unique(vtx.begin(), vtx.end()) - vtx.begin();
  vtx.resize(n);

  for(auto e : ed) if(!contains(used, e)) {
    ll wt = x[e.u] ^ x[e.v] ^ e.wt;
    if(!contains(notused, e)) {
      num.push_back(wt);
      notused.insert(e);
    }
  }

  int b = gauss();

  for(int i=0; i<62; i++) for(auto j : base) if(j[i]) has[i] = true;

  ll sum = 0;
  for(int i=0; i<62; i++) {
    ll one = 0, zero = 0;
    for(int j : vtx) {
      if(x[j] & (1ll << i)) one++;
      else zero++;
    }

    if(has[i] and b != 0) {
      ll term1 = (1ll << i) % MOD;
      ll term2 = (1ll << (b-1)) % MOD;
      ll term3 = ((n * (n-1))/2) % MOD;
      term1 = (term1 * term2) % MOD;
      term1 = (term1 * term3) % MOD;
      sum = (sum + term1) % MOD;
    }
    else {
      ll term1 = (1ll << i) % MOD;
      ll term2 = (1ll << b) % MOD;
      term1 = (term1 * term2) % MOD;
      term1 = (term1 * one) % MOD;
      term1 = (term1 * zero) % MOD;
      sum = (sum + term1) % MOD;
    }
  }

  return sum;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);

  for(int i=0; i<m; i++) {
    int u, v; ll t; scanf("%d %d %lld", &u, &v, &t);
    edge eu = {u,v,t};
    edge ev = {v,u,t};
    adj[u].push_back(eu);
    adj[v].push_back(ev);
  }

  ll ans = 0;

  for(int i=1; i<=n; i++) if(!vis[i]) {
    ed.clear(); num.clear(); base.clear();
    used.clear();

    dfs(i, 0);
    ans = (ans + solve(ed)) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}

