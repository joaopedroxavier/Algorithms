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

ll n, p[N];

ll count(ll n, ll p) {
  ll ans = n / (p<<1);

  // Do you believe in magic?
  ll magic = n ^ (n & (p-1));
  magic |= p;
  if(n >= magic) ans++;
  // Yes, I do

  return ans;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld", &n);
  n--;

  int i=0; ll ans = 0;
  while((1ll << i) <= n) {
    ll p = (1ll << (i));
    ans += p * count(n, p);

    i++;
  }

  printf("%lld\n", ans);
	return 0;
}

