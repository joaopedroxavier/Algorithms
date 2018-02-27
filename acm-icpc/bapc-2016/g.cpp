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

struct ManhattanLine {
  ll x1, y1, x2, y2;
  ll k;
  int type;

  ManhattanLine(ll x1, ll y1, ll x2, ll y2): x1(x1), y1(y1), x2(x2), y2(y2) {
    if(x1 == x2 and y1 == y2) type = 0;
    else if(y1 < y2) type = 1, k = y1-x1;
    else type = -1, k = y1+x1;
  }

  bool inside(ll x, ll y) {
    if(type == 0) return x == x1 and y == y1;
    return (x - x1) * (y2 - y1) == (y - y1) * (x2 - x1) and between(x);
  }

  bool between(ll x) {
    return x1 <= x and x <= x2;
  }

  bool operator<(ManhattanLine m) const { return mp(x1, y1) == mp(m.x1, m.y1) ? mp(x2, y2) < mp(m.x2, m.y2) : mp(x1, y1) < mp(m.x1, m.y1); }
  bool operator!=(ManhattanLine m) const { return mp(x1, y1) != mp(m.x1, m.y1) and mp(x2, y2) != mp(m.x2, m.y2); }

  void print() {
    printf("Line from (%lld, %lld) to (%lld, %lld)\n", x1, y1, x2, y2);
  }
};

ManhattanLine intersect(ManhattanLine m1, ManhattanLine m2) {
  //printf("Intersecting: \n");
  //m1.print(); m2.print();
  if(m1.type == 0) {
    return m2.inside(m1.x1, m1.y1) ? ManhattanLine(m1.x1, m1.y1, m1.x1, m1.y1) : ManhattanLine(INF, INF, INF, INF);
  }
  if(m2.type == 0) {
    return m1.inside(m2.x1, m2.y1) ? ManhattanLine(m2.x1, m2.y1, m2.x1, m2.y1) : ManhattanLine(INF, INF, INF, INF);
  }
  if(m1.type == m2.type) {
    if(m1.x1 > m2.x1) swap(m1, m2);

    if(m1.x2 < m2.x2) {
      return m1.inside(m2.x1, m2.y1) ? ManhattanLine(m2.x1, m2.y1, m1.x2, m1.y2) : ManhattanLine(INF, INF, INF, INF);
    }
    else {
      return m1.inside(m2.x1, m2.y1) ? ManhattanLine(m2.x1, m2.y1, m2.x2, m2.y2) : ManhattanLine(INF, INF, INF, INF);
    }
  }
  else {
    if(m1.type == -1) swap(m1, m2);

    ll y = (m1.k+m2.k)/2; ll x = (m2.k-m1.k)/2;
    if((m1.k&1) != (m2.k&1)) return ManhattanLine(INF, INF, INF, INF);
    else return m1.inside(x, y) and m2.inside(x, y) ? ManhattanLine(x, y, x, y) : ManhattanLine(INF, INF, INF, INF);
  }
}

set<ManhattanLine> lines;
int n;

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    ll x, y, d;
    scanf("%lld %lld %lld", &x, &y, &d);

    ManhattanLine m1 = ManhattanLine(x, y+d, x+d, y);
    ManhattanLine m2 = ManhattanLine(x-d, y, x, y+d);
    ManhattanLine m3 = ManhattanLine(x-d, y, x, y-d);
    ManhattanLine m4 = ManhattanLine(x, y-d, x+d, y);

    /*
    printf("line m1 starting with (%lld, %lld) and ending in (%lld, %lld)\n", m1.x1, m1.y1, m1.x2, m1.y2);
    printf("line m2 starting with (%lld, %lld) and ending in (%lld, %lld)\n", m2.x1, m2.y1, m2.x2, m2.y2);
    printf("line m2 starting with (%lld, %lld) and ending in (%lld, %lld)\n", m3.x1, m3.y1, m3.x2, m3.y2);
    printf("line m2 starting with (%lld, %lld) and ending in (%lld, %lld)\n", m4.x1, m4.y1, m4.x2, m4.y2);
    */

    if(i == 0) {
      lines.insert(m1);
      lines.insert(m2);
      lines.insert(m3);
      lines.insert(m4);
    }

    else {
      set<ManhattanLine> currentlines;
      for(auto m : lines) if(intersect(m1, m) != ManhattanLine(INF, INF, INF, INF)) {
        currentlines.insert(intersect(m1, m));
      }
      for(auto m : lines) if(intersect(m2, m) != ManhattanLine(INF, INF, INF, INF)) {
        currentlines.insert(intersect(m2, m));
      }
      for(auto m : lines) if(intersect(m3, m) != ManhattanLine(INF, INF, INF, INF)) {
        currentlines.insert(intersect(m3, m));
      }
      for(auto m : lines) if(intersect(m4, m) != ManhattanLine(INF, INF, INF, INF)) {
        currentlines.insert(intersect(m4, m));
      }

      lines = currentlines;
    }
    
    /*
    printf("current manhattan lines: \n");
    for(auto m : lines) {
      printf("a line starting with (%lld, %lld) and ending in (%lld, %lld)\n", m.x1, m.y1, m.x2, m.y2);
    }
    */
  }

  set<pair<ll, ll>> candidates;
  for(auto m : lines) {
    if(m.type != 0) return printf("uncertain\n"), 0;

    candidates.insert(mp(m.x1, m.y1));
  }
  if(candidates.size() == 1) {
    ManhattanLine m = *lines.begin();
    printf("%lld %lld\n", m.x1, m.y1);
  }
  else if(candidates.size() > 1) printf("uncertain\n");
  else {
    printf("impossible\n");
  }

	return 0;
}

