//
// Elohim Essaim, Elohim Essaim, I implore you...
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

const int N = 1e6+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

ll c[N], bit[N];

void update(ll x, ll p) {
  ll add = x - c[p];
  c[p] = x;
  for(p += 2; p < N; p += p&-p) bit[p] += add;
}

ll qry(ll p) {
  ll ans = 0;
  for(p += 2; p; p -= p&-p) ans += bit[p];
  return ans;
}

int n, r;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  
  scanf("%d %d", &n, &r);
  for(int i=0; i<(1<<n); i++) {
    ll u; scanf("%lld", &u);
    update(u, i);
  }

  ld sum = qry((1<<n)-1), amt = (1<<n);
  printf("%.12Lf\n", sum / amt);
  for(int i=0; i<r; i++) {
    ll z, g; scanf("%lld %lld", &z, &g);
    update(g, z);
    sum = qry((1<<n)-1);

    printf("%.12Lf\n", sum / amt);
  }

  return 0;
}

