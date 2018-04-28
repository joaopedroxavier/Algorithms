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

ll w, l;
ll dp[N], pref[N];
ll v[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld", &w, &l);
  for(int i=1; i<w; i++) {
    scanf("%lld", &v[i]);
  }

  ll sum = 0;
  for(int i=1; i<=l; i++) {
    sum += v[i];
  }

  ll ans = sum;
  for(int i=l+1; i<w; i++) {
    sum += v[i] - v[i-l];
    ans = min(ans, sum);
  }

  printf("%lld\n", ans);

	return 0;
}

