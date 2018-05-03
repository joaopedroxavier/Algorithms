#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

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

struct point {
  ll x, y;
  int quad;
  point():x(0), y(0) {}
  point(ll x, ll y):x(x), y(y) {
  }

  point operator+(point p) const { return point(x+p.x, y+p.y); }
  point operator-(point p) const { return point(x-p.x, y-p.y); }
  
  ll operator*(point p) const { return x*p.x + y*p.y; }
  ll operator%(point p) const { return x*p.y - y*p.x; }

  ll operator~() const { return sqrt(x*x + y*y); }
};

int n; ll a, b;
point p[N], v[N];
map<ll, vector<ll>> m;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %lld %lld", &n, &a, &b);

  point lineparam = point(1ll, a);
  for(int i=0; i<n; i++) {
    ll x, vx, vy;
    scanf("%lld %lld %lld", &x, &vx, &vy);
    p[i] = point(x, a*x + b);
    v[i] = point(vx, vy);

    ll cross = v[i] % lineparam;
    m[cross].push_back(v[i] * lineparam);
  }

  ll ans = 0;
  for(auto it : m) {
    vector<ll> parc = it.second;
    ll sz = (ll) parc.size();
    ans += (sz*(sz-1))/2;

    map<ll, ll> am;
    for(ll j : parc) {
      am[j]++;
    }

    for(auto j : am) {
      ll s = j.second;
      ans -= (s*(s-1))/2;
    }
  }

  printf("%lld\n", ans * 2);
  return 0;
}
