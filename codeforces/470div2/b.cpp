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

const int N = 1e6+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

ll n;
int sieve[N];
int least[N];
int dp[N];

ll resp(ll j) {
  if(!sieve[j]) return INF;
  return j - dp[j] + 1;
}

ll solve(ll i) {
  ll ans = INF;
  for(ll j=i; j>=i-dp[i]+1; j--) {
    ans = min(ans, resp(j));
  }
  return ans;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  for(ll i=2; i<N; i++) if(!sieve[i]) {
    for(ll j=2*i; j<N; j+=i) sieve[j] = 1, dp[j] = i;
  }

  scanf("%lld", &n);
  printf("%lld\n", solve(n));

	return 0;
}

