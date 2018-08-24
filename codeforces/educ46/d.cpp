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

const int N = 1e3+5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

ll n, a[N], dp[N];
ll b[N][N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld", &n);
  for(int i=1; i<=n; i++) scanf("%lld", &a[i]);

  b[0][0] = 1;
  b[1][0] = b[1][1] = 1;
  for(int i=2; i<=n; i++) {
    b[i][0] = 1;
    for(int j=1; j<=i; j++) b[i][j] = (b[i-1][j-1] + b[i-1][j]) % MOD;
  }

  dp[0] = 1;

  for(int i=1; i<=n; i++) {
    dp[i] = dp[i-1];
    for(int j=i-1; j>0; j--) {
      if(a[j] > 0 and a[j] + j <= i) {
        ll comb = b[i-j-1][a[j]-1];
        dp[i] = (dp[i] + (comb * dp[j-1])) % MOD;
      }
    }
  }
  printf("%lld\n", dp[n]-1);

  return 0;
}

