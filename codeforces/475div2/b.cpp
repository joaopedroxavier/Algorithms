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

const int N = 1e3+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

ll n, a, b, c, t;
ll v[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &c, &t);
  
  ll ans = 0;
  for(int i=0; i<n; i++) {
    ll u; scanf("%lld", &u);
    if(b >= c) {
      ans += a;
    } else {
      ans += a + (c - b) * (t - u);
    }
  }

  printf("%lld\n", ans);
	return 0;
}

