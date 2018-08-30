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

ll a, b, h, w;
vector<ll> use;
vector<ll> extra;
ll mul[N];

int n, sz;

int check(int mask) {
  int usea = 0, useb = 0;
  ll mh = h, mw = w;
  vector<ll> forb;
  for(int i=0; i<sz; i++) {
    if(mask & (1<<i)) {
      if(mh >= a) continue;
      usea++; 
      mh = mh * use[i];
    }
    else {
      forb.push_back(use[i]);
    }
  }
  for(ll i : extra) forb.push_back(i);
  sort(forb.begin(), forb.end(), [](ll a, ll b) { return a > b; });
  for(ll p : forb) {
    if(mw >= b) break;
    useb++;
    mw *= p;
  }
  return (mh >= a and mw >= b) ? usea + useb : INF;
}

int check2(int mask) {
  int usea = 0, useb = 0;
  ll mh = h, mw = w;
  vector<ll> forb;
  for(int i=0; i<sz; i++) {
    if(mask & (1<<i)) {
      if(mw >= b) continue;
      useb++; 
      mw = mw * use[i];
    }
    else {
      forb.push_back(use[i]);
    }
  }
  for(ll i : extra) forb.push_back(i);
  sort(forb.begin(), forb.end(), [](ll a, ll b) { return a > b; });
  for(ll p : forb) {
    if(mh >= a) break;
    usea++;
    mh *= p;
  }
  return (mh >= a and mw >= b) ? usea + useb : INF;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld %lld %lld %d", &a, &b, &h, &w, &n);
  for(int i=0; i<n; i++) scanf("%lld", &mul[i]);

  sort(mul, mul+n);

  int ans = INF;
  if(n > 34) {
    for(int i=n-1; i>=max(0, n-17); i--) use.push_back(mul[i]);
    if(n-17 > 0) {
      for(int i=n-18; i>=max(0, n-40); i--) if(extra.size() < 17) extra.push_back(mul[i]);
    }
    sz = (int) use.size();

    for(int i=0; i<(1<<sz); i++) ans = min(ans, check(i));
    for(int i=0; i<(1<<sz); i++) ans = min(ans, check2(i));
    swap(a, b);
    for(int i=0; i<(1<<sz); i++) ans = min(ans, check(i));
    for(int i=0; i<(1<<sz); i++) ans = min(ans, check2(i));
  }
  else {
    for(int i=n-1; i>=max(0, n-17); i--) use.push_back(mul[i]);
    if(n-17 > 0) {
      for(int i=n-18; i>=max(0, n-40); i--) if(extra.size() < 17) extra.push_back(mul[i]);
    }
    sz = (int) use.size();

    for(int i=0; i<(1<<sz); i++) ans = min(ans, check(i));
    for(int i=0; i<(1<<sz); i++) ans = min(ans, check2(i));
    swap(a, b);
    for(int i=0; i<(1<<sz); i++) ans = min(ans, check(i));
    for(int i=0; i<(1<<sz); i++) ans = min(ans, check2(i));

    use.clear();
    extra.clear();
    for(int i=0; i<17; i++) use.push_back(mul[i]);
    if(n >= 17) {
      for(int i=17; i<n; i++) if(extra.size() < 17) extra.push_back(mul[i]);
    }
    sz = (int) use.size();

    for(int i=0; i<(1<<sz); i++) ans = min(ans, check(i));
    for(int i=0; i<(1<<sz); i++) ans = min(ans, check2(i));
    swap(a, b);
    for(int i=0; i<(1<<sz); i++) ans = min(ans, check(i));
    for(int i=0; i<(1<<sz); i++) ans = min(ans, check2(i));

  }

  printf("%d\n", ans == INF ? -1 : ans);

  return 0;
}

