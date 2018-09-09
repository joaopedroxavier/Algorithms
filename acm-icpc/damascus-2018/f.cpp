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
const int MOD = 7901;
const int INF = 0x3f3f3f3f;

ll f[N], cnt[N];
int n, t;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &t);

  f[0] = 1;
  for(int i=1; i<N; i++) f[i] = (i * f[i-1]) % MOD;

  while(t--) {
    memset(cnt, 0, sizeof cnt);

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
      int u; scanf("%d", &u);

      cnt[u]++;
    }

    ll ans = 1;
    for(int i=0; i<N; i++) if(cnt[i]) {
      ans = (ans * f[cnt[i]]) % MOD;
    }

    printf("%lld\n", ans);
  }
	return 0;
}

