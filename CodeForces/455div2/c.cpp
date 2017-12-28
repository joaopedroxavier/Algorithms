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
const int N=5e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll n, dp[N][N], ps[N];
char com[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for(int i=1; i<=n; i++) {
    cin >> com[i];
  }

  dp[1][1] = 1;
  for(int i=1; i<=n; i++) ps[i] = 1;
  for(int i=2; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if(com[i-1] == 'f') {
        dp[i][j] = dp[i-1][j-1];
      }
      else {
        dp[i][j] = (dp[i][j] + ps[n] - ps[j-1] + MOD) % MOD;
      }
    }
    for(int j=1; j<=n; j++) ps[j] = dp[i][j];
    for(int j=1; j<=n; j++) ps[j] = (ps[j] + ps[j-1]) % MOD;
  }

  printf("%lld\n", ps[n]);

	return 0;
}

