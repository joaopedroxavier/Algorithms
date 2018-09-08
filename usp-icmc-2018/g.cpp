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

ld a[N], b[N];
ld ans;
int n, cur, ord[N];

bool can_intersect(int i, int j) {
  return a[j] > a[i] + EPS;
}

ld intersect(int i, int j) {
  return (b[j] - b[i]) / (a[i] - a[j]);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);

  for(int i=0; i<n; i++) scanf("%Lf %Lf", &b[i], &a[i]), ord[i] = i;

  sort(ord, ord+n, [](int i, int j) { return b[i] > b[j]; });

  cur = ord[0];
  for(int i=1; i<n; i++) {
    int j = ord[i];
    if(can_intersect(cur, j)) {
      ans = max(ans, intersect(cur, j));
    }
    else {
      cur = j;
    }
  }

  printf("%.12Lf\n", ans);

  return 0;
}

