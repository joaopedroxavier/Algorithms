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

const int N = 1e2+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

struct point {
  ld x, y;

  point(): x(0), y(0) {}
  point(ld x, ld y): x(x), y(y) {}

  point operator+(point p) const { return {x+p.x, y+p.y}; }
  point operator-(point p) const { return {x-p.x, y-p.y}; }
  point operator/(ld k) const { return {x / k, y / k}; }
  point operator*(ld k) const { return {x * k, y * k}; }

  ld operator*(point p) const { return x*p.x + y*p.y; }
  ld operator%(point p) const { return x*p.y - y*p.x; }

  ld operator!() const { return sqrt(x*x + y*y); }
  point operator~() const { return {-y, x}; }
};

void rotate(point &p, ld ang) {
  ld nx = p.x * cos(ang) - p.y * sin(ang);
  ld ny = p.x * sin(ang) + p.y * cos(ang);
  p.x = nx; p.y = ny;
}

struct circle {
  point ct; ld r;

  circle() : ct(), r(0) {}
  circle(point ct, ld r) : ct(ct), r(r) {}
  
  bool intersect(circle c) { return !(ct - c.ct) - (r + c.r) < -EPS; }
};

bool spannable(circle a, circle b, ld rd) { return 2*rd + a.r + b.r > !(a.ct - b.ct) - EPS; }
bool spannable_ver(circle a, ld k, ld rd) { return 2*rd > abs(k - a.ct.x) - a.r - EPS; }
bool spannable_hor(circle a, ld k, ld rd) { return 2*rd > abs(k - a.ct.y) - a.r - EPS; }

circle span(circle a, circle b, ld rd, int x) {
  ld ra = a.r + rd;
  ld rb = b.r + rd;

  point par = (b.ct - a.ct);
  ld rc = !par;
  par = par / rc; 
  ld ang = acos((ra*ra + rc*rc - rb*rb) / (2*ra*rc));
  rotate(par, ~x ? ang : -ang);

  par = par * ra;
  
  return circle(a.ct + par, rd);
}

circle span_ver(circle a, ld k, ld rd, int x) {
  ld ra = a.r + rd;
  point par = point(1, 0);

  if(k < a.ct.x) par.x = -par.x;

  ld ang = acos(abs(k - a.ct.x - rd) / ra);
  rotate(par, ~x ? ang : -ang);

  par = par * ra;
  return circle(a.ct + par, rd);
}

circle span_hor(circle a, ld k, ld rd, int x) {
  ld ra = a.r + rd;
  point par = point(0, 1);

  if(k < a.ct.y) par.y = -par.y;

  ld ang = acos(abs(k - a.ct.y - rd) / ra);
  rotate(par, ~x ? ang : -ang);

  par = par * ra;
  return circle(a.ct + par, rd);
}

int t, n;
ld w, h;
circle circles[N];

bool bounded(circle c) {
  return -EPS < c.ct.x - c.r and c.ct.x + c.r < w + EPS and
         -EPS < c.ct.y - c.r and c.ct.y + c.r < h + EPS;
}

bool fit(circle c, int i, int j) {
  for(int k=0; k<n; k++) if(k != i and k != j and c.intersect(circles[k])) return false;
  return bounded(c);
}

bool check(ld x) {
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) if(spannable(circles[i], circles[j], x)) {
      circle fst = span(circles[i], circles[j], x, 1);
      if(fit(fst, i, j)) return true;
      circle snd = span(circles[i], circles[j], x, -1);
      if(fit(snd, i, j)) return true;
    }
  }

  for(int i=0; i<n; i++) {
    if(spannable_hor(circles[i], 0, x)) {
      circle fst = span_hor(circles[i], 0, x, 1);
      if(fit(fst, i, i)) return true;
      circle snd = span_hor(circles[i], 0, x, -1);
      if(fit(snd, i, i)) return true;
    }
    if(spannable_hor(circles[i], h, x)) {
      circle fst = span_hor(circles[i], h, x, 1);
      if(fit(fst, i, i)) return true;
      circle snd = span_hor(circles[i], h, x, -1);
      if(fit(snd, i, i)) return true;
    }
    if(spannable_ver(circles[i], 0, x)) {
      circle fst = span_ver(circles[i], 0, x, 1);
      if(fit(fst, i, i)) return true;
      circle snd = span_ver(circles[i], 0, x, -1);
      if(fit(snd, i, i)) return true;
    }
    if(spannable_ver(circles[i], w, x)) {
      circle fst = span_ver(circles[i], w, x, 1);
      if(fit(fst, i, i)) return true;
      circle snd = span_ver(circles[i], w, x, -1);
      if(fit(snd, i, i)) return true;
    }
  }

  circle ul = circle(point(x, h-x), x);
  circle ur = circle(point(w-x, h-x), x);
  circle bl = circle(point(x, x), x);
  circle br = circle(point(w-x, x), x);

  if(fit(ul, n, n)) return true;
  if(fit(ur, n, n)) return true;
  if(fit(bl, n, n)) return true;
  if(fit(br, n, n)) return true;


  return false;
}

inline bool stop(ld l, ld r) {
  ld av = (l+r)/2;
  return abs(r-l) < 1e-7 or abs(r-l) / av < 1e-7;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &t);

  while(t--) {
    scanf("%Lf %Lf", &w, &h);
    scanf("%d", &n);

    if(n == 0) { printf("%.12Lf\n", min(w,h)/2); continue; }

    for(int i=0; i<n; i++) {
      scanf("%Lf %Lf %Lf", &circles[i].ct.x, &circles[i].ct.y, &circles[i].r);
    }

    ld l = 1e9, r = max(w, h);

    for(int i=0; i<n; i++) {
      l = min(l, (circles[i].ct.x - circles[i].r) / 2);
      l = min(l, (w - circles[i].ct.x + circles[i].r) / 2);
      l = min(l, (circles[i].ct.y - circles[i].r) / 2);
      l = min(l, (h - circles[i].ct.y + circles[i].r) / 2);
    }
    for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) 
      l = min(l, (!(circles[i].ct - circles[j].ct) - (circles[i].r + circles[j].r)) / 2);

    for(int i=0; i<60; i++) {
      if(stop(l, r)) break;
      ld m = (l+r)/2;
      if(check(m)) l = m;
      else r = m;
    }

    printf("%.12Lf\n", l);

  }
  return 0;
}

