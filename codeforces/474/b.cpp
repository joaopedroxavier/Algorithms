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

int n, k1, k2;
ll a[N], b[N], c[N];

ll dist(ll i, ll j) { return (i-j) * (i-j); }

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d %d", &n, &k1, &k2);

  for(int i=0; i<n; i++) 
    scanf("%lld", &a[i]);

  for(int i=0; i<n; i++) 
    scanf("%lld", &b[i]);

  ll ans = 0;
  for(int i=0; i<n; i++) {
    c[i] = abs(a[i] - b[i]);
  }

  for(int i=0; i<k1+k2; i++) {
    int big = 0, idx = 0;
    for(int j=0; j<n; j++) {
      if(c[j] > big) {
        big = c[j];
        idx = j;
      }
    }
    if(c[idx] == 0) {
      c[idx]++;
    } else {
      c[idx]--;
    }
  }

  for(int i=0; i<n; i++) {
    ans += c[i] * c[i];
  }

  printf("%lld\n", ans);
	return 0;
}

