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

ll shf[100], sz[100];
int n;

ll mulmod(ll a, ll b, ll m = MOD) {
  ll r = 0;
  for(a %= m; b; b >>=1, a=(a*2)%m) if(b&1) r=(r+a)%m;
  return r;
}

int getlevel(ll n) {
  int p=0;
  while((1ll<<p) <= n) {
    p++;
  }
  p--;
  return p;
}

void shift_val(ll n, ll x) {
  ll l = getlevel(n);
  x %= sz[l];
  shf[l] = (shf[l] + x + sz[l]) % sz[l];
}

void shift_node(ll n, ll x) {
  int l = getlevel(n);
  int s=0;
  for(int i=l; i<60; i++) {
    shf[i] = (shf[i] + mulmod(x, 1ll<<s, sz[i]) + sz[i]) % sz[i];
    s++;
  }
}

ll get_at_pos(int l, ll x) {
  ll ans = (1ll<<l) + ((x - shf[l] + sz[l]) % sz[l]);
  return ans;
}

ll get_pos_of(int l, ll x) {
  ll ans = (1ll<<l) + ((x + shf[l] + sz[l]) % sz[l]);
  //printf("%lld\n", ((x + shf[l] + sz[l]) % sz[l]));
  return ans;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  sz[0] = 1;
  for(int i=1; i<60; i++) sz[i] = sz[i-1] * 2;
  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    ll t, x, k;
    scanf("%lld", &t);

    if(t == 1) {
      scanf("%lld %lld", &x, &k);
      shift_val(x, k);
    } else if(t == 2) {
      scanf("%lld %lld", &x, &k);
      shift_node(x, k);
    } else {
      scanf("%lld", &x);
      int l = getlevel(x);
      x = get_pos_of(l, x);
      while(l >= 0) {
        printf("%lld ", get_at_pos(l, x));
        l--;
        x >>= 1;
      }
      printf("\n");
    }
  }

  return 0;
}

