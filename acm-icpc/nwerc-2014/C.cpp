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
const int N=2e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int dp[N][25], dist[N][N], v[N];
int n, d;

int round(int n){ return (n % 10 < 5) ? n - n % 10 : n - n % 10 + 10; }

int main(){
  scanf("%d %d", &n, &d);
  for(int i=0;i<n;i++) scanf("%d", &v[i]);

  for(int i=0;i<n;i++) dist[i][i] = v[i];
  for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) dist[i][j] = dist[i][j-1] + v[j];

  for(int i=0;i<n;i++) dp[i][0] = round(dist[0][i]);
  for(int j=1;j<=d;j++){
    for(int i=0;i<n;i++){
      dp[i][j] = INF;
      for(int k=0;k<i;k++) dp[i][j] = min(dp[i][j], dp[k][j-1] + round(dist[k+1][i]));
    }
  }

  int ans = INF;
  for(int i=0;i<=d;i++) ans = min(ans, dp[n-1][i]);

  printf("%d\n", ans);
	return 0;
}

