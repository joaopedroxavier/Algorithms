//
// 내가 나인 게 싫은 날
// 영영 사라지고 싶은 날
// 문을 하나 만들자 너의 맘 속에다
// 그 문을 열고 들어가면
// 이 곳이 기다릴 거야
// 믿어도 괜찮아 널 위로해줄 magic shop
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

const int N = 2e4+5;
const int M = 1e3+5;
const int MAXP = 1e6+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

ll addmod(ll a, ll b) { return a + b >= MOD ? a + b - MOD : a + b; }

map<ll, ll> pf;

bool sieve[MAXP];
vector<ll> primes;
ll b, n;
ll a[N], dp[N][M];
vector<pair<ll, ll>> prime;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld", &b, &n);

  for(ll i=2; i<MAXP; i++) if(!sieve[i]) {
    primes.push_back(i);
    for(ll j=2*i; j<MAXP; j+=i) sieve[j] = 1;
  }

  for(int i=0; i<n; i++) {
    scanf("%lld", &a[i]);
    for(ll p : primes) while(a[i] % p == 0) {
      a[i] /= p;
      pf[p]++;
    }
    if(a[i] > 1) pf[a[i]]++;
  }

  printf("%d\n", (int) primes.size());

  if(b <= 1) return printf("%lld\n", b), 0;

  for(auto p : pf) prime.push_back({p.st, p.nd});

  //for(auto p : prime) printf("%lld: %lld\n", p.st, p.nd);

  int t = prime.size();
  for(int i=0; i<t; i++) {
    for(int j=2; j<=min(b, prime[i].nd+1); j++) dp[i][j] = 1;
  }

  for(int i=1; i < (int) prime.size(); i++) {
    ll p = prime[i].nd;

    for(int j=2; j<=b; j++) dp[i][j] = addmod(dp[i][j], dp[i-1][j]);

    for(int j=1; j<=min(b, p); j++) {
      for(int k = 2*(j+1), l = 2; k <= b; k += (j+1), l++) {
        //printf("%d %d %d\n", i, j+1, k);
        dp[i][k] = addmod(dp[i][k], dp[i-1][l]);
      }
    }
  }

  /*
  for(int i=0; i<t; i++) {
    for(int j=0; j<=b; j++) printf("%lld ", dp[i][j]);
    printf("\n");
  }
  */

  printf("%lld\n", dp[t-1][b]);

  return 0;
}

