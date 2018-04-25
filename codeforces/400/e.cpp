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

map<ll, int> factorize(ll n) {
  map<ll, int> fact;
  for(ll i=2; i*i<=n; i++) {
    while(n % i == 0) fact[i]++, n /= i;
  }
  if(n > 1) fact[n]++;
  return fact;
}

ll phi(ll n) {
  if(n == 1) return 1;
  map<ll, int> fact = factorize(n);
  for(auto p : fact) n -= n / p.first;
  return n;
}

ll n, k;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld", &n, &k);

  k = (k+1)/2;
  while(k > 0 and n > 1) {
    k--;
    n = phi(n);
  }

  printf("%lld\n", n % MOD);

	return 0;
}

