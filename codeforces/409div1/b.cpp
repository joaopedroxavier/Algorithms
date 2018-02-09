#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

struct point {
  ld x, y;

  point(): x(0), y(0) {}
  point(ld a, ld b): x(a), y(b) {}

  point operator+(point p) const { return point(x+p.x, y+p.y); }
  point operator-(point p) const { return point(x-p.x, y-p.y); }

  point operator*(ld k) const { return point(x*k, y*k); }
  point operator/(ld k) const { return point(x*k, y*k); }

  ld operator*(point p) const { return x*p.x + y*p.y; }
  ld operator%(point p) const { return x*p.y - y*p.x; }

  ld operator~() const { return sqrt(x*x + y*y); }
};

ld dist(point a, point b, point c) {
  ld cross = abs((c-a) % (b-a));
  return cross / (~(b-a));
}

int n;
point p[N];

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    scanf("%Lf %Lf", &p[i].x, &p[i].y);
  }

  ld ans = 1e18;
  for(int i=0; i<n; i++) {
    ld d = dist(p[i], p[(i+2)%n], p[(i+1)%n]);
//    printf("%d %d %d %Lf\n", i, (i+1)%n, (i+2)%n, d);
    ans = min(ans, d/2);
  }

  printf("%.9Lf\n", ans);

	return 0;
}

