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

const int N = 2e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

vector<int> st[4*N];
int v[N];

void build(int p, int l, int r) {
  if(l == r) { st[p].pb(v[l]); return; }

  int m = (l+r)/2;
  build(2*p, l, m);
  build(2*p+1, m+1, r);

  st[p].resize(r-l+1);
  merge(st[2*p].begin(), st[2*p].end(), st[2*p+1].begin(), st[2*p+1].end(), st[p].begin());
}

int query(int p, int l, int r, int i, int j, int x) {
  if(j < l or i > r) return 0;
  if(i <= l and r <= j) {
    return st[p].end() - lower_bound(st[p].begin(), st[p].end(), x);
  }

  int m = (l+r)/2;
  return query(2*p, l, m, i, j, x) + query(2*p+1, m+1, r, i, j, x);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  int n;
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    scanf("%d", &v[i]);
  }

  build(1, 1, n);
  ll ans = 0;
  for(int i=1; i<=n; i++) {
    ans += query(1, 1, n, 1, min(n, v[i]), i) - (v[i] >= i);
  }

  printf("%lld\n", ans/2);

	return 0;
}

