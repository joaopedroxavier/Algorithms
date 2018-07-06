//
// Elohim Essaim, Elohim Essaim, I implore you...
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

const int N = 1e6+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

struct point {
  ld x, y;

  point(): x(0), y(0) {}
  point(ld x, ld y): x(x), y(y) {}

  point operator+(point p) const { return point(x+p.x, y+p.y); }
  point operator-(point p) const { return point(x-p.x, y-p.y); }

  ld operator~() const { return sqrt(x*x + y*y); }
  
  bool operator<(point p) const { return y == p.y ? x < p.x : y < p.y; }
};

int n;
point p[N];

ld dist(point a, point b) { return ~(a-b); }

ld perimeter(point a, point b, point c) { return dist(a,b) + dist(b,c) + dist(c,a); }

set<ii> curr;

ld get(int i, ld d) {
  ld dl = (d / 2 + 4);
  point c = p[i];
  auto it = curr.lower_bound(mp(p[i].y - dl, -1));
  auto jt = curr.upper_bound(mp(p[i].y + dl, n+1));
  for(auto lt = it; lt != jt; lt++) {
    point a = p[lt->second];
    for(auto rt = next(lt); rt != jt; rt++) {
      if(lt == rt) continue;
      point b = p[rt->second];
      d = min(d, perimeter(a,b,c));
    }
  }
  curr.insert(mp(c.y, i));
  return d;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%Lf %Lf", &p[i].x, &p[i].y);
  sort(p, p+n, [](point a, point b){ return a.x == b.x ? a.y < b.y : a.x < b.x; });

  ld ans = perimeter(p[0], p[1], p[2]);
  int l = 0;
  for(int i=3; i<=n; i++) {
    while((p[i] - p[l]).x > ans) {
      l++;
      curr.erase(mp(p[l].y, l));
    }
    ans = get(i, ans);
  }

  printf("%.12Lf\n", ans);
	return 0;
}

