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

int rem[N];
int k, dp[N][N];
char s[N], ans[N];

int main(){


  while(scanf("%s %d", s, &k) != EOF) {
    memset(dp, -1, sizeof dp);
    int n = (int) strlen(s);

    rem[0] = 1;
    for(int i=1; i<n; i++) rem[i] = (rem[i-1] * 10) % k;

    if(n == 1) {
      if(k < 9) printf("%d\n", k);
      else printf("*\n");
      continue;
    }

    if(s[n-1] == '?') for(int p=0; p<10; p++) {
      if(dp[n-1][(p * rem[0]) % k] == -1) dp[n-1][(p * rem[0]) % k] = p;
      dp[n-1][(p * rem[0]) % k] = min(dp[n-1][(p * rem[0]) % k], p);
    }
    else dp[n-1][((s[n-1] - '0') * rem[0]) % k] = s[n-1] - '0';   

    for(int i=n-2; i>=0; i--) {
      if(s[i] != '?') {
        for(int j=0; j<k; j++) if(~dp[i+1][(j - ((s[i] - '0') * rem[n-i-1]) % k + k)%k]) {
          dp[i][j] = s[i] - '0';
        }
      }
      else {
        for(int p= (i == 0 ? 1 : 0); p<10; p++) {
          for(int j=0; j<k; j++) if(~dp[i+1][(j - (p * rem[n-i-1]) % k + k)%k]) {
            if(dp[i][j] == -1) dp[i][j] = p;
            dp[i][j] = min(dp[i][j], p);
          }
        }
      }
    }

    if(dp[0][0] == -1) printf("*\n");
    else {
      int r = 0;
      for(int i=0; i<n; i++) {
        ans[i] = dp[i][r] + '0';
        r = (r - (dp[i][r] * rem[n-i-1]) % k + k) % k;
      }
      for(int i=0; i<n; i++) printf("%c", ans[i]);
      printf("\n");
    }

  }

  return 0;
}

