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
typedef pair<ll, ll> pll;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e6+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

map<pll, vector<pll>> m;
ll n, tx, ty;

ll gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

ll dp[N], l;
ll lis(vector<pll>& v) {

  int sz = v.size(); l = 0;
  dp[l] = INF;
  sort(v.begin(), v.end(), [](pll a, pll b) { return a.second < b.second; });
  for(int i=0; i<sz; i++) {
    dp[i] = INF;
    ll j = lower_bound(dp, dp+l, v[i].first) - dp;
    dp[j] = min(dp[j], v[i].first);
    l = max(l, j+1);
  }

  return l;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld", &tx, &ty);
  scanf("%lld", &n);

  for(int i=0; i<n; i++) {
    ll x, y, h;
    scanf("%lld %lld %lld", &x, &y, &h);
    x -= tx, y -= ty;
    ll g = gcd(abs(x), abs(y));
    m[mp(x/g, y/g)].push_back(mp(h, x*x + y*y));
  }

  ll ans = 0;
  for(auto p : m) {
    ans += lis(p.second);
  }

  printf("%lld\n", ans);

	return 0;
}

