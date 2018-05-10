#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

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
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int dp[N][N];
int n, k, v;
ll a[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d %d", &n, &k, &v);

  for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
  memset(dp, -1, sizeof dp);

  dp[0][0] = 0;
  ll sum = 0;
  for(int i=1; i<=n; i++) {
    sum += a[i];
    for(int j=0; j<k; j++) {
      if(~dp[i-1][j]) {
        dp[i][j] = j;
        dp[i][(j+a[i])%k] = j; 
      }
    }
  }

  if(dp[n][v%k] == -1 or sum < v) {
    printf("NO\n");
    return 0;
  } 

  vector<int> d, nd;
  int p = v%k;
  for(int i=n; i>0; i--) {
    if(dp[i][p] != p or (dp[i][p] == p and a[i] % k == 0)) {
      d.push_back(i);
    }
    else nd.push_back(i);

    p = dp[i][p];
  }

  printf("YES\n");

  for(int i=1; i<(int)d.size(); i++) if(a[d[i]]) {
    ll qt = (a[d[i]]+k-1)/k;
    a[d[0]] += a[d[i]];
    a[d[i]] = 0;

    printf("%lld %d %d\n", qt, d[i], d[0]);
  }

  for(int i=1; i<(int)nd.size(); i++) if(a[nd[i]]) {
    ll qt = (a[nd[i]]+k-1)/k;
    a[nd[0]] += a[nd[i]];
    a[nd[i]] = 0;

    printf("%lld %d %d\n", qt, nd[i], nd[0]);
  }

  int x = d.empty() ? nd[1] : d[0], y = nd.empty() ? d[1] : nd[0];
  if(a[x] > v) {
    ll qt = (a[x]-v)/k;

    printf("%lld %d %d\n", qt, x, y);
  }
  else if(a[x] < v) {
    ll qt = (v-a[x])/k;

    printf("%lld %d %d\n", qt, y, x);
  }

  return 0;
}

