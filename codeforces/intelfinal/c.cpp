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
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

map<iiii, ll> tmp;
ll n, m, k;

void go(int i, int j, int dir1, int dir2, ll t) {
  if(tmp.count(mp(mp(i, j), mp(dir1, dir2)))) return;
  if(i == n and j == m) return;
  if(i == n and j == 0) return;
  if(i == 0 and j == m) return;
  if(i == 0 and j == 0 and t != 0) return;
  tmp[mp(mp(i,j), mp(dir1, dir2))] = t;

  if(dir1 == 1 and dir2 == 1) {
    int r = m - j;
    if(i + r <= n) {
      if(i + r == n) go(i + r, m, -dir1, -dir2, t + r);
      else go(i + r, m, -dir1, dir2, t + r);
    }
    else {
      int r = n - i;
      go(n, r, dir1, -dir2, t + r);
    }
  }
  if(dir1 == 1 and dir2 == -1) {
    int r = m - j;
    if(i - r >= 0) {
      if(i - r == 0) go(i - r, m, -dir1, -dir2, t + r);
      else go(i - r, m, -dir1, dir2, t + r);
    }
    else {
      go(0, i, dir1, -dir2, t + i);
    }
  }
  if(dir1 == -1 and dir2 == 1) {
    int r = j;
    if(i + r <= n) {
      if(i + r == n) go(i + r, 0, -dir1, -dir2, t + r);
      else go(i + r, 0, -dir1, dir2, t + r);
    }
    else {
      int r = n - i;
      go(n, m-r, dir1, -dir2, t + r);
    }
  }
  if(dir1 == -1 and dir2 == -1) {
    int r = j;
    if(i - r >= 0) {
      if(i - r == 0) go(i - r, 0, -dir1, -dir2, t + r);
      else go(i - r, 0, -dir1, dir2, t + r);
    }
    else {
      int r = i;
      go(0, m-r, dir1, -dir2, t + i);
    }
  }
}

bool swp;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld %lld", &n, &m, &k);
  if(n < m) swp = true, swap(n, m);

  go(0, 0, 1, 1, 0);
  /*
  for(auto pp : tmp) {
    auto p = pp.st;
    printf("%d %d %d %d %lld\n", p.st.st, p.st.nd, p.nd.st, p.nd.nd, pp.nd);
  }
  */

  for(int i=0; i<k; i++) {
    ll x, y; scanf("%lld %lld", &x, &y);
    if(swp) swap(x, y);

    ll ans = LINF;
    ii p1 = mp(max(0ll, x-y), max(0ll, y-x));
    if(tmp.count(mp(p1, mp(1, 1)))) {
      ll t = tmp[mp(p1, mp(1, 1))] + abs(max(0ll, x-y) - x);
      // printf("1: %lld\n", t);
      ans = min(ans, t);
    }
    ii p2 = mp(max(0ll, x-(m-y)), min(m, y+x));
    if(tmp.count(mp(p2, mp(-1, 1)))) {
      ll t = tmp[mp(p2, mp(-1, 1))] + abs(max(0ll, x-(m-y)) - x);
      // printf("2: %lld\n", t);
      ans = min(ans, t);
    }
    ii p3 = mp(min(n, x+y), max(0ll, y-(n-x)));
    if(tmp.count(mp(p3, mp(1, -1)))) {
      ll t = tmp[mp(p3, mp(1, -1))] + abs(min(n, x+y) - x);
      // printf("3: %lld\n", t);
      ans = min(ans, t);
    }
    ii p4 = mp(min(n, x+(m-y)), min(m, y+(n-x)));
    if(tmp.count(mp(p4, mp(-1, -1)))) {
      ll t = tmp[mp(p4, mp(-1, -1))] + abs(min(n, x+(m-y)) - x);
      // printf("4: %lld\n", t);
      ans = min(ans, t);
    }

    if(ans == LINF) printf("-1\n");
    else printf("%lld\n", ans);
  }

	return 0;
}

