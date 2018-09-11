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

const int N = 505; // I'M GOING BACK TO 505
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, x, pal[N][N], vis[N][N], zis[N][N], v[N];
int bestl[N][N], bestr[N][N];

bool palindrome(int i, int j) {
  if(~pal[i][j]) return pal[i][j];
  if(i == j) return pal[i][j] = true;
  if(i == j-1) return pal[i][j] = v[i] == v[j];
  if(i > j) return pal[i][j] = false;

  vis[i][j] = x;
  pal[i][j] = v[i] == v[j] and palindrome(i+1, j-1);

  return pal[i][j];
}

int dp[N][N];

int solve(int i, int j) {
  if(~dp[i][j]) return dp[i][j];
  if(i > j) return 0;
  if(palindrome(i, j)) return dp[i][j] = 1;

  dp[i][j] = 1 + solve(i+1, j);
  dp[i][j] = min(dp[i][j], 1 + solve(i, j-1));

  for(int k=i+1; k<=j-1; k++) {
    dp[i][j] = min(dp[i][j], solve(i, k) + solve(k+1, j));
  }

  int p=i, q=j;
  while(v[p] == v[q] and p <= q) {
    dp[i][j] = min(dp[i][j], solve(p+1, q-1));
    p++, q--;
  }

  return dp[i][j];
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);

  for(int i=1; i<=n; i++) scanf("%d", &v[i]);

  memset(dp, -1, sizeof dp);
  memset(pal, -1, sizeof pal);

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) palindrome(i,j);
  }

  for(int i=1; i<=n; i++) {
    bestl[i][i] = i;
    int last = i;
    for(int j=i+1; j<=n; j++) {
      if(palindrome(i, j)) last = j;
      bestl[i][j] = last;
    }
  }

  for(int i=1; i<=n; i++) {
    bestr[i][i] = i;
    int last = i;
    for(int j=i-1; j>0; j--) {
      if(palindrome(j, i)) last = j;
      bestr[j][i] = last;
    }
  }

  printf("%d\n", solve(1, n));

  return 0;
}

