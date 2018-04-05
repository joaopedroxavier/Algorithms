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
  ll x, y;

  point(): x(0), y(0) {}
  point(ll x, ll y): x(x), y(y) {}

  point operator+(point p) const { return point(x + p.x, y + p.y); }
  point operator-(point p) const { return point(x - p.x, y - p.y); }

  ll operator%(point p) const { return x*p.y - y*p.x; }
};

int n;
vector<point> pts;

bool col(point a, point b, point c) {
  return (b-a) % (c-a) == 0;
}

bool get(vector<point> v) {
  if(v.size() < 2) return true;
  point p = v[0], q = v[1];
  for(int i=2; i<(int)v.size(); i++) if(!col(v[i], p, q)) return false;

  return true;
}

bool can(point a, point b) {
  vector<point> v;
  for(point p : pts) if(!col(a, b, p)) v.push_back(p);

  return get(v);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  srand(time(0));
  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    ll x, y;
    scanf("%lld %lld", &x, &y);
    point p = point(x, y);
    pts.push_back(p);
  }

  for(int i=0; i<500; i++) {
    int p = rand() % n;
    int q = rand() % n;
    if(p == q) q = (q+1)%n;

    if(can(pts[p], pts[q])) return printf("YES\n"), 0;
  }

  printf("NO\n");

	return 0;
}

