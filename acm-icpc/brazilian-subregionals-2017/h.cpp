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
  ll x, y;
  
  point(): x(0), y(0) {}
  point(ll x, ll y): x(x), y(y) {}

  point operator+(point p) const { return point(x + p.x, y + p.y); }
  point operator-(point p) const { return point(x - p.x, y - p.y); }

  ll operator%(point p) const { return x * p.y - y * p.x; }
};

vector<int> adj[N];
int n, sz[N];
point ancha, anchb, pt[N];

int dfs(int u) {
  if(sz[u]) return sz[u];

  for(int v : adj[u]) sz[u] = max(sz[u], dfs(v));

  sz[u]++; return sz[u];
}

bool below(point a, point b) {
  bool bl = (a - ancha) % (b - ancha) > 0;
  bool br = (a - anchb) % (b - anchb) < 0;
  return bl and br;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %lld %lld", &n, &ancha.x, &anchb.x);

  for(int i=1; i<=n; i++) {
    ll x, y; scanf("%lld %lld", &x, &y);
    pt[i] = point(x, y);
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) if(below(pt[i], pt[j])) adj[i].push_back(j);
  }

  int ma = 0;
  for(int i=1; i<=n; i++) ma = max(ma, dfs(i));
  printf("%d\n", ma);

	return 0;
}

