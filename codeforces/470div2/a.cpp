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

const int N = 1e3+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int dx[] = {+0, +0, -1, +1};
int dy[] = {+1, -1, +0, +0};

int n, m;
char grid[N][N];

bool check(int i, int j) {
  return i >= 0 and i < n and j >= 0 and j < m;
}

bool consume(int i, int j) {
  for(int k=0; k<4; k++) if(check(i+dx[k], j+dy[k])) {
    int x = i+dx[k];
    int y = j+dy[k];
    if(grid[x][y] == 'S') return true;
  }
  return false;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++) for(int j=0; j<m; j++) scanf(" %c", &grid[i][j]);

  bool poss = false;
  for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
    if(grid[i][j] == 'W') {
      poss = poss or consume(i,j);
    }
  }

  if(poss) return printf("No\n"), 0;

  printf("Yes\n");
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(grid[i][j] == '.') printf("D");
      else printf("%c", grid[i][j]);
    }
    printf("\n");
  }

  return 0;
}

