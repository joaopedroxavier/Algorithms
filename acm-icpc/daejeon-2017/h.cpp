#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;
const int mod = 20*(1<<23)+1;
const int root = 3;

ll w[N];
ll ry[N], py[N], sy[N];
ll rm[N], pm[N], sm[N];
string you, me;
int nyou, nme;

ll fexp(ll b, ll e, ll mod) {
  ll ans = 1;
  while(e) {
    if(e & 1) ans = ans * b % mod;
    b = b * b % mod;
    e >>= 1;
  }
  return ans;
}

void ntt(ll *a, int n, bool inv) {
  for(int i=0, j=0; i<n; i++) {
    if(i > j) swap(a[i], a[j]);
    for(int l=n/2; (j^=l) < l; l>>=1);
  }

  ll k, t, nrev;
  w[0] = 1;
  k = fexp(root, (mod-1) / n, mod);
  for(int i=1; i<=n; i++) w[i] = w[i-1] * k % mod;
  for(int i=2; i<=n; i<<=1) for(int j=0; j<n; j+=i) for (int l=0; l<(i/2); l++) {
    int x = j+l, y = j+l+(i/2), z = (n/i)*l;
    t = a[y] * w[inv ? n-z : z] % mod;
    a[y] = (a[x] - t + mod) % mod;
    a[x] = (a[j+l] + t) % mod;
  }

  nrev = fexp(n, mod-2, mod);
  if(inv) for(int i=0; i<n; ++i) a[i] = a[i] * nrev % mod;
}

void multiply(ll *a, ll *b, int n) {
  n = 2*n;
  while(n&(n-1)) n++;
  ntt(a, n, 0);
  ntt(b, n, 0);
  for(int i=0; i<n; i++) a[i] = a[i] * b[i] % mod;
  ntt(a, n, 1);
}

int main() {
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> nyou >> nme;
  cin >> you >> me;

  for(int i=0; i<nyou; i++) {
    if(you[i] == 'R') ry[i] = 1;
    if(you[i] == 'P') py[i] = 1;
    if(you[i] == 'S') sy[i] = 1;
  }

  reverse(me.begin(), me.end());

  for(int i=0; i<nme; i++) {
    if(me[i] == 'R') sm[i] = 1;
    if(me[i] == 'P') rm[i] = 1;
    if(me[i] == 'S') pm[i] = 1;
  }

  nme;

  multiply(ry, rm, nyou);
  multiply(sy, sm, nyou);
  multiply(py, pm, nyou);

  ll ans = 0;
  for(int i=nme-1; i<nyou+nme; i++) ans = max(ans, ry[i] + sy[i] + py[i]);
  printf("%lld\n", ans);

  return 0;
}
