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

const int N = 1e4+5;
const int M = 1e2+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int w, s, x, y, h[N][M], ma[M];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &w, &s);
  scanf("%d %d", &x, &y);

  for(int i=0; i<w; i++) for(int j=0; j<x; j++) scanf("%d", &h[i][j]);

  for(int i=0; i<s; i++) for(int j=0; j<x; j++) {
    int u; scanf("%d", &u);
    ma[j] = max(ma[j], u);
  }

  for(int i=0; i<w; i++) for(int j=0; j<x; j++) h[i][j] = min(h[i][j], y-ma[j]);

  for(int i=0; i<w; i++) {
    for(int j=0; j<x; j++) printf("%d ", h[i][j]);
    printf("\n");
  }
	return 0;
}

