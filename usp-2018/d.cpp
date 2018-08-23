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

const int N = 1e6+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

struct point {
  int x, y;
  char c;

  point() : x(0), y(0), c('c') {}
  point(int x, int y, char c) : x(x), y(y), c(c) {}
};

bool cmph(point p, point q) {
  return p.x == q.x ? p.y < q.y : p.x < q.x;
}

bool cmpv(point p, point q) {
  return p.y == q.y ? p.x < q.x : p.y < q.y;
}

int n, bl[N], wh[N];
int ans;
point pt[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf(" %d %d %c", &pt[i].x, &pt[i].y, &pt[i].c);
  }

  // hor
  sort(pt, pt+n, cmph);
  for(int i=0; i<n; i++) {
    int j = i;
    int b = 0, w = 0;
    while(pt[i].x == pt[j].x) {
      b += (pt[i].c == 'b');
      w += (pt[i].c == 'w');
      i++;
    }
    i--;
    bl[i] = b; wh[i] = w;
  }

  ans = max(bl[n-1], wh[n-1]);
  for(int i=1; i<n; i++) bl[i] += bl[i-1], wh[i] += wh[i-1];
  for(int i=0; i<n; i++) ans = max(ans, max(bl[i] + wh[n-1] - wh[i], wh[i] + bl[n-1] - bl[i]));

  // ver
  sort(pt, pt+n, cmpv);
  memset(bl, 0, sizeof bl);
  memset(wh, 0, sizeof wh);
  for(int i=0; i<n; i++) {
    int j = i;
    int b = 0, w = 0;
    while(pt[i].y == pt[j].y) {
      b += (pt[i].c == 'b');
      w += (pt[i].c == 'w');
      i++;
    }
    i--;
    bl[i] = b; wh[i] = w;
  }

  for(int i=1; i<n; i++) bl[i] += bl[i-1], wh[i] += wh[i-1];
  for(int i=0; i<n; i++) ans = max(ans, max(bl[i] + wh[n-1] - wh[i], wh[i] + bl[n-1] - bl[i]));

  printf("%d\n", ans);
	return 0;
}

