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

int prefr[N][N], prefc[N][N], num[N][N];
int n, k;
char grid[N][N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &k);

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      scanf(" %c", &grid[i][j]);
    }
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) prefr[i][j] = prefr[i][j-1] + (grid[i][j] == '.');
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) prefc[i][j] = prefc[i][j-1] + (grid[j][i] == '.');
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j+k-1<=n; j++) if(prefr[i][j+k-1] - prefr[i][j-1] == k) {
      for(int x=j; x<=j+k-1; x++) num[i][x]++;
    }
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j+k-1<=n; j++) if(prefc[i][j+k-1] - prefc[i][j-1] == k) {
      for(int x=j; x<=j+k-1; x++) num[x][i]++;
    }
  }

  int x=1, y=1;
  for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) {
    if(num[i][j] > num[x][y]) {
      x = i, y = j;
    }
  }

  printf("%d %d\n", x, y);
  return 0;
}

