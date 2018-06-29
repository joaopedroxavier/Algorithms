//
// Elohim Essaim, Elohim Essaim, I implore you...
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
typedef pair<int, ii> iii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int grid[4][N];
vector<iii> updates;

bool perform(int i, int j, int goi, int goj) {
  if(grid[goi][goj] == 0 and grid[i][j] != 0) {
    grid[goi][goj] = grid[i][j];
    updates.push_back({grid[i][j], {goi,goj}});
    grid[i][j] = 0;
    return true;
  }
  return false;
}

void update(int n) {
  for(int j=n-1; j>0; j--) if(perform(2,j-1,2,j)) return;
  if(perform(1,0,2,0)) return;

  for(int j=0; j<n-1; j++) if(perform(1,j+1,1,j)) return;
  if(perform(2,n-1,1,n-1)) return;
}

void check(int n) {
  for(int j=0; j<n; j++) if(grid[1][j] and grid[1][j] == grid[0][j]) {
    updates.push_back({grid[1][j], {0,j}});
    grid[1][j] = 0;
  }

  for(int j=0; j<n; j++) if(grid[2][j] and grid[2][j] == grid[3][j]) {
    updates.push_back({grid[2][j], {3,j}});
    grid[2][j] = 0;
  }
}

bool finished(int n) {
  for(int j=0; j<n; j++) if(grid[1][j]) return false;
  for(int j=0; j<n; j++) if(grid[2][j]) return false;
  return true;
}

bool impossible(int n, int k) {
  if(k < 2*n) return false;
  for(int i=0; i<n; i++) if(grid[1][i] == grid[0][i]) return false;
  for(int i=0; i<n; i++) if(grid[2][i] == grid[3][i]) return false;
  return true;
}

int n, k;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &k);
  for(int i=0; i<4; i++) for(int j=0; j<n; j++) scanf("%d", &grid[i][j]);

  if(impossible(n,k)) return printf("-1\n"), 0;

  while(!finished(n)) {
    check(n);
    update(n);
    /*
    for(int i=0; i<4; i++) {
      for(int j=0; j<n; j++) {
        printf("%d ", grid[i][j]);
      }
      printf("\n");
    }
    printf("\n");
    }
    */
  }

  printf("%d\n", (int) updates.size());
  for(iii mv : updates) {
    printf("%d %d %d\n", mv.st, mv.nd.st+1, mv.nd.nd+1);
  }

  return 0;
}

