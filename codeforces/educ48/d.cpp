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

const int N = 1e2+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int l[N], r[N], a[N], b[N];
int n, m;
ll ans[N][N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++) scanf("%d", &l[i]);
  for(int i=0; i<m; i++) scanf("%d", &r[i]);

  ll ansr = 0, ansc = 0;
  for(int i=0; i<n; i++) ansr ^= l[i];
  for(int i=0; i<m; i++) ansc ^= r[i];

  if(ansr != ansc) return printf("NO\n"), 0;

  for(int i=0; i<40; i++) {
    ll bt = (1ll << i);
    for(int k=0; k<n; k++) a[k] = bt & l[k];
    for(int k=0; k<m; k++) b[k] = bt & r[k];

    for(int k=1; k<n; k++) {
      ans[k][0] += a[k];
    }

    for(int k=1; k<m; k++) {
      ans[0][k] += b[k];
    }

    ll zz = 0;
    for(int k=1; k<m; k++) {
      zz ^= b[k];
    }
    ans[0][0] += zz ^ a[0];
  }

  printf("YES\n");
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) printf("%lld ", ans[i][j]);
    printf("\n");
  }

  return 0;
}

