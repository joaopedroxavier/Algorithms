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

const int N = 1e2+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

struct point{
  ld x, y;
  
  point(): x(0), y(0) {}
  point(ld x, ld y): x(x), y(y) {}

  point operator+(point p) const { return point(x + p.x, y + p.y); }
  point operator-(point p) const { return point(x - p.x, y - p.y); }

  ld operator*(point p) const { return x*p.x + y*p.y; }
  ld operator%(point p) const { return x*p.y - y*p.x; }

  ld operator!() const { return sqrt(x*x + y*y); }

  bool operator<(point p) const { return x == p.x ? y < p.y : x < p.x; }
};

int n;
vector<point> p;

ld dist(point q, point a, point b) {
  return abs((q-a) % (b-a)) / !(b-a);
}

point ogn;

bool zero(ld l) { return l < EPS and l > -EPS; }
bool pos(ld l) { return l > -EPS; }

bool radial(point a, point b) {
  return zero((a-ogn) % (b-ogn)) ? !(a-ogn) < !(b-ogn) : (a-ogn) % (b-ogn) > 0;
}

vector<point> convex_hull(vector<point> v) {
  vector<point> ans;
  sort(v.begin(), v.end());
  ogn = v[0];

  sort(v.begin(), v.end(), radial);

  ans.push_back(ogn); int sz = 1;
  for(int i=1; i<(int)v.size(); i++) {
    while(ans.size() > 2 and pos((v[i] - ans[sz-2]) % (ans[sz-1] - ans[sz-2]))) {
      ans.pop_back(); sz--;
    }
    ans.push_back(v[i]); sz++;
  }
  return ans;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    ld x, y;
    scanf("%Lf %Lf", &x, &y);
    p.push_back(point(x, y));
  }

  p = convex_hull(p); n = p.size();

  ld ans = 1e9;
  for(int i=0; i<n; i++) {
    ld ma = 0;
    int l = i, r = (i+1)%n;
    for(int j=0; j<n; j++) if(j != l and j != r) {
      ma = max(ma, dist(p[j], p[l], p[r]));
    }
    ans = min(ans, ma);
  }

  printf("%.12Lf\n", ans);

  return 0;
}

