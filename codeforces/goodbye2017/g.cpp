#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

string x;
ll dp[N][N][2];

ll part(int n) {
  memset(dp, 0, sizeof dp);

  int sz = (int) x.size();

  printf("%d: \n\n", n);

  dp[0][0][0] = 1;
  for(int i=0; i < sz; i++) {
    int d = x[i] - '0';
    for(int j=0; j <= i; j++) {
      for(int k=0; k<=d; k++) {
        if(k == d) {
          if(k >= n) dp[i+1][j+1][0] = (dp[i+1][j+1][0] + dp[i][j][0]) % MOD;
          else dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][0]) % MOD;
        }
        else {
          if(k >= n) dp[i+1][j+1][1] = (dp[i+1][j+1][1] + dp[i][j][0]) % MOD;
          else dp[i+1][j][1] = (dp[i+1][j][1] + dp[i][j][0]) % MOD;
        }
      }
      for(int k=d+1; k<=9; k++) {
        if(k >= n) dp[i+1][j+1][1] = (dp[i+1][j+1][1] + dp[i][j][1]) % MOD;
        else dp[i+1][j][1] = (dp[i+1][j][1] + dp[i][j][1]) % MOD;
      }
    }
  }

  for(int j=0; j<=sz; j++) printf("%lld ", dp[sz][j][0]);
  printf("\n");
  printf("\n");

  for(int j=0; j<=sz; j++) printf("%lld ", dp[sz][j][1]);
  printf("\n");
  printf("\n");

  ll ans = 0;
  for(int i = sz-1; i >= 0; i--) {
    ll tot = 0;
    for(int j = sz; j > i; j--) tot = (tot + dp[sz][j][1] + dp[sz][j][0]) % MOD;

    ll pot = 1;
    for(int j = 0; j < i; j++) pot = (pot * 10) % MOD;

    ans = (ans + (tot * pot) % MOD) % MOD;
  }

  return ans;
}

int main(){
  cin >> x;

  ll ans = 0;
  for(int i=1; i<=9; i++) ans = (ans + part(i)) % MOD;

  cout << ans << endl;

  return 0;
}

