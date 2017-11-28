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

int n, dist[3][3];
int dp[N][3];

int main(){
  scanf("%d %d %d %d", &n, &dist[0][1], &dist[2][0], &dist[1][2]);
  dist[1][0] = dist[0][1], dist[2][1] = dist[1][2], dist[0][2] = dist[2][0];

  dp[0][0] = 0, dp[0][1] = dp[0][2] = INF;
  for(int i=1; i<n; i++){
    for(int j=0; j<3; j++) {
      dp[i][j] = INF;
      for(int k=0; k<3; k++) {
        if(j == k) continue;
        dp[i][j] = min(dp[i-1][k] + dist[k][j], dp[i][j]);
      }
    }
  }

  printf("%d\n", min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}));

	return 0;
}

