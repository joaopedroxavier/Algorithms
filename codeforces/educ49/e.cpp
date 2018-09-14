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

const int N = 505; // BUT I CRUMBLE COMPLETELY WHEN YOU CRY
                   // IT SEEMS LIKE ONCE AGAIN YOU'VE HAD TO GREET ME WITH GOODBYES
                   // I'M ALWAYS JUST ABOUT TO GO AND SPOIL A SURPRISE
                   // TAKE MY HANDS OFF OF YOUR EYES TOO SOON...
                   //
                   // XD
                   
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

ll poss[N][N][2], ans[N][N];

ll configrow(int n, int k, int p) {
  if(n < 0) return 0;
  if(~poss[n][k][p]) return poss[n][k][p];
  if(!p and n < k) return poss[n][k][p] = 0;
  if(n == 0) return 1;

  poss[n][k][p] = 0;

  if(p) {
    for(int i=1; i<=k; i++) poss[n][k][p] = (poss[n][k][p] + configrow(n-i, k, p)) % MOD;
  } else {
    for(int i=1; i<k; i++) poss[n][k][p] = (poss[n][k][p] + configrow(n-i, k, p)) % MOD;
    poss[n][k][p] = (poss[n][k][p] + configrow(n-k, k, 1)) % MOD;
  }

  return poss[n][k][p];
}

int n; ll val;

ll solve(int n, int k) {
  if(~ans[n][k]) return ans[n][k];
  if(n == 0) return ans[n][k] = configrow(::n, k, 0);

  ans[n][k] = 0;
  for(int i=n, amt=k; i>0 and amt < val; i--, amt+=k) {
    ans[n][k] = (ans[n][k] + solve(i-1, k)) % MOD;
  }

  return ans[n][k];
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %lld", &n, &val);

  memset(poss, -1, sizeof poss);
  memset(ans, -1, sizeof ans);

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) configrow(i, j, 0);
  }

  ll sum = 0;
  for(int i=1; i<=n; i++) {
    sum = (sum + solve(n, i)) % MOD;
  }

  printf("%lld\n", (2*sum) % MOD);

  return 0;
}

