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
const int N=1e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll n, k, dp[N][N], bin[N][N];
ll ans;

void facts(){
  for(int i=0;i<=n;++i){
    bin[i][i] = bin[i][0] = 1;
    for(int j=1;j<i;++j){
      bin[i][j] = (bin[i-1][j] + bin[i-1][j-1]) % MOD;
    }
  }
}

int solve(int l, int e){
  if(dp[l][e] != -1) return dp[l][e];
  dp[l][e] = 0;
  for(int i=1;i<k;++i){
    for(int j=l-1;j>=1;--j){
      if(e-i >= 0) dp[l][e] = (dp[l][e] + (bin[e][i]*solve(j,e-i)) % MOD) % MOD;
    }
  }
  return dp[l][e];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  facts();

  for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) dp[i][j] = -1;
  for(int i=0;i<=n;++i) dp[1][i] = ((i<k) ? 1 : 0);
  for(int i=n;i>=1;--i) ans = (ans + solve(i, n-2)) % MOD;

  cout << ((n == 1 and k == 1) ? 1 : ans) << endl;
  return 0;
}

