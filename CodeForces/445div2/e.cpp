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
const int N=1e6+5;
const ll MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll d[N], s[N], f[N], inv[N], finv[N];
ll n, k;

int main(){
  scanf("%lld %lld", &n, &k);

  ll p = MOD;
  f[0] = (ll)1; finv[0] = (ll)1;
  inv[1] = (ll)1; finv[1] = (ll)1; f[1] = (ll)1;
  for(ll i=2; i<=n; i++) {
    inv[i] = (p - ((((p/i)*inv[p%i])%p)%p));
    finv[i] = (finv[i-1] * inv[i]) % MOD;
    f[i] = (f[i-1]*i) % MOD;
  }

  for(ll i=1; i<=n; i++) {
    if(k >= i) d[i] = 0;
    else d[i] = (((i-k-1) * f[i-2]) % MOD + (f[i-2] * ((s[i-1] - s[i-k-1] + MOD) % MOD)) % MOD) % MOD;
    s[i] = (s[i-1] + (d[i] * finv[i-1]) % MOD) % MOD;
  }

  //for(int i=1; i<=n; i++) printf("%lld\n", s[i]);

  ll ans = (s[n] * f[n-1]) % MOD;
  printf("%lld\n", ans);

  return 0;
}


