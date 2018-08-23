//
// 내가 나인 게 싫은 날
// 영영 사라지고 싶은 날
// 문을 하나 만들자 너의 맘 속에다
// 그 문을 열고 들어가면
// 이 곳이 기다릴 거야
//믿어도 괜찮아 널 위로해줄 magic shop
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

struct point {
  ll x, y;
  int idx, jdx;

  point() : x(0), y(0), idx(0), jdx(0) {}
  point(ld x, ld y, int i, int j) : x(x), y(y), idx(i), jdx(j) {}

  point operator+(point p) const { return point(x+p.x, y+p.y, 0, 0); }
  point operator-(point p) const { return point(x-p.x, y-p.y, 0, 0); }

  ll operator*(point p) const { return x*p.x + y*p.y; }
  ll operator%(point p) const { return x*p.y - y*p.x; }
  bool operator==(point p) const { return x == p.x and y == p.y; }

  ll operator!() const { return sqrt(x*x + y*y); }
  point operator-() const { return point(-x, -y, idx, jdx); }
};

int n, q, ans[N];
point pt[N], qry[N];
vector<point> intervals;

bool convex = true, always, count_parallel;
pair<point, point> last_added;

bool compare_atan(pair<ll, ll> p, pair<ll, ll> q) {
  if(p.second < 0 and q.second >= 0) return false;
  if(q.second < 0 and p.second >= 0) return true;
  if(p.second == 0) return q.second < 0;
  if(q.second == 0) return p.second > 0;
  return p.st * q.nd < q.st * p.nd;
}

bool cmp(point p, point q) {
  pair<ll, ll> tanp = {p.y, p.x};
  pair<ll, ll> tanq = {q.y, q.x};
  if(p % q == 0) {
    return p.jdx < q.jdx;
  }
  return compare_atan(tanp, tanq);
}

void add_interval(point p, point q) {
  if(p.y < 0) p = -p, q = -q;
  else if(p.y == 0 and q.y < 0) p = -p, q = -q;
  if(q.y < 0) {
    count_parallel = true;
    intervals.push_back(point(-1, 0, 0, -1));
    intervals.push_back(point(p.x, p.y, 0, 1));
    q = -q;
    intervals.push_back(point(q.x, q.y, 0, -1));
    intervals.push_back(point(1, 0, 0, 1));
  }
  else {
    intervals.push_back(point(q.x, q.y, q.idx, -1));
    intervals.push_back(point(p.x, p.y, 0, 1));
  }
}

void hull() {
  for(int i=0; i<n; i++) {
    ll cross = (pt[(i+1)%n] - pt[i]) % (pt[i] - pt[(i+n-1)%n]);
    if(cross > 0) {
      point l = pt[(i+1)%n] - pt[i], r = pt[i] - pt[(i+n-1)%n];
      if(!convex and last_added.st == r) {
        last_added = {l, last_added.nd};
      }
      else {
        last_added = {l, r};
      }
      convex = false;
      if(last_added.st % last_added.nd < 0) {
        always = true;
        break;
      }
    }
    else if(cross < 0){
      if(!(last_added.st == last_added.nd)) add_interval(last_added.st, last_added.nd);
      last_added = {point(), point()};
    }
  }
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &q);
  for(int i=0; i<n; i++) {
    scanf("%lld %lld", &pt[i].x, &pt[i].y);
    pt[i].idx = i, pt[i].jdx = 2;
  }

  for(int i=0; i<q; i++) {
    scanf("%lld %lld", &qry[i].x, &qry[i].y);
    point p = point(-qry[i].y, qry[i].x, i, 0);
    if(p.y < 0) p = -p;
    if(p.y == 0 and p.x < 0) p = -p;
    qry[i] = p;
  }

  hull();

  if(always) {
    for(int i=0; i<q; i++) printf("N\n");
    return 0;
  }
  if(convex) {
    for(int i=0; i<q; i++) printf("Y\n");
    return 0;
  }

  for(int i=0; i<q; i++) {
    point p = qry[i];
    if(!p == 0) ans[i] = !convex;
    else intervals.push_back(point(p.x, p.y, p.idx, p.jdx));
  }

  sort(intervals.begin(), intervals.end(), cmp);

  int cum = 0;
  for(point p : intervals) {
    if(p.jdx == 0) {
      ans[p.idx] = p.y == 0 ? count_parallel : cum > 0;
    }
    else {
      cum += p.jdx;
    }
  }

  for(int i=0; i<q; i++) printf("%s\n", ans[i] ? "N" : "Y");

  return 0;
}

