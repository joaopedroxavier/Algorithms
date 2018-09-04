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

const int N = 5e4+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int t, n;
int a, b, m, p[N], dp[N], ps[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &t);
  while(t--) {
    memset(p, 0, sizeof p);
    memset(ps, 0, sizeof ps);
    memset(dp, 63, sizeof dp);

    scanf("%d %d", &n, &m);
    scanf("%d %d", &a, &b);

    for(int i=1; i<=n; i++) scanf("%d", &p[i]);

    dp[0] = 0;
    for(int i=1; i<=n; i++) {
      int sum = 0;
      ps[i] = p[i] + ps[i-1];

      for(int j=i; j>0; j--) {
        sum += p[j];
        if(sum >= m) {
          int tot = (sum - m) * a;
          dp[i] = min(dp[i], tot + dp[j-1]);
          if(sum > m) break;
        }
        else {
          int tot = (m - sum) * b;
          dp[i] = min(dp[i], tot + dp[j-1]);
        }
      }

      if(ps[i] >= m) dp[i] = min(dp[i], (ps[i] - m) * a);
    }

    printf("%d\n", dp[n]);
  }
	return 0;
}

