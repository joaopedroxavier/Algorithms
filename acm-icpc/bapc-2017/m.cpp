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

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, cnt;
int xh, yh, xw, yw;
vector<int> x, y, ord;
int dp[N], v[N], lis;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  
  scanf("%d", &n);
  scanf("%d %d %d %d", &xh, &yh, &xw, &yw);
  if(xh > xw){ swap(xh, xw); swap(yh, yw); }

  for(int i=0; i<n; i++) {
    int xx, yy;
    scanf("%d %d", &xx, &yy);
    if(min(xh, xw) <= xx and xx <= max(xh, xw) and min(yh, yw) <= yy and yy <= max(yh, yw)) {
      x.pb(xx), y.pb(yy);
      ord.pb(cnt++);
    }
  }

  if(yh <= yw) {
    sort(ord.begin(), ord.end(), [](int i, int j) { return x[i] == x[j] ? y[i] < y[j] : x[i] < x[j]; });
    memset(dp, 63, sizeof dp);
    for(int i : ord) {
      int j = upper_bound(dp, dp+lis, y[i]) - dp;
      dp[j] = min(dp[j], y[i]);
      lis = max(lis, j+1);
    }
  }
  else {
    sort(ord.begin(), ord.end(), [](int i, int j) { return x[i] == x[j] ? y[i] > y[j] : x[i] < x[j]; });
    memset(dp, 63, sizeof dp);
    for(int i : ord) {
      int j = upper_bound(dp, dp+lis, (yh - y[i])) - dp;
      dp[j] = min(dp[j], yh - y[i]);
      lis = max(lis, j+1);
    }
  }

  printf("%d\n", lis);

	return 0;
}

