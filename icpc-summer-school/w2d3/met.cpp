#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> tll;

const long double EPS = 1e-9;
const int N=3e5+20;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll bit[N], goal[N], ans[N];
tll query[N];

map<int, vector<int>> pos;
int n, m, k, p;

void add(int i, ll v) {
  for(int j=i; j<N; j+=j&-j) bit[j] += v;
}

ll qry(int i) {
  ll ans = 0;
  for(int j=i; j; j-=j&-j) ans += bit[j];
  return ans;
}

void apply(int i) {
  if(query[i].st.st <= query[i].st.nd) {
    add(query[i].st.st, query[i].nd);
    add(query[i].st.nd+1, -query[i].nd);
  }
  else {
    add(query[i].st.st, query[i].nd);
    add(1, query[i].nd);
    add(query[i].st.nd+1, -query[i].nd);
  }
}

void undo(int i) {
  if(query[i].st.st <= query[i].st.nd) {
    add(query[i].st.st, -query[i].nd);
    add(query[i].st.nd+1, query[i].nd);
  }
  else {
    add(query[i].st.st, -query[i].nd);
    add(1, -query[i].nd);
    add(query[i].st.nd+1, query[i].nd);
  }
}

void solve(int l, int r, vector<int>& v) {
  if(l == r or v.empty()) {
    for(int i : v) ans[i] = l;
    return;
  }

  vector<int> left, right;
  int mid = (l+r)/2;

  while(p > mid) { undo(p); p--; }
  while(p < mid) { p++; apply(p); }

  for(int i : v) {
    ll sum = 0;
    for(int j : pos[i]) {
      sum = min(sum + qry(j), goal[i]);
    }
    if(sum < goal[i]) right.pb(i);
    else left.pb(i);
  }

  solve(l, mid, left);
  solve(mid+1, r, right);
}

int main(){
  scanf("%d %d", &n, &m);

  vector<int> v;
  for(int i=1; i<=m; i++) {
    int u;
    scanf("%d", &u);
    pos[u].pb(i);
  }

  for(int i=1; i<=n; i++) scanf("%lld", &goal[i]), v.pb(i);

  scanf("%d", &k);
  for(int i=1; i<=k; i++) {
    ll u, v, w;
    scanf("%lld %lld %lld", &u, &v, &w);
    query[i] = mp(mp(u,v), w);
  }

  solve(1, k+1, v);
  for(int i : v) {
    if(ans[i] <= k) printf("%lld\n", ans[i]);
    else printf("NIE\n");
  }

  return 0;
}

