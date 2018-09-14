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

const int N = 3e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

ll n, a[N], b[N];
ll dp[N];
ll beg[N], psa[N], psb[N], sta[N], stb[N];
ll bkwa[N], bkwb[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld", &n);
  for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
  for(int i=1; i<=n; i++) scanf("%lld", &b[i]);

  beg[1] = b[1];
  for(ll i=2; i<=n; i++) {
    beg[i] = beg[i-1];
    ll t = 2*(i-1);
    if(i & 1) {
      beg[i] += a[i]*t + b[i]*(t+1);
    }
    else {
      beg[i] += b[i]*t + a[i]*(t+1);
    }
  }

  for(int i=1; i<=n; i++) psa[i] = psa[i-1] + a[i];
  for(int i=1; i<=n; i++) psb[i] = psb[i-1] + b[i];

  for(ll i=1; i<=n; i++) sta[i] = sta[i-1] + (i) * a[i];
  for(ll i=1; i<=n; i++) stb[i] = stb[i-1] + (i) * b[i];

  for(ll i=n; i>0; i--) bkwa[i] = bkwa[i+1] + (n-i+1) * a[i];
  for(ll i=n; i>0; i--) bkwb[i] = bkwb[i+1] + (n-i+1) * b[i];

  /*
  printf("ps:\n");
  for(int i=1; i<=n; i++) printf("%lld ", psa[i]);
  printf("\n");

  for(int i=1; i<=n; i++) printf("%lld ", psb[i]);
  printf("\n");

  printf("st:\n");
  for(int i=1; i<=n; i++) printf("%lld ", sta[i]);
  printf("\n");

  for(int i=1; i<=n; i++) printf("%lld ", stb[i]);
  printf("\n");

  printf("bkw:\n");
  for(int i=1; i<=n; i++) printf("%lld ", bkwa[i]);
  printf("\n");

  for(int i=1; i<=n; i++) printf("%lld ", bkwb[i]);
  printf("\n");

  printf("beg:\n");
  for(int i=1; i<=n; i++) printf("%lld ", beg[i]);
  printf("\n");
  */

  ll ans = 0;
  for(ll i=1; i<=n; i++) {
    //printf("%lld: ", i);
    ll bef = beg[i];
    ll t = 2*i;
    if(i & 1) {
      ll bend = (t-i-1) * (psb[n] - psb[i]) + stb[n] - stb[i];
      t += (n-i);
      ll aend = bkwa[i+1] + (t-1) * (psa[n] - psa[i]);

      /*
      printf("going: %lld\n", bend);
      printf("back: %lld\n", aend);
      */

      bef += bend;
      bef += aend;
    }
    else {
      ll aend = (t-i-1) * (psa[n] - psa[i]) + (sta[n] - sta[i]);
      t += (n-i);
      ll bend = bkwb[i+1] + (t-1) * (psb[n] - psb[i]);

      /*
      printf("going: %lld\n", aend);
      printf("back: %lld\n", bend);
      */

      bef += bend;
      bef += aend;
    }
    //printf("%lld\n", bef);
    ans = max(ans, bef);
  }
  //printf("0: %lld\n", sta[n] + (n-1) * psb[n] + bkwb[1] - psa[n]);
  ans = max(ans, sta[n] + (n-1) * psb[n] + bkwb[1] - psa[n]);

  printf("%lld\n", ans);

	return 0;
}

