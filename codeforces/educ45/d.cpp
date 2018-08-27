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

const int N = 1e3+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, a, b;
int adj[N][N];

void connect(int u, int v){
  adj[u][v] = adj[v][u] = 1;
}
void disconnect(int u, int v) {
  adj[u][v] = adj[v][u] = 0;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d %d", &n, &a, &b);

  if(a != 1 and b != 1) return printf("NO\n"), 0;

  if(a != 1) {
    for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++) connect(i, j);
    for(int i=1; i<=a-1; i++) {
      for(int j=1; j<=n; j++) disconnect(i, j);
    }
  }
  else if(b != 1) {
    for(int i=1; i<=b-1; i++) {
      for(int j=1; j<=n; j++) if(i != j) connect(i, j);
    }
  }
  else {
    if(n <= 3 and n >= 2) return printf("NO\n"), 0;
    else {
      for(int i=1; i<=n; i++) {
        if(i == n and n >= 5) connect(i, 1);
        else connect(i, i+1);
      }
    }
  }

  for(int i=1; i<=n; i++) disconnect(i, i);

  printf("YES\n");
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) printf("%d", adj[i][j]);
    printf("\n");
  }

	return 0;
}

