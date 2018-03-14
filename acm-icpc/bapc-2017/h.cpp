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

int n, vis[N], cnt[N];
vector<int> adj[N];

struct point {
  ll x, y;

  point(): x(0), y(0) {}
  point(ll x, ll y): x(x), y(y) {}

  point operator+(point p) const { return point(x + p.x, y + p.y); }
  point operator-(point p) const { return point(x - p.x, y - p.y); }

  ll operator*(point p) const { return x * p.x + y * p.y; }
  ll operator%(point p) const { return x * p.y - y * p.x; }

  bool operator==(point p) const { return x == p.x and y == p.y; }
};

bool between(point p, point a, point b) {
  ll sc = (p-a) * (b-a);
  return sc >= 0 and sc <= (b-a) * (b-a);
}

bool op(ll d1, ll d2) { return (d1 > 0 and d2 < 0) or (d1 < 0 and d2 > 0); }

bool cross(point p, point q, point a, point b) {
  ll d1, d2, d3, d4;
  d1 = (a-p) % (p-q);
  d2 = (b-p) % (p-q);
  d3 = (p-a) % (a-b);
  d4 = (q-a) % (a-b);

  if(op(d1,d2) and op(d3,d4)) return true;
  return (d1 == 0 and between(a, p, q))
    or (d2 == 0 and between(b, p, q))
    or (d3 == 0 and between(p, a, b))
    or (d4 == 0 and between(q, a, b));
}

void dfs(int u) {
  vis[u] = 1;
  for(int v : adj[u]) if(!vis[v]){
    dfs(v);
  }
}

pair<point, point> line[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%lld %lld %lld %lld", &line[i].first.x, &line[i].first.y, &line[i].second.x, &line[i].second.y);
  }

  int v = 0, e = 0;
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      if(cross(line[i].first, line[i].second, line[j].first, line[j].second)) {
        adj[i].pb(j); adj[j].pb(i);
        cnt[i]++; cnt[j]++;
      }
    }
  }

  for(int i=0; i<n; i++) {
    v += cnt[i];
    e += max(0, cnt[i] - 1);
  }

  v /= 2;

  int c = 0;
  for(int i=0; i<n; i++) if(!vis[i] and adj[i].size()) c++, dfs(i);

  printf("%d\n", c + e - v);
	return 0;
}

