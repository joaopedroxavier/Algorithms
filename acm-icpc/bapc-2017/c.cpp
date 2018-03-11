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

const int N = 5e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

ll n, a[N];
set<ll> d;
int adj[N];

unordered_set<ll> ans;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld", &n);
  for(int i=0; i<n; i++) scanf("%lld", &a[i]);

  d.insert(a[0]); ans.insert(a[0]);
  for(int i=1; i<n; i++) {
    set<ll> dd;
    dd.insert(a[i]); ans.insert(a[i]);
    for(ll j : d) {
      ll g = gcd(a[i], j);
      dd.insert(g); ans.insert(g);
    }
    d = dd;
  }

  printf("%lld\n", (ll) ans.size());
	return 0;
}

