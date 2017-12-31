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
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll dp[N][N];
ll k, pa, pb, s, painv, pbinv;

ll e(ll na, ll nab) {
  if(dp[na][nab] != -1) return dp[na][nab];

  if(nab >= k) return dp[na][nab] = nab;
  if(na + nab >= k) {
    ll term = (pa * pbinv) % MOD;
    term = (term + na + nab) % MOD;
    return dp[na][nab] = (term) % MOD;
  }

  dp[na][nab] = ( (pa*e(na+1, nab))%MOD + (pb*e(na, nab+na))%MOD ) % MOD;

  return dp[na][nab];
}

ll fexp(ll b, ll e) {
  ll ans = 1;
  while(e) {
    if(e&1) ans = (ans * b) % MOD;
    b = (b * b) % MOD; e /= 2;
  }
  return ans;
}

int main(){
  memset(dp, -1, sizeof dp);

  scanf("%lld %lld %lld", &k, &pa, &pb);
  s = pa + pb;

  ll sinv = fexp(s, MOD-2);
  pa = (pa * sinv) % MOD;
  pb = (pb * sinv) % MOD;

  painv = fexp(pa, MOD-2);
  pbinv = fexp(pb, MOD-2);

  printf("%lld\n", e(1, 0));

	return 0;
}

