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

int n, p[N];
vector<int> r[N];
ll v[N], t[N], pref[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%lld", &v[i]);
  for(int i=0; i<n; i++) scanf("%lld", &t[i]);

  pref[0] = t[0];
  for(int i=1; i<n; i++) pref[i] = pref[i-1] + t[i];

  for(int i=0; i<n; i++) {
    ll old = i == 0 ? 0 : pref[i-1];
    p[i] = lower_bound(pref, pref+n, v[i] + old) - pref;
    r[p[i]].push_back(i);
  }

  /*
  for(int i=0; i<n; i++) {
    printf("%d: ", i);
    for(int j : r[i]) printf("%d ", j);
    printf("\n");
  }
  */

  ll num = 0;
  for(int i=0; i<n; i++) {
    num++; ll ans = 0;
    for(int j : r[i]) {
      num--;
      ans += v[j] - (i == 0 ? 0 : pref[i-1]) + (j == 0 ? 0 : pref[j-1]);
    }
    ans += num * t[i];
    printf("%lld ", ans);
  }
  printf("\n");


	return 0;
}

