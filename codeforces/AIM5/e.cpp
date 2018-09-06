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

const int N = 2e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n;
ll a[N], b[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  
  ll ma = 0;
  for(int i=0; i<n; i++) scanf("%lld", &b[i]), ma = max(ma, b[i]);

  bool eq = true;
  for(int i=1; i<n; i++) eq = eq and (b[i] == b[0]);

  if(eq) {
    if(b[0] != 0) printf("NO\n");
    else {
      printf("YES\n");
      for(int i=0; i<n; i++) printf("1 ");
      printf("\n");
    }
    return 0;
  }

  int idx = 0;
  for(int i=0; i<n; i++) if(b[i] == ma and b[(i+n-1)%n] != ma) idx = i;

  a[idx] = ma;
  a[(idx + n - 1) % n] += ma;
  for(int i=1; i<n; i++) {
    int jdx = (idx + n - i) % n;
    int kdx = (jdx + 1) % n;
    a[jdx] += a[kdx] + b[jdx];
  }

  printf("YES\n");
  for(int i=0; i<n; i++) {
    printf("%lld ", a[i]);
  }
  printf("\n");
  
	return 0;
}

