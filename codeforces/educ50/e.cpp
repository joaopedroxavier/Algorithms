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

struct Point {
  ll x, y;

  Point() : x(0), y(0) {}
  Point(ll x, ll y) : x(x), y(y) {}

  Point operator+(Point p) const { return {x+p.x, y+p.y}; }
  Point operator-(Point p) const { return {x-p.x, y-p.y}; }

  ll operator%(Point p) const { return x*p.y - y*p.x; }
  ll operator*(Point p) const { return x*p.x + y*p.y; }

  bool operator<(Point p) const { return x == p.x ? y < p.y : x < p.x; }
};

struct Line {
  Point p, q;
};

bool intersect(Line a, Line b) {
  ll crossbp = (a.q - a.p) % (b.p - a.p);
  ll crossbq = (a.q - a.p) % (b.q - a.p);

  if(crossbp == 0 or crossbq == 0) return false;

  crossbp /= abs(crossbp);
  crossbq /= abs(crossbq);

  ll crossap = (b.q - b.p) % (a.p - b.p);
  ll crossaq = (b.q - b.p) % (a.q - b.p);

  if(crossap == 0 or crossaq == 0) return false;

  crossap /= abs(crossap);
  crossaq /= abs(crossaq);

  return crossbp * crossbq < 0 and crossap * crossaq < 0;
}

bool int_intersect(Line a, Line b) {
  if(!intersect(a, b)) return false;
  Point r = a.q - a.p, s = b.q - b.p, c = Point(a.p % a.q, b.p % b.q);

  ll x = Point(r.x, s.x) % c;
  ll y = Point(r.y, s.y) % c;
  ll d = r % s;

  return x % d == 0 and y % d == 0;
}

Point intersection(Line a, Line b) {
  Point r = a.q - a.p, s = b.q - b.p, c = Point(a.p % a.q, b.p % b.q);

  ll x = Point(r.x, s.x) % c;
  ll y = Point(r.y, s.y) % c;
  ll d = r % s;

  return Point(x/d, y/d);
}

bool fallp(Point p, Line l) {
  ll cross = (p - l.p) % (l.q - l.p);
  ll dotp = (p - l.p) * (l.q - l.p);
  ll test = (l.q - l.p) * (l.q - l.p);

  return cross == 0 and dotp >= 0 and dotp <= test;
}

bool fall(Line a, Line b) {
  return fallp(a.p, b) or fallp(a.q, b) or fallp(b.p, a) or fallp(b.q, a);
}

Point fallpoint(Line a, Line b) {
  if(fallp(a.p, b)) return a.p;
  if(fallp(a.q, b)) return a.q;
  if(fallp(b.p, a)) return b.p;
  return b.q;
}

map<Point, set<int>> intr;
int n;
Line l[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    Point p, q;
    scanf("%lld %lld %lld %lld", &p.x, &p.y, &q.x, &q.y);
    l[i] = {p, q};
  }

  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      if(fall(l[i], l[j])) {
        Point fallpt = fallpoint(l[i], l[j]);
        intr[fallpt].insert(i);
        intr[fallpt].insert(j);
      }
      else if(int_intersect(l[i], l[j])) {
        Point intp = intersection(l[i], l[j]);
        intr[intp].insert(i);
        intr[intp].insert(j);
      }
    }
  }

  ll ans = 0;
  for(int i=0; i<n; i++) {
    ll dx = abs(l[i].p.x - l[i].q.x);
    ll dy = abs(l[i].p.y - l[i].q.y);

    //printf("%d %lld\n", i, __gcd(dx, dy) + 1);
    ans += __gcd(dy, dx) + 1;
  }

  for(auto p : intr) {
    //printf("%lld %lld %d\n", p.st.x, p.st.y, (int) p.nd.size());
    ans -= (p.nd.size() - 1);
  }

  printf("%lld\n", ans);

	return 0;
}

