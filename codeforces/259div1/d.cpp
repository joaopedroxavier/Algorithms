#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define add(x,y) (x+y >= p ? x+y-p : x+y)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=2e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll e[N], b[N], f[N];
ll m, t, p;

ll fmul(ll a, ll b, ll mod) {
  return a*b - (ll)(((long double)a * b + 0.5) / mod) * mod;
}

void fwht(ll* a, int n, bool inv) {
  for(int l=1; 2*l <= n; l<<=1) {
    for(int i=0; i < n; i+=2*l) {
      for(int j=0; j<l; j++) {
        ll u = a[i+j], v = a[i+l+j];

        a[i+j] = add(u, v); 
        a[i+l+j] = add(u, p-v);
      }
    }
  }

  if(inv) {
    for(int i=0; i<n; i++) {
      a[i] = a[i] / n;
    }
  }
}

ll fexp(ll v, ll e) {
  ll ans = 1;

  while(e) {
    if(e&1) ans = fmul(ans, v, p);
    v = fmul(v, v, p);
    e /= 2;
  }

  return ans;
}

int main(){
  scanf("%lld %lld %lld", &m, &t, &p);
  int n = 1<<m;
  p *= n;

  for(int i=0; i < n; i++) {
    scanf("%lld", &e[i]);
    e[i] %= p;
  }

  for(int i=0; i < m+1; i++) {
    scanf("%lld", &b[i]);
    b[i] %= p;
  }

  for(int i=0; i < n; i++) {
    f[i] = b[bitset<25>(i).count()];
  }

  fwht(f, n, false);
  for(int i=0; i<n; i++) {
    f[i] = fexp(f[i], t);
  }
  fwht(e, n, false);
  for(int i=0; i<n; i++) {
    e[i] = fmul(e[i], f[i], p);
  }
  fwht(e, n, true);


  for(int i=0; i<n; i++) printf("%lld\n", e[i]);

	return 0;
}

