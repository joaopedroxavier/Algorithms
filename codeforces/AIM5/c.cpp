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
#define y1 sdiufdsugf

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 2e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n;
ll x1[N], y1[N], x2[N], y2[N];

multiset<int> xmi, ymi, xma, yma;

bool check(int xl, int yl, int xr, int yr) {
  return xr >= xl and yr >= yl;
}

int retx, rety;

bool test(int i) {
  int xl = x1[i], xr = x2[i];
  int yl = y1[i], yr = y2[i];

  auto it1 = xmi.find(xl);
  auto it2 = xma.find(xr);
  auto it3 = ymi.find(yl);
  auto it4 = yma.find(yr);

  xmi.erase(it1);
  xma.erase(it2);
  ymi.erase(it3);
  yma.erase(it4);

  int mix = *xma.begin();
  int miy = *yma.begin();
  int mx = *prev(xmi.end());
  int my = *prev(ymi.end());

  bool ans = check(mx, my, mix, miy);
  if(ans) retx = mx, rety = my;

  xmi.insert(xl);
  xma.insert(xr);
  ymi.insert(yl);
  yma.insert(yr);

  return ans;
}


int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%lld %lld %lld %lld", &x1[i], &y1[i], &x2[i], &y2[i]);

    xmi.insert(x1[i]);
    ymi.insert(y1[i]);
    xma.insert(x2[i]);
    yma.insert(y2[i]);
  }

  for(int i=0; i<n; i++) if(test(i)) {
    printf("%d %d\n", retx, rety);
    return 0;
  }

	return 0;
}

