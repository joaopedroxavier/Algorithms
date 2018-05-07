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

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

struct point {
  ld x, y;

  point(): x(0), y(0) {}
  point(ld x, ld y): x(x), y(y) {}

  point operator+(point p) const { return point(x+p.x, y+p.y); }
  point operator-(point p) const { return point(x-p.x, y-p.y); }

  point operator*(ld k) const { return point(x*k, y*k); }
  point operator/(ld k) const { return point(x/k, y/k); }

  ld operator*(point p) const { return x*p.x + y*p.y; }
  ld operator%(point p) const { return x*p.y - y*p.x; }
  ld operator!() const { return x*x + y*y; }

  bool above(point p) { return abs(x - p.x) < EPS and y > p.y; }
  bool below(point p) { return abs(x - p.x) < EPS and y < p.y; }
};

void rotate(point &p, ld ang) {
  ld c = cos(ang), s = sin(ang);
  p = point(p.x * c - p.y * s, p.x * s + p.y * c);
}

point pt[N], bar, initbar;
ld rotation, ini[N];
int pin1, pin2;

point recover(point p, ld ang) {
  point d = p-initbar;
  rotate(d, ang);

  return bar+d;
}

int remainingpin(int j) { return pin1 == j ? pin2 : pin1; }

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  int n, q;
  scanf("%d %d", &n, &q);

  ld ar = 0;
  for(int i=0; i<n; i++) {
    ld x, y; scanf("%Lf %Lf", &x, &y);
    pt[i] = point(x, y);
  }
  point shf = pt[0];
  for(int i=0; i<n; i++) pt[i] = pt[i] - shf;

  for(int i=0; i<n; i++) {
    bar.x += (pt[i].x + pt[(i+1)%n].x) * (pt[i] % pt[(i+1)%n]);
    bar.y += (pt[i].y + pt[(i+1)%n].y) * (pt[i] % pt[(i+1)%n]);
    ar += (pt[i] % pt[(i+1)%n]) / 2.0;
  }
  bar = bar / 6.0;
  bar = bar / ar;

  initbar = bar;
  pin1 = 0, pin2 = 1;

  for(int i=0; i<q; i++) {
    int t; scanf("%d", &t);
    if(t == 1) {
      int a, b; scanf("%d %d", &a, &b);
      a--; b--;

      int pin = remainingpin(a);
      pin1 = b, pin2 = pin;

      point pivot = recover(pt[pin], rotation);
      if(pivot.above(bar)) continue;
      point rel = bar - pivot;
      ld ang;

      if(pivot.below(bar)) ang = PI/2;
      else ang = atan2(rel.y, rel.x);

      rotate(rel, 3*PI/2 - ang);

      rotation += 3*PI/2 - ang;
      bar = pivot + rel;
    } else {
      int a; scanf("%d", &a);
      a--;
      point ans = recover(pt[a], rotation);
      ans = ans + shf;
      printf("%.12Lf %.12Lf\n", ans.x, ans.y);
    }
  }

	return 0;
}
