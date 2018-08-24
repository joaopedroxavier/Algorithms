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
typedef pair<ll, ll> pll;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 2e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n;
vector<pll> pts;
ll ans[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    ll l, r; scanf("%lld %lld", &l, &r);
    pts.push_back({l, 1});
    pts.push_back({r, -1});
  }

  sort(pts.begin(), pts.end(), [](pll a, pll b) { return a.st == b.st ? a.nd > b.nd : a.st < b.st; });

  int acc = 0; ll last = 0;
  for(int i=0; i<(int)pts.size(); i++) {
    //printf("%lld %lld\n", pts[i].st, pts[i].nd);
    ll x = pts[i].st;
    if(acc > 0) {
      //printf("segment with %lld points covered by %d segments\n", x - last, acc);
      ans[acc] += x - last;
    }

    while(pts[i].st == x and pts[i].nd > 0) {
      acc++; i++;
    }

    //printf("point %lld covered by %d segments\n", x, acc);
    ans[acc]++;

    while(pts[i].st == x and pts[i].nd < 0 and i <= (int) pts.size()) {
      acc--; i++;
    }

    last = x + 1;
    i--;
  }

  for(int i=1; i<=n; i++) printf("%lld ", ans[i]);
  printf("\n");

	return 0;
}

