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
const int N=5e3+5;
const ll MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll memo[N][N];
ll n, ok;

ll fexp(ll b, ll e) {
  ll ans = 1;

  while(e) {
    if(e&1) ans = (ans * b) % MOD;
    b = (b*b) % MOD;
    e /= 2;
  }

  return ans;
}

ll dp(ll k, ll i) {
  if(!k) return memo[k][i] = fexp(2, n-i);
  if(~memo[k][i]) return memo[k][i];

  ll term1 = (i * dp(k-1, i)) % MOD;
  ll term2 = ((n-i) * dp(k-1, i+1)) % MOD;

  return memo[k][i] = (term1 + term2) % MOD;
}

int main(){
  scanf("%lld %lld", &n, &ok);
  memset(memo, -1, sizeof memo);

  ll ans = (n * dp(ok-1, 1)) % MOD;
  printf("%lld\n", ans);

	return 0;
}

