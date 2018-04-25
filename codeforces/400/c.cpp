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

ll pref[N], v[N];
ll n, k;

ll find(ll p) {
  map<ll, ll> freq;
  ll ans = 0;
  freq[0]++;
  for(int i=0; i<n; i++) {
    if(freq.count(pref[i] - p)) {
      ans += freq[pref[i]-p];
    }
    freq[pref[i]]++;
  }
  return ans;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld", &n, &k);
  for(int i=0; i<n; i++) {
    scanf("%lld", &v[i]);
  }

  pref[0] = v[0];
  for(int i=1; i<n; i++) {
    pref[i] = pref[i-1] + v[i];
  }

  ll p = 1ll;
  ll ma = 100000000000000ll;
  ll ans = 0;
  if(k < 0) {
    if(abs(k) == 1) {
      ans += find(1);
      ans += find(-1);
    }
    else {
      while(abs(p) <= ma) {
        ans += find(p);
        p *= k;
      }
    }
  }
  else {
    while(p <= ma) {
      ans += find(p);
      p *= k;
      if(k == 1) break;
    }
  }

  printf("%lld\n", ans);
  return 0;
}
