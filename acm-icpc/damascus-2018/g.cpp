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

vector<ll> v;

bool divisible(ll a, ll b) { return b % a == 0; }

int t;

ll a[N];
ll prefgc[N], sufgc[N];
ll preflc[N], suflc[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &t);

  while(t--) {
    v.clear();

    ll n, x, y;
    scanf("%lld %lld %lld", &n, &x, &y);

    ll lc = 1, gc = 0;
    for(int i=0; i<n; i++) {
      scanf("%lld", &a[i]);
      if(!divisible(x, a[i]) or !divisible(a[i], y)) v.push_back(i);
      else {
        a[i] /= x;
        gc = __gcd(a[i], gc);
        lc = (a[i] / __gcd(lc, a[i])) * lc;
      }
    }

    if(!divisible(x, y)) {
      printf("-1\n");
      continue;
    }

    if(n == 1) {
      if(x == y) printf("%d\n", v.empty() ? 0 : 1);
      else printf("-1\n");
      continue;
    }

    if(v.size() >= 2) {
      printf("%d\n", (int) v.size());
    }
    else {
      if(v.empty()) {
        if(gc == 1 and lc == y / x) {
          printf("0\n");
          continue;
        }

        prefgc[0] = preflc[0] = a[0];
        for(int i=1; i<n; i++) {
          prefgc[i] = __gcd(a[i], prefgc[i-1]);
          preflc[i] = (a[i] / __gcd(a[i], preflc[i-1])) * preflc[i-1];
        }

        sufgc[n-1] = suflc[n-1] = a[n-1];
        for(int i=n-2; i>=0; i--) {
          sufgc[i] = __gcd(a[i], sufgc[i+1]);
          suflc[i] = (a[i] / __gcd(a[i], suflc[i+1])) * suflc[i+1];
        }

        bool fd = false;
        for(int i=0; i<n; i++) {
          ll prefl = i == 0 ? 1 : preflc[i-1];
          ll prefr = i == n-1 ? 1 : suflc[i+1];
          ll lcm = (prefl / __gcd(prefl, prefr)) * prefr;

          ll need = (y / x) / lcm;

          ll prefgl = i == 0 ? 0 : prefgc[i-1];
          ll prefgr = i == n-1 ? 0 : sufgc[i+1];
          ll gcd = __gcd(prefgl, prefgr);

          if(__gcd(need, gcd) == 1) fd = true;
        }

        printf("%d\n", fd ? 1 : 2);
      }
      else {
        ll need = (y / x) / lc;
        printf("%d\n", __gcd(need, gc) == 1 ? 1 : 2);
      }
    }
  }

  return 0;
}

