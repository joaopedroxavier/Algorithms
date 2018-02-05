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

ll solve(ll a, ll m, ll p) {
  map<ll, ll> babystep;

  ll b = 1, an = a;
  while(b*b < p) b++, an = (an * a) % p;

  ll bs = m;
  for(ll i=0; i<=b; i++) {
    babystep[bs] = i;
    bs = (bs * a) % p;
  }

  ll gs = an;
  for(ll i=1; i<=b; i++) {
    if(babystep.count(gs)) {
      return (b * i - babystep[gs]);
    }
    gs = (gs * an) % p;
  }

  return -1;
}

ll fexp(ll b, ll e, ll p) {
  ll ans = 1;
  while(e) {
    if(e&1) ans = (ans * b) % p;
    b = (b * b) % p;
    e = e/2;
  }
  return ans;
}

int main(){
  ll p, a, x0, b, x;
  scanf("%lld %lld %lld %lld %lld", &p, &x0, &a, &b, &x);
  x0 %= p, a %= p, b %= p, x %=p;

  if(x0 == x) return printf("0\n"), 0;

  if(a == 0) {
    if(b == x) return printf("1\n"), 0;
    else return printf("NIE\n"), 0;
  }

  if(a == 1) {
    if(b == 0 and x0 == x) return printf("0\n"), 0;
    else if(b == 0) return printf("NIE\n"), 0;
    else {
      ll ans = (((x-x0+p)%p) * fexp(b, p-2, p)) % p;
      return printf("%lld\n", ans), 0;
    }
  }

  ll m  = (a*x0 - x0 + b) % p;
  ll m1 = (a*x - x + b) % p;

  m = fexp(m, p-2, p);
  ll k = solve(a, (m * m1) % p, p);

  if(~k) printf("%lld\n", k);
  else printf("NIE\n");

	return 0;
}

