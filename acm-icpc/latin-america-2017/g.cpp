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

ll memo[N][2][2];
int n, l[N], r[N], f[N];

ll dp(int i, int out, int sup) {
  if(~memo[i][out][sup]) return memo[i][out][sup];

  if(!i) return out == sup;

  memo[i][0][0] = ((dp(l[i], 1, 1) * dp(r[i], 1, 1))) % MOD;

  memo[i][0][1] = ((dp(l[i], 1, 0) * dp(r[i], 1, 0)) % MOD +
                   (dp(l[i], 1, 0) * dp(r[i], 1, 1)) % MOD +
                   (dp(l[i], 1, 1) * dp(r[i], 1, 0)) % MOD) % MOD;

  memo[i][1][0] = ((dp(l[i], 0, 1) * dp(r[i], 1, 1)) % MOD +
                   (dp(l[i], 0, 1) * dp(r[i], 0, 1)) % MOD +
                   (dp(l[i], 1, 1) * dp(r[i], 0, 1)) % MOD) % MOD;

  memo[i][1][1] = ((dp(l[i], 0, 0) * dp(r[i], 0, 0)) % MOD +
                   (dp(l[i], 0, 0) * dp(r[i], 0, 1)) % MOD +
                   (dp(l[i], 0, 0) * dp(r[i], 1, 0)) % MOD +
                   (dp(l[i], 0, 0) * dp(r[i], 1, 1)) % MOD +
                   (dp(l[i], 0, 1) * dp(r[i], 0, 0)) % MOD +
                   (dp(l[i], 0, 1) * dp(r[i], 1, 0)) % MOD +
                   (dp(l[i], 1, 0) * dp(r[i], 0, 0)) % MOD +
                   (dp(l[i], 1, 0) * dp(r[i], 0, 1)) % MOD +
                   (dp(l[i], 1, 1) * dp(r[i], 0, 0)) % MOD) % MOD;

  if(f[i] == 1) {
    ll t11 = memo[i][1][1], t10 = memo[i][1][0], t00 = memo[i][0][0], t01 = memo[i][0][1];
    memo[i][1][1] = t11 + t01;
    memo[i][1][0] = t10 + t00;
    memo[i][0][1] = memo[i][0][0] = 0;
  }

  if(f[i] == 0) {
    ll t11 = memo[i][1][1], t10 = memo[i][1][0], t00 = memo[i][0][0], t01 = memo[i][0][1];
    memo[i][0][1] = t01 + t11;
    memo[i][0][0] = t00 + t10;
    memo[i][1][1] = memo[i][1][0] = 0;
  }

  return memo[i][out][sup];
}

int main(){

  while(scanf("%d", &n) != EOF) {
    memset(memo, -1, sizeof memo);

    for(int i=1; i<=n; i++) {
      scanf("%d %d %d", &l[i], &r[i], &f[i]);
    }
    printf("%lld\n", (dp(1, 0, 1) + dp(1, 1, 0)) % MOD);
  }

	return 0;
}

