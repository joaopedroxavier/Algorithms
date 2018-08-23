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

const int N = 1e6+5;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;

ll n, a[N], p[N], pot[N], f[N], g[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld", &n);
  for(int i=1; i<=n; i++) scanf("%lld", &a[i]);

  if(n == 1) return printf("%lld\n", a[1]), 0;
  p[1] = a[1];
  for(int i=2; i<=n; i++) p[i] = (p[i-1] + a[i]) % MOD;

  pot[0] = 1;
  for(int i=1; i<=n; i++) pot[i] = (2ll * pot[i-1]) % MOD;

  ll ans = p[n] % MOD;
  ans = (ans + (p[n-1] * 2) % MOD) % MOD;
  for(ll i=n-2; i>0; i--) {
    ll j = n-i;
    ll term = ((j-1) * pot[j-2]) % MOD;
    term = (term + pot[j]) % MOD;
    ans = (ans + (p[i] * term) % MOD) % MOD;
  }
  printf("%lld\n", ans);

	return 0;
}

