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

const int N = 1e2+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, k;
int grid[N][N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &k);

  printf("YES\n");
  int p = 1;
  int r = 1;

  while(k > 2) {
    grid[r][p] = grid[r][n-p-1] = 1;

    if(r == 2) p++, r=1;
    else r++;

    k -= 2;
  }
  if(k&1) grid[1][n/2] = 1;
  else if(k>0) grid[1][n/2] = grid[2][n/2] = 1;

  for(int i=0; i<4; i++) {
    for(int j=0; j<n; j++) {
      printf("%c", grid[i][j] ? '#' : '.');
    }
    printf("\n");
  }

  return 0;
}

