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
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll a[N], s[N], pos[N], last[N];
int n, m, k;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d %d", &n, &m, &k);
  for(int i=0; i<=n; i++) pos[i] = true;
  for(int i=0; i<m; i++) scanf("%lld", &s[i]), pos[s[i]] = false;
  for(int i=1; i<=k; i++) scanf("%lld", &a[i]);

  last[0] = pos[0] ? 0 : -1;
  for(int i=1; i<=n; i++) last[i] = pos[i] ? i : last[i-1];

  ll ans = LINF;

  for(int i=1; i<=k; i++) {
    ll cnt = 0;
    for(int j=0; j<n; j++) {
      if(last[j] == -1 or last[j] + i <= j) {
        cnt = -1;
        break;
      }
      j = last[j];
      cnt++;
      j += i - 1;
    }
    if(~cnt) ans = min(ans, cnt * a[i]);
  }

  printf("%lld\n", ans == LINF ? -1 : ans);

	return 0;
}

