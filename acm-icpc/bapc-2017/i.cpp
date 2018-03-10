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

int dp[N][N][2];
int pmax, qmax;

int best(int p, int q, int player) {
  if(dp[p][q][player] != -INF) return dp[p][q][player];
  if(p == 0 or q == 0) return dp[p][q][player] = 0;

  int t = abs(qmax-q)&1;
  int b = abs((p-1) - (qmax-q))&1;

  int gain_col = (p & 1) ? ((t == 1) ? -1 : 1) : 0;
  int gain_row = (q & 1) ? ((b == 1) ? -1 : 1) : 0;

  if(player == 0) {
    for(int i=1; i<=q; i++) {
      int gain = (i & 1) ? gain_col : 0;
      dp[p][q][player] = max(dp[p][q][player], gain - best(p, q-i, 1));
    }
  }
  else {
    for(int i=1; i<=p; i++) {
      int gain = (i & 1) ? gain_row : 0;
      dp[p][q][player] = max(dp[p][q][player], gain - best(p-i, q, 0));
    }
  }

  return dp[p][q][player];
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &pmax, &qmax);

  for(int i=0; i<=pmax; i++) {
    for(int j=0; j<=qmax; j++) dp[i][j][0] = dp[i][j][1] = -INF;
  }

  printf("%d\n", best(pmax, qmax, 0));
	return 0;
}

