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
  ld x, y;

  Point() : x(0), y(0) {}
  Point(ld x, ld y) : x(x), y(y) {}

  Point operator+(Point p) const { return {x+p.x, y+p.y}; }
  Point operator-(Point p) const { return {x-p.x, y-p.y}; }
};

struct Line {
  Point p, q;
  ld a, b;

  Line() : p(), q(), a(0), b(0) {}

  Line(Point p, Point q) : p(p), q(q) {
    a = (q-p).y / (q-p).x;
    b = p.y - a * p.x;
  }

  ld pos(ld y) {
    return (y-b)/a;
  }
};

struct Trapezium {
  ld minb, maxb, minh, maxh;

  Trapezium() : minb(0), maxb(0), minh(0), maxh(0) {}

  Trapezium(Line a, Line b) {
    if(a.p.y < b.q.y) {
      maxh = a.p.y;
      maxb = abs(a.p.x - b.pos(maxh));
    }
    else {
      maxh = b.q.y;
      maxb = abs(b.q.x - a.pos(maxh));
    }

    if(a.q.y > b.p.y) {
      minh = a.q.y;
      minb = abs(a.q.x - b.pos(minh));
    }
    else {
      minh = b.p.y;
      minb = abs(b.p.x - a.pos(minh));
    }
  }

  ld area() {
    ld b = (minb + maxb) / 2;
    ld h = abs(maxh - minh);
    return b * h;
  }
};

Line l[N];
Point p[N];

ld area(int i, int j) {
  return Trapezium(l[i], l[j]).area();
}

bool intersect(int i, int j) {
  return (l[i].p.y > l[j].p.y and l[i].p.y < l[j].q.y) or
         (l[i].q.y > l[j].p.y and l[i].q.y < l[j].q.y);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  int t; scanf("%d", &t);

  while(t--) {
    int n; scanf("%d", &n);

    for(int i=0; i<n; i++) {
      scanf("%Lf %Lf", &p[i].x, &p[i].y);
    }

    for(int i=0; i<n-1; i++) {
      l[i] = Line(p[i], p[i+1]);
    }

    stack<int> st;
    
    ld ans = 0;
    for(int i=0; i<n-1; i++) {
      if(l[i].a < -EPS) {
        st.push(i);
      }
      else if(l[i].a > EPS) {
        while(!st.empty()) {
          int tp = st.top();
          st.pop();

          ans += area(tp, i);
          if(l[tp].p.y > l[i].q.y) {
            l[tp].q.y = l[i].q.y;
            l[tp].q.x = l[tp].pos(l[tp].q.y);
            st.push(tp);
            break;
          }
          else {
            l[i].p.y = l[tp].p.y;
            l[i].p.x = l[i].pos(l[i].p.y);
          }
        }
      }
    }

    printf("%.12Lf\n", ans);
  }
  return 0;
}

