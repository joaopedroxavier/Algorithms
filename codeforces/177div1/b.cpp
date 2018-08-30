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

ll ans, stir[N][2];

ll fexp(ll b, ll e) {
  if(b == 0) return 0;
  ll ans = 1;
  while(e) {
    if(e & 1) ans = (ans * b) % MOD;
    b = (b * b) % MOD;
    e >>= 1;
  }
  return ans;
}

ll n, k;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld", &n, &k);

  ll term = fexp(n-k, n-k);
  ll pruf = fexp(k, k-1);
  ans = (pruf * max(1ll, term)) % MOD;

  printf("%lld\n", ans);

  return 0;
}

