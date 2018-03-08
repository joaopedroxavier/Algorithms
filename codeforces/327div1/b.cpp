#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define y1 awueifweuif

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

struct point {
  ld x, y;
  
  point():x(0), y(0) {}
  point(ld x, ld y): x(x), y(y) {}

  void to_pollar(ld m, ld theta) {
    x = m * cos(theta);
    y = m * sin(theta);
  }

  point operator+(point p) const { return point(x + p.x, y + p.y); }
  point operator-(point p) const { return point(x - p.x, y - p.y); }
  point operator*(ld k) const { return point(x * k, y * k); }
  point operator/(ld k) const { return point(x / k, y / k); }

  ld operator*(point p) const { return x * p.x + y * p.y; }
  ld operator%(point p) const { return x * p.y - y * p.x; }
  ld operator~() const { return sqrt(x * x + y * y); }
};

bool cmp(point p1, point p2) { return ~(p2-p1) < EPS; }

point p1, p2, w1, w2;
ld t, v;

point to_pollar(ld m, ld theta) { return point(m * cos(theta), m * sin(theta)); }

ld get(ld m) {
  point change = to_pollar(v, m);
  change = p1 + change * t + (w1 * t);

  point diff = (p2 - change);

  ld x = abs(w2 % diff) / (~(diff));
  ld y = sqrt(v*v - x*x);
  ld vel = y + ((w2 * diff) / (~(diff)));

  return t + (~diff) / vel;
}

ld ans() {
  point diff = p2 - p1;

  ld x = abs(w1 % diff) / (~(diff));
  ld y = sqrt(v*v - x*x);
  ld vel = y + ((w1 * diff) / (~(diff)));
  ld maybe = (~diff) / vel;

  if(maybe < t) return maybe;

  ld d = (w1 * diff) / (~(diff));
  ld l = -abs(acos(abs(d)/v)), r = -l;
  ld th = p2.y < p1.y ? -acos(diff.x / (~diff)) : acos(diff.x / (~diff));
  l += th, r += th;
  if(l > r) swap(l, r);

  for(int i=0; i<1000; i++) {
    ld m1 = (2*l + r)/3;
    ld m2 = (l + 2*r)/3;

    if(get(m1) < get(m2)) r = m2;
    else l = m1;
  
  }

  return get(l);
}

ld x1, y1, x2, y2;
ld vx, vy, wx, wy;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%Lf %Lf %Lf %Lf", &x1, &y1, &x2, &y2);
  p1 = point(x1, y1), p2 = point(x2, y2);

  scanf("%Lf %Lf", &v, &t);

  scanf("%Lf %Lf %Lf %Lf", &vx, &vy, &wx, &wy);
  w1 = point(vx, vy), w2 = point(wx, wy);

  printf("%.20Lf\n", cmp(p1,p2) ? 0 : ans());

  return 0;
}

