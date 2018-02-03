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
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, ans;
int dp[N][2];

int main(){
  scanf("%d", &n);

  int f;
  scanf("%d", &f);
  dp[0][1] = (f == 1);
  dp[0][0] = (f == 0);
  for(int i=1; i<n; i++) {
    int u;
    scanf("%d", &u);

    if(u == 1) {
      dp[i][1] = max(dp[i-1][1] + 1, dp[i-1][0] + 1);
      dp[i][0] = dp[i-1][0];
    } else {
      dp[i][1] = dp[i-1][1];
      dp[i][0] = dp[i-1][0] + 1;
    }
  }

  printf("%d\n", max(dp[n-1][0], dp[n-1][1]));

	return 0;
}

