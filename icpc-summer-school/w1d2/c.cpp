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

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x,y) and le(x,y); }

struct point {
    type x, y;

    point(): x(0), y(0) {}
    point(type x, type y) : x(x), y(y) {}

    point operator -() { return point(-x, -y); }
    point operator +(point p) { return point(x+p.x, y+p.y); }
    point operator -(point p) { return point(x-p.x, y-p.y); }

    point operator *(type k) { return point(k*x, k*y); }

    type operator *(point p) { return x*p.x + y*p.y; }
    type operator %(point p) { return x*p.y - y*p.x; }
    ld operator ~() { return hypot(x,y); }

    bool operator <(point p) { return x != p.x ? x < p.x : y < p.y; }
    
};

point origin;

bool radial(point p, point q) {
  ll cr = (p - origin) % (q - origin);
  return cr == 0 ? ~(p-origin) < ~(q-origin) : cr > 0;
}
    
vector<point> convex_hull(vector<point> pts) {
    vector<point> ch;
    point mn = pts[0];

    for(point p : pts) if (p.x < mn.x or (p.x == mn.x and p.y < mn.y)) mn = p;

    origin = mn;

    sort(pts.begin(), pts.end(), radial);

    int sz = 0;

    for(point p : pts) {
        while(sz > 1 and (p - ch[sz-2]) % (p - ch[sz-1]) <= 0) sz--, ch.pop_back();
        ch.pb(p), sz++;
    }

    return ch;
}

int n;
map<pair<ll, ll>, int> ord;

int main() {
    scanf("%d", &n);
    vector<point> points;

    for(int i=0; i<n; i++) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        point p = point(x,y);
        points.pb(p);

        ord[mp(x,y)] = i;
    }

    vector<point> convexhull = convex_hull(points);

    n = convexhull.size();
    printf("%d\n", n);
    for(point p : convexhull) {
        printf("%d ", ord[mp(p.x, p.y)] + 1);
    }
    printf("\n");

    ld per = 0;
    for(int i=0; i < (int) convexhull.size(); i++) {
        ld dist = ~(convexhull[i] - convexhull[(i+1)%n]);
        per = per + dist;
    }

    ll area = 0;
    for(int i=0; i < (int) convexhull.size(); i++) {
        point p1 = convexhull[i], p2 = convexhull[(i+1)%n];
        area += abs(p1 % p2);
    }

    printf("%.20Lf\n", per);
    printf("%lld%s\n", area/2, area%2 ? ".5" : ".0");
}
