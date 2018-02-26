#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;
const ll LINF=0x3f3f3f3f3f3f3f3f;

ll n, t;
set<ll> p2;

vector<vector<ll>> ans;

ll power(ll b, ll e) {
  ll ans = 1;
  while(e) {
    if(e&1) ans *= b;
    b = b*b;
    e >>= 1;
  }
  return ans;
}

bool check(ll n, ll i, ll x) {
  ll ans = 1;
  while(i) {
    if(i & 1) {
      if(ans > n / x) return false;
      ans *= x;
    }
    i >>= 1;
    if(i and x > n / x) return false;
    x *= x;
  }

  return ans <= n;
}

ll ith_root(ll n, ll i) {
  ll l=1, r=n;
  while(l < r) {
    ll m = (l + r + 1)/2;
    if(check(n, i, m)) l = m;
    else r = m-1;
  }
  return l;
}

int main(){
  freopen("little.in", "r", stdin);
  freopen("little.out", "w", stdout);

  scanf("%lld", &n);

  ll p = 1;
  for(int i=0; i<60; i++){ 
    p2.insert(p);
    p <<= 1; 
  }

  if(n == 1 or p2.count(n)) return printf("-1\n"), 0;

  ans.push_back({n});

  p = sqrt(n);
  ll q = p+1;
  if(p*q == n or p*p == n) {
    vector<ll> v;
    
    v.push_back(p);
    v.push_back(p*q == n ? q : p);
    ans.push_back(v);
  }

  ll i = 3;
  while(ith_root(n, i) > 1) {
    ll p = ith_root(n, i);
    ll q = p+1;
    for(ll k=0; k<=i; k++) {
      if(power(p, k) * power(q, i-k) == n) {
        vector<ll> v;
        
        for(int l=0; l<k; l++) v.push_back(p);
        for(int l=0; l<i-k; l++) v.push_back(q);
        ans.push_back(v);
      }
    }
    i++;
  }

  printf("%d\n", (int) ans.size());
  for(auto p : ans) {
    printf("%d ", (int) p.size());
    for(ll j : p) printf("%lld ", j);
    printf("\n");
  }
	return 0;
}

