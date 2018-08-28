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

const int N = 1e4+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll dp[N], cpy[N];
ll n, c, s[N], p[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld", &n, &c);

  memset(dp, 63, sizeof dp);

  for(int i=1; i<=n; i++) scanf("%lld", &p[i]);
  for(int i=1; i<=n; i++) scanf("%lld", &s[i]);

  dp[0] = 0;
  for(int i=0; i<=n; i++) {
    for(ll j=i; j>0; j--) {
      dp[j] = min(dp[j-1] + s[i], dp[j] + p[i] + j * c);
    }
    dp[0] = dp[0] + p[i];
  }

  ll ans = LINF;
  for(int i=0; i<=n; i++) ans = min(ans, dp[i]);
  printf("%lld\n", ans);

	return 0;
}

