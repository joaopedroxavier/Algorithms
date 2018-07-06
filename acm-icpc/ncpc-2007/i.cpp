//
// Elohim Essaim, Elohim Essaim, I implore you...
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

const int N = 1e3+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ld dp[N][N], sum[N][N], v[N];
int n, c, t;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &t);
  while(t--) {
    memset(dp, 0, sizeof dp);
    memset(sum, 0, sizeof sum);
    memset(v, 0, sizeof v);

    scanf("%d %d", &n, &c);
    for(int i=1; i<=n; i++) scanf("%Lf", &v[i]);

    for(int i=1; i<=n; i++) {
      for(int j=i+1; j<=n; j++) {
        for(int k=i+1; k<j; k++) {
          ld term = k-i;
          term /= ((ld) j-i);
          term *= ((ld) v[j] - v[i]);
          term += v[i];

          sum[i][j] = sum[i][j] + abs(term - v[k]);
        }
      }
    }

    for(int i=2; i<=n; i++) dp[2][i] = sum[1][i];
    for(int i=3; i<=n; i++) {
      for(int j=2; j<=n; j++) {
        dp[i][j] = LINF;
        for(int k=j-1; k>0; k--) {
          dp[i][j] = min(dp[i][j], dp[i-1][k] + sum[k][j]);
        }
      }
    }
    printf("%.4Lf\n", dp[c][n] / ((ld) n));
  }
	return 0;
}

