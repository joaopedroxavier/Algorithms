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

int n, m, grid[N][N], cpy[N][N];

bool test(int col1, int col2) {
  for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cpy[i][j] = grid[i][j];

  for(int i=1; i<=n; i++) {
    swap(cpy[i][col1], cpy[i][col2]);
    vector<int> off;
    for(int j=1; j<=m; j++) if(cpy[i][j] != j) off.push_back(j);
    if(off.size() != 0 and off.size() != 2) return false;
  }
  return true;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) scanf("%d", &grid[i][j]);
  bool fd = false;
  for(int i=1; i<=m; i++) for(int j=1; j<=m; j++) fd = fd or test(i, j);
  printf("%s\n", fd ? "YES" : "NO");

  return 0;
}

