#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

const long double EPS = 1e-9;
const int N=1e3+5;
const ll MOD=1e9+7;
const ll INF=0x3f3f3f3f;

bool ge(ld x, ld y){ return x + EPS > y; }
bool le(ld x, ld y){ return x - EPS < y; }
bool eq(ld x, ld y){ return ge(x,y) and le(x,y); }

struct point{
  int x;
  int y;
  point():x(0),y(0){}
  point(int x, int y):x(x),y(y){}
  point operator -(){ return point(-x, -y); }
  point operator +(point p){ return point(x+p.x, y+p.y); }
  point operator -(point p){ return point(x-p.x, y-p.y); }
  point operator *(int k){ return point(k*x, k*y); }
  point operator /(int k){ return point(x/k, y/k); }
  ll operator *(point p){ return x*p.x + y*p.y; }
  ll operator %(point p){ return x*p.y - y*p.x; }
  bool operator !=(point p){ return x != p.x or y != p.y; }
  int dir(point o, point p){
    ld x = (*this - o) % (p - o);
    return (x > 0) - (x < 0);
  }
  bool on_seg(point p, point q){
    if(this->dir(p,q)) return 0;
    return x >= min(p.x, q.x) and
           x <= max(p.x, q.x) and
           y >= min(p.y, q.y) and
           y <= max(p.y, q.y);
  }
};

vi adj[N];
ld wellx[N], welly[N];
int color[N], w, p;
bool vis[N], imp;
pair<point, point> pipe[N];

int direction(point o, point p, point q){ return p.dir(o,q); }

bool segments_intersect(point p, point q, point a, point b){
  int d1, d2, d3, d4;
  d1 = direction(p, q, a);
  d2 = direction(p, q, b);
  d3 = direction(a, b, p);
  d4 = direction(a, b, q);
  if(d1*d2 < 0 and d3*d4 < 0) return true;
  return p.on_seg(a, b) or q.on_seg(a, b) or 
         a.on_seg(p, q) or b.on_seg(p, q);
}

bool cross(int i, int j){
  return segments_intersect(pipe[i].first, pipe[i].second, pipe[j].first, pipe[j].second) and
         pipe[i].first != pipe[j].first;
}

void dfs(int u){
  for(int v : adj[u]){
    if(color[v] == -1) color[v] = color[u] ^ 1, dfs(v);
    if(color[v] != (color[u] ^ 1)) imp = true;
  }
}

int main(){
  scanf("%d %d", &w, &p);
  for(int i=1;i<=w;i++){
    scanf("%Lf %Lf", &wellx[i], &welly[i]);
  }
  for(int i=1;i<=p;i++){
    int u;
    ld x, y;
    scanf("%d %Lf %Lf", &u, &x, &y);
    point p1 = point(wellx[u], welly[u]);
    point p2 = point(x, y);
    pipe[i] = mp(p1, p2);
  }
  for(ll i=1;i<=p;i++){
    for(ll j=i+1;j<=p;j++){
      if(cross(i,j)){
        adj[i].pb(j), adj[j].pb(i);
      }
//     printf("%lld %lld %s\n", i, j, (cross(i,j) ? ": Se cruzam" : ": Não se cruzam"));
    }
  }
  for(int i=1;i<=p;i++) color[i] = -1;
  for(ll i=1;i<=p;i++) if(color[i] == -1) color[i] = 0,  dfs(i);
//  for(ll i=1;i<=p;i++) printf("%lld ", color[i]);
//  printf("\n");
  printf("%s\n", ((imp) ? "impossible" : "possible"));
  return 0;
}

