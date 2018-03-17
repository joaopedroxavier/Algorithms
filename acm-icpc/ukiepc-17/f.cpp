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

const int N = 405;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, k;
ld memo[N][N];
bool st[N][N];

ld dp(int i, int j) {
  if(st[i][j]) return memo[i][j];

  st[i][j] = true;

  if(i == 1 or j == 1) return memo[i][j] = 0.5;
  return memo[i][j] = 0.5 * (dp(i-1, j-1) + 1.0) + 0.5 * (dp(i, j-1));
}
int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &k);
  printf("%.12Lf\n", dp(n,k));
	return 0;
}

