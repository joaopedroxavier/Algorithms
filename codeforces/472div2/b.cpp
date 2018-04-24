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

const int N = 55;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

bitset<50> grid[N];
char inp[N][N];
int n, m;

bool iszero(bitset<50> bs) {
  for(int i=0; i<50; i++) if(bs[i]) return false;
  return true;
}

bool check(int i, int j) {
  bitset<50> op = grid[i] & grid[j];
  if(iszero(op)) return true;
  else {
    op = grid[i] ^ grid[j];
    if(iszero(op)) return true;
  }
  return false;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      scanf(" %c", &inp[i][j]);
      grid[i][j] = inp[i][j] == '#';
    }
  }

  bool ans = true;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      ans = ans and check(i,j);
    }
  }

  printf("%s\n", ans ? "Yes" : "No");
	return 0;
}

