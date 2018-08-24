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

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

ll n, m, a[N], pse[N], pso[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld", &n, &m);
  for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
  a[n+1] = m; n++;

  pso[1] = a[1] - a[0];
  for(int i=3; i<=n; i++) {
    if(i & 1) pso[i] = pso[i-2] + (a[i] - a[i-1]);
  }
  pse[2] = a[2] - a[1];
  for(int i=4; i<=n; i++) {
    if(!(i & 1)) pse[i] = pse[i-2] + (a[i] - a[i-1]);
  }

  ll ans = n & 1 ? pso[n] : pso[n-1];

  /*
  for(int i=0; i<=n; i++) printf("%lld ", pso[i]);
  printf("\n");
  for(int i=0; i<=n; i++) printf("%lld ", pse[i]);
  printf("\n");
  */

  for(int i=0; i<n; i++) if(a[i+1] - a[i] > 1) {
    if(i & 1) {
      ll tot = n & 1 ? pse[n-1] : pse[n];
      ll pos = a[i] + 1;
      ll term = pso[i] + max(0ll, tot - pse[i+1]) + (a[i+1] - pos);
      ans = max(ans, term);
    }
    else {
      ll tot = n & 1 ? pse[n] : pse[n-1];
      ll term = pso[i+1] - 1 + max(0ll, tot - pse[i]);
      ans = max(ans, term);
    }
  }
  printf("%lld\n", ans);

	return 0;
}

