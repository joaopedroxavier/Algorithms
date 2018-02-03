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
const int N=4e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

map<ll, ll> fact;
vector<ll> primes;
ll x, y, q;
ll sieve[N];
ll f[N], inv[N], finv[N], e[N];

void factorize(ll x) {
  for(ll p : primes) {
    while(x % p == 0) { x/=p; fact[p]++; }
  }
  if(x>1) fact[x]++;
}

int main(){
  scanf("%lld", &q);

  sieve[0] = sieve[1] = 1;
  for(ll i=2; i*i < N; i++) if(!sieve[i]) {
    primes.pb(i);
    for(ll j=2*i; j < N; j+=i) sieve[j] = 1;
  }

  f[0] = 1; finv[0] = 1, e[0] = 1;
  f[1] = 1; finv[1] = 1, inv[1] = 1; e[1] = 2;
  for(ll i=2; i<N; i++) {
    f[i] = (f[i-1] * i) % MOD;
    inv[i] = (MOD - ((MOD/i)*inv[MOD%i])%MOD)%MOD;
    finv[i] = (finv[i-1] * inv[i]) % MOD;
    e[i] = (e[i-1] * 2) % MOD;
  }

  while(q--){
    fact.clear();
    scanf("%lld %lld", &x, &y);
    factorize(x);

    ll ans = 1;
    for(auto p : fact) {
      ll prod = (((f[p.second + y - 1] * finv[p.second]) % MOD) * finv[y-1]) % MOD;
      ans = (ans * prod) % MOD;
    }

    ans = (ans * e[y-1]) % MOD;
    printf("%lld\n", ans);
  }

	return 0;
}

