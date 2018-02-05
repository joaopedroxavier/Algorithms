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
const int N=2e2+5;
const int K=2e4+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;
const ll LINF=0x3f3f3f3f3f3f3f3f;

ll n, b[N], c[N], k;
ll dp[N][K], amount[N][K], ans[N];

int main(){
  scanf("%lld", &n);
  for(int i=1; i<=n; i++) scanf("%lld", &b[i]);
  for(int i=1; i<=n; i++) scanf("%lld", &c[i]);
  scanf("%lld", &k);

  memset(dp, 63, sizeof dp);
  dp[0][0] = 0;
  for(int i=1; i<=n; i++) {
    for(int j=0; j<=k; j++) dp[i][j] = dp[i-1][j];

    ll p = 1;
    while(p <= c[i]) {
      ll bb = b[i] * p;
      for(int j=k; j>=0; j--) if(j >= bb) {
        if(dp[i][j] > dp[i][j-bb] + p) {
          dp[i][j] = dp[i][j-bb] + p;
          amount[i][j] = amount[i][j-bb] + p;
        }
      }
      c[i] -= p;
      p *= 2;
    }

    ll bb = b[i] * c[i];
    for(int j=k; j>=0; j--) if(j >= bb) {
        if(dp[i][j] > dp[i][j-bb] + c[i]) {
          dp[i][j] = dp[i][j-bb] + c[i];
          amount[i][j] = amount[i][j-bb] + c[i]; 
        }
    }
  }

  int sack = k, i = n;
  ll tot = 0;
  while(i) {
    ans[i] += amount[i][sack];
    tot += ans[i];
    sack -= amount[i][sack] * b[i];
    i--;
  }

  printf("%lld\n", tot);
  for(int i=1; i<=n; i++) printf("%lld%c", ans[i], i==n ? '\n' : ' ');


	return 0;
}
