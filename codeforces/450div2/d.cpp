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

map<int, int> pf;
vector<int> f, primes;
ll x, y;
int sieve[N];

void factorize(ll n) {
  for(ll p : primes) {
    while(n % p == 0){ pf[p]++; n /= p; }
    if(pf[p]) f.pb(p);
  }
  if(n>1) pf[n]++, f.pb(n);
}

ll fexp(ll b, ll e) {
  ll ans = 1;
  while(e) {
    if(e&1) ans = (ans * b) % MOD;
    b = (b * b) % MOD;
    e /= 2;
  }
  return ans;
}

int main(){
  scanf("%lld %lld", &x, &y);

  if(y % x != 0) return printf("0\n"), 0;
  y /= x;

  for(ll i=2; i<N; i++) if(!sieve[i]) {
    primes.pb(i);
    for(ll j=2*i; j<N; j+=i) sieve[j] = 1;
  }

  factorize(y);

  ll d = f.size(), ans = 0;
  for(int i=0; i < (1<<d); i++) {
    int cnt = 0, prod = 1;
    for(int j=0; j<d; j++) if(i & (1<<j)) {
      cnt++;
      prod = (prod * f[j]) % MOD;
    }
    ans = ans + ( cnt & 1 ? -1 : 1 ) * fexp(2, y/prod - 1);
    if(ans > MOD) ans -= MOD;
    if(ans < 0) ans += MOD;
  }
  
  printf("%lld\n", ans);

	return 0;
}

