#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

struct point { 
  ll x, y, z;

  point(): x(0), y(0), z(0) {}
  point(ll x, ll y, ll z): x(x), y(y), z(z) {}

  point operator+(point p) const { return point(x + p.x, y + p.y, z + p.z); }
  point operator-(point p) const { return point(x - p.x, y - p.y, z - p.z); }
  point operator%(point p) const { return point(y*p.z - z*p.y, -x*p.z + z*p.x, x*p.y - y*p.x); }

  ll operator*(point p) const { return x*p.x + y*p.y + z*p.z; }
};

point points[4];

int sgn(ll x) { return x > 0 ? 1 : (x < 0 ? -1 : 0); }

int missing(bitset<4> b) {
  for(int i=0; i<4; i++) if(!b[i]) return i;
  return 0;
}

bool check(bitset<4> b, point x) {
  point p[3], other; int it=0;

  for(int i=0; i<4; i++) {
    if(b[i]) p[it++] = points[i];
    else other = points[i];
  }

  point n = (p[2] - p[0]) % (p[1] - p[0]);
  return sgn((x - p[0]) * n) == -sgn((other - p[0])*n);
}

int t;
bool ans[4];
point obs;

int main(){
  scanf("%d", &t);

  while(t--) {
    ll x, y, z;
    scanf("%lld %lld %lld", &x, &y, &z);
    points[0] = point(x, y, z);

    scanf("%lld %lld %lld", &x, &y, &z);
    points[1] = point(x, y, z);

    scanf("%lld %lld %lld", &x, &y, &z);
    points[2] = point(x, y, z);

    scanf("%lld %lld %lld", &x, &y, &z);
    points[3] = point(x, y, z);

    scanf("%lld %lld %lld", &x, &y, &z);
    obs = point(x, y, z);

    for(int i=0; i<16; i++) {
      bitset<4> b = bitset<4>(i);
      if(b.count() == 3) {
        int j = missing(b);
        ans[j] = check(b, obs);
      }
    }

    for(int i=0; i<4; i++) printf("%s", ans[i] ? "Y" : "N");
    printf("\n");
  }

	return 0;
}

