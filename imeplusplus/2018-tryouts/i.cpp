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

struct point {
  ll x, y;

  point() : x(0), y(0) {}
  point(ll x, ll y) : x(x), y(y) {}

  point operator+(point p) const { return point(x+p.x, y+p.y); }
  point operator-(point p) const { return point(x-p.x, y-p.y); }

  ll operator%(point p) const { return x*p.y - y*p.x; }
};

vector<point> sheena, rose, maria;
int s, r, m;

bool inside(vector<point>& wall, point p, int sz) {
  for(int i=0; i<sz; i++) {
    if((wall[(i+1)%sz] - wall[i]) % (p - wall[i]) < 0) return false;
  }
  return true;
}

string wall_belonging(point p) {
  if(inside(sheena, p, s)) return "Sheena";
  if(inside(rose, p, r)) return "Rose";
  if(inside(maria, p, m)) return "Maria";
  return "Outside";
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d %d", &s, &r, &m);

  for(int i=0; i<s; i++) {
    ll x, y; scanf("%lld %lld", &x, &y);
    sheena.push_back(point(x, y));
  }
  for(int i=0; i<r; i++) {
    ll x, y; scanf("%lld %lld", &x, &y);
    rose.push_back(point(x, y));
  }
  for(int i=0; i<m; i++) {
    ll x, y; scanf("%lld %lld", &x, &y);
    maria.push_back(point(x, y));
  }

  int n; scanf("%d", &n);
  for(int i=0; i<n; i++) {
    point p; scanf("%lld %lld", &p.x, &p.y);
    printf("%s\n", wall_belonging(p).c_str());
  }

	return 0;
}

