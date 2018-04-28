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

ll n, k, ma, d;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

bool bigg(ll x) {
  return x > n/k;
}

bool big(ll x, ll q) {
  if(bigg(x)) return true;
  x *= k;
  return x > n/q;
}

ll f(ll x) {
  if(bigg(x)) return -INF;
  ll l=1, r=ma;
  while(l < r) {
    ll m = (l+r+1)/2;
    if(big(m, x-1)) r=m-1;
    else {
      ll amount = (x-1)*m*k;
      if(n >= amount + m) l = m;
      else r = m-1;
    }
  }
  return l*x;
}


int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld %lld %lld", &n, &k, &ma, &d);

  ll ans = ma;
  for(ll i=2; i<=d; i++) ans = max(ans, f(i));
  printf("%lld\n", ans);
	return 0;
}

