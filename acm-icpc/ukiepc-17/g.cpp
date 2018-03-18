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
typedef pair<ii, int> iii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int dx[] = {+0, +0, +1, -1, +0, +0};
int dy[] = {+1, -1, +0, +0, +0, +0};
int dz[] = {+0, +0, +0, +0, +1, -1};

struct point{
  int x, y, z;

  point(): x(0), y(0), z(0) {}
  point(int x, int y, int z): x(x), y(y), z(z) {}

  void move(int i) { x += dx[i], y += dy[i], z += dz[i]; }
  point moved(int i) { point t = point(x, y, z); t.move(i); return t; }

  bool operator==(point p) { return x == p.x and y == p.y and z == p.z; }
  bool operator!=(point p) { return !(*this == p); }

  void print() { printf("(%d %d %d) ", x, y, z); }
};

int p1, q1;
point s1, e1, s2, e2;
vector<int> path1, path2;

int not_interfere(int i1, int i2) {
  for(int i=0; i<3; i++) if(i != i1/2 and i != i2/2) return i*2;
  return 0;
}

void solve(point &t1, int i1, point &t2, int i2) {
  int alt = not_interfere(i1, i2);

  t1.move(alt);
  t2.move(i2); q1++;
  t1.print(); t2.print();
  printf("\n");

  t1.move(i1); p1++;
  t1.print(); t2.print();
  printf("\n");

  t1.move(alt ^ 1);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d %d", &s1.x, &s1.y, &s1.z);
  scanf("%d %d %d", &e1.x, &e1.y, &e1.z);
  scanf("%d %d %d", &s2.x, &s2.y, &s2.z);
  scanf("%d %d %d", &e2.x, &e2.y, &e2.z);

  point p = s1;
  while(p.x != e1.x) {
    if(p.x < e1.x) path1.push_back(2), p.move(2);
    else path1.push_back(3), p.move(3);
  }
  while(p.y != e1.y) {
    if(p.y < e1.y) path1.push_back(0), p.move(0);
    else path1.push_back(1), p.move(1);
  }
  while(p.z != e1.z) {
    if(p.z < e1.z) path1.push_back(4), p.move(4);
    else path1.push_back(5), p.move(5);
  }

  point q = s2;
  while(q.x != e2.x) {
    if(q.x < e2.x) path2.push_back(2), q.move(2);
    else path2.push_back(3), q.move(3);
  }
  while(q.y != e2.y) {
    if(q.y < e2.y) path2.push_back(0), q.move(0);
    else path2.push_back(1), q.move(1);
  }
  while(q.z != e2.z) {
    if(q.z < e2.z) path2.push_back(4), q.move(4);
    else path2.push_back(5), q.move(5);
  }

  p = s1; q = s2;
  while(p != e1 or q != e2) {
    p.print(); q.print();
    printf("\n");

    int i1 = p1 < (int) path1.size() ? path1[p1] : 0;
    int i2 = q1 < (int) path2.size() ? path2[q1] : 0;

    if(q1 == (int) path2.size()) {
      if(p.moved(i1) == q) {
        int alt = not_interfere(i1, i2);
        q.move(alt);
        p.move(i1); p1++;
        p.print(); q.print();
        printf("\n");
        i1 = path1[p1];
        q.move(alt ^ 1);
        p.move(i1); p1++;
      }
      else {
        p.move(i1); p1++;
      }
    }
    else if(p1 == (int) path1.size()) {
      if(q.moved(i2) == p) {
        int alt = not_interfere(i1, i2);
        p.move(alt);
        q.move(i2); q1++;
        p.print(); q.print();
        printf("\n");
        i2 = path2[q1];
        q.move(i2); q1++;
        p.move(alt ^ 1);
      }
      else {
        q.move(i2); q1++;
      }
    }
    else if(p.moved(i1) == q.moved(i2)) {
      q.move(i2); q1++;
    } else if(p.moved(i1) == q and q.moved(i2) == p) {
      solve(p, i1, q, i2);
    }
    else {
      p.move(i1); p1++;
      q.move(i2); q1++;
    }
  }
  p.print(); q.print();
  printf("\n");
  return 0;
}

