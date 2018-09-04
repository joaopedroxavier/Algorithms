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

const int N = 5e3+5;
const int MOD = 1e4+7;
const int INF = 0x3f3f3f3f;

int fact[] = {1, 1, 2, 6, 24};

int amt[N];
int memo[N][N];

int mv[12];
int cnt, ma;

int count_amt(int f) {
  if(f == 0) { ma = cnt; return amt[f] = 1; }

  int ans = 0;
  for(int i=0; i<12; i++) if((f & mv[i]) == mv[i]) {
    cnt++;
    ans = (ans + count_amt(f ^ mv[i])) % MOD;
    cnt--;
  }

  return ans;
}

int dp(int i, int f) {
  if(~memo[i][f]) return memo[i][f];
  if(i == 1) return memo[i][f] = amt[f];
  if(i == 0) return 1;

  memo[i][f] = 0;
  for(int msk = 0; msk < (1 << 9); msk++) if((f & msk) == msk) {
    int full = (1 << 9) - 1;
    if(amt[f ^ msk]) memo[i][f] = (memo[i][f] + (amt[f ^ msk] * dp(i-1, full ^ msk)) % MOD) % MOD;
  }

  return memo[i][f];
}

int t, n;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &t);

  mv[0] = (1 << 0) + (1 << 1);
  mv[1] = (1 << 1) + (1 << 2);

  mv[2] = (1 << 3) + (1 << 4);
  mv[3] = (1 << 4) + (1 << 5);

  mv[4] = (1 << 6) + (1 << 7);
  mv[5] = (1 << 7) + (1 << 8);

  mv[6] = (1 << 0) + (1 << 3);
  mv[7] = (1 << 3) + (1 << 6);

  mv[8] = (1 << 1) + (1 << 4);
  mv[9] = (1 << 4) + (1 << 7);

  mv[10] = (1 << 2) + (1 << 5);
  mv[11] = (1 << 5) + (1 << 8);

  memset(memo, -1, sizeof memo);

  for(int i=0; i < (1<<9); i++) {
    ma = 0; cnt = 0;
    amt[i] = count_amt(i) / fact[ma];
  }

  while(t--) {
    scanf("%d", &n);
    printf("%d\n", dp(n, (1<<9) - 1));
  }

  return 0;
}

