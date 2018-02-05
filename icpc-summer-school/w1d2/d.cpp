#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << "==" << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e5+5;
const ld EPS = 1e-9;

typedef long long type;

struct point {
  type x, y;

  point(): x(0), y(0) {}
  point(type x, type y) : x(x), y(y) {}

  point operator -() { return point(-x, -y); }
  point operator +(point p) { return point(x+p.x, y+p.y); }
  point operator -(point p) { return point(x-p.x, y-p.y); }

  point operator *(type k) { return point(k*x, k*y); }
  point operator /(type k) { return point(x/k, y/k); }

  type operator *(point p) { return x*p.x + y*p.y; }
  type operator %(point p) { return x*p.y - y*p.x; }

  bool operator <(point p) const { return x == p.x ? y < p.y : x < p.x; }
  bool operator >(point p) const { return x == p.x ? y > p.y : x > p.x; }
  bool operator !=(point p) const { return x != p.x or y != p.y; }
  bool operator ==(point p) const { return x == p.x and y == p.y; }

  ld abs() { 
    ld xx = x, yy = y;
    return sqrt(xx*xx + yy*yy);
  }

  type abs2() {
    return x*x + y*y;
  }
};

int n, m, k; vector<point> v, w;
vector<point> upper, lower;

int main() {
  scanf("%d %d %d", &n, &m, &k);

  int lfmindex = 0, rtmindex = 0;
  for(int i=0; i<n; i++) {
    ll x, y;
    scanf("%lld %lld", &x, &y);

    v.pb(point(x,y)); w.pb(point(x,y));

    if(point(x,y) < v[lfmindex]) lfmindex = i;
    if(point(x,y) > v[rtmindex]) rtmindex = i;
  }

  sort(w.begin(), w.end());
  point leftmost = v[lfmindex];
  point rightmost = v[rtmindex];

  for(int i=lfmindex; v[i] != rightmost; i = (i-1+n)%n) upper.pb(v[i]);
  for(int i=lfmindex; v[i] != rightmost; i = (i+1)%n) lower.pb(v[i]);
  upper.pb(rightmost), lower.pb(rightmost);

  /*
  for(point p : upper) printf("%lld %lld | ", p.x, p.y);
  printf("\n");
  for(point p : lower) printf("%lld %lld | ", p.x, p.y);
  printf("\n");
  */

  int cnt = 0;
  for(int i=0; i<m; i++) {
    ll x, y;
    scanf("%lld %lld", &x, &y);

    point qry = point(x,y);

    if(x < leftmost.x or x > rightmost.x) continue;

    auto upperit = lower_bound(upper.begin(), upper.end(), qry);
    auto lowerit = lower_bound(lower.begin(), lower.end(), qry);

    if(qry == *upperit or qry == *lowerit) { cnt++; continue; }

    //printf("%lld %lld | %lld %lld | %lld %lld\n", qry.x, qry.y, (*upperit).x, (*upperit).y, (*lowerit).x, (*lowerit).y);

    if( (qry - *upperit) % (*(upperit+1) - *upperit) >= 0 and
        (qry - *lowerit) % (*(lowerit+1) - *lowerit) <= 0 ) cnt++;
  }

  printf("%s\n", cnt >= k ? "YES" : "NO");

  return 0;
}
