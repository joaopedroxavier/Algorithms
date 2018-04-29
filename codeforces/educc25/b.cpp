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

const int N = 1e1+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

char grid[N][N];
int n = 10;

bool test() {
  for(int i=0; i<n; i++) {
    for(int j=0; j<=n-5; j++) {
      int cnt=0;
      for(int k=j; k<j+5; k++) {
        cnt += (grid[i][k] == 'X');
      }
      if(cnt == 5) return true;
    }
  }

  for(int j=0; j<n; j++) {
    for(int i=0; i<=n-5; i++) {
      int cnt=0;
      for(int k=i; k<i+5; k++) {
        cnt += (grid[k][j] == 'X');
      }
      if(cnt == 5) return true;
    }
  }

  for(int i=0; i<=n-5; i++) {
    for(int j=0; j<=n-5; j++) {
      int cnt=0;
      for(int k=0; k<5; k++) {
        cnt += (grid[i+k][j+k] == 'X');
      }
      if(cnt == 5) return true;
    }
  }

  for(int i=0; i<=n-5; i++) {
    for(int j=4; j<n; j++) {
      int cnt=0;
      for(int k=0; k<5; k++) {
        cnt += (grid[i+k][j-k] == 'X');
      }
      if(cnt == 5) return true;
    }
  }

  return false;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      scanf(" %c", &grid[i][j]);
    }
  }

  bool ans = false;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(grid[i][j] == '.') {
        grid[i][j] = 'X';
        ans = ans or test();
        grid[i][j] = '.';
      }
    }
  }

  printf("%s\n", ans ? "YES" : "NO");
	return 0;
}

