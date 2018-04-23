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
const ll MOD = 1e9+9;
const int INF = 0x3f3f3f3f;

ll fexp(ll b, ll e) {
  ll ans = 1;
  while(e) {
    if(e&1) ans = (ans * b) % MOD;
    b = (b * b) % MOD;
    e >>= 1;
  }
  return ans;
}

vector<ll> divisors(ll n) {
  vector<ll> ans;
  for(ll i=1; i*i <= n; i++) if(n % i == 0){
    ans.push_back(i);
  }
  return ans;
}

string sgn;
ll n, a, b, k;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> a >> b >> k;
  cin >> sgn;

  ll p1 = fexp(a, n);
  ll i1 = fexp(a, MOD-2);

  ll p2 = 1;

  ll ans = 0;
  ll kk = k;
  while(kk * kk < n) {
    kk += k;
  }
  
  for(int i=0; i<kk; i++) {
    if(sgn[i%k] == '+') {
      ll term = (p1 * p2) % MOD;
      ans = (ans + term) % MOD;
    } else {
      ll term = (p1 * p2) % MOD;
      ans = (ans + MOD - term) % MOD;
    }
    p1 = (p1 * i1) % MOD;
    p2 = (p2 * b) % MOD;
  }

  ll sum = ans;
  for(int i=1; i<(n+1)/kk; i++) {
    sum = (sum * fexp(i1, kk)) % MOD;
    sum = (sum * fexp(b, kk)) % MOD;
    p1 = (p1 * fexp(i1, kk)) % MOD;
    p2 = (p2 * fexp(b, kk)) % MOD;
    ans = (ans + sum) % MOD;
  }

  for(ll i=((n+1)/kk)*kk; i<=n; i++) {
    if(sgn[i%k] == '+') {
      ll term = (p1 * p2) % MOD;
      ans = (ans + term) % MOD;
    } else {
      ll term = (p1 * p2) % MOD;
      ans = (ans + MOD - term) % MOD;
    }
    p1 = (p1 * i1) % MOD;
    p2 = (p2 * b) % MOD;
  }

  cout << ans << endl;

  return 0;
}

