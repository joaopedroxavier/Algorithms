//
// 내가 나인 게 싫은 날
// 영영 사라지고 싶은 날
// 문을 하나 만들자 너의 맘 속에다
// 그 문을 열고 들어가면
// 이 곳이 기다릴 거야
// 믿어도 괜찮아 널 위로해줄 magic shop
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e4+5;
const int M = 1e3+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

ll addmod(ll a, ll b, ll m = MOD) { return a + b >= m ? a + b - m : a + b; }

ull mulmod(ull a, ull b, ull m = MOD) {
	ull q = (ld) a * (ld) b / (ld) m;
	ull r = a * b - q * m;
	return (r + m) % m;
}

ll fexp(ll a, ll b, ll m = MOD) {
  ll r = 1;
  for(a %= m; b; b >>= 1, a=mulmod(a, a, m)) if(b & 1) r = mulmod(r, a, m);
  return r;
}

bool miller(ll n, ll k) {
  if(!(n&1)) return n == 2;
  if(k == n) return true;

  ll mod = n;
  n--;
  while(!(n&1) and n) {
    n >>= 1;
    if(fexp(k, n, mod) == 1 or fexp(k, n, mod) == mod - 1) return true;
  }
  return false;
}

bool isprime(ll n) {
  if(n == 1) return false;

  ll base[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for(int i=0; i<12; i++) {
    if(!miller(n, base[i]))  return 0;
  }
  return 1;
}

ll func(ll x, ll n, ll c) { return (mulmod(x, x, n) + c) % n; }

ull gcd(ull a, ull b) { return b ? gcd(b, a%b) : a; }

ull pollard(ull n) {
  ull x, y, d, c;
  if(n % 2 == 0) return 2;
  if(isprime(n)) return n;

  while(1) {
    y = x = 2; d = 1;
    do {
      c = rng() % n;
    } while(c == 0 or (c+2)%n == 0);
    while(1) {
      x = func(x, n, c);
      y = func(y, n, c);
      y = func(y, n, c);
      d = gcd(x >= y ? x-y : y-x, n);
      if (d > 1) {
        if(d == n) break;
        else return d;
      }
    }
  }
}

void fator(ll n, vector<ll> &v) {
  // prime factorization of n, put into a vector v.
  //
  // for each prime factor of n, it is repeated the amount of times
  // that it divides n
  //
  // ex : n == 120, v = {2, 2, 2, 3, 5};
  // 
  //
  if(isprime(n)) { v.pb(n); return; }
  vector<ull> w, t; w.pb(n); t.pb(1);

  while(!w.empty()) {
    ull bck = w.back();
    ull div = pollard(bck);

    if(div == bck) {
      int amt = 0;
      for(int i=0; i < (int) w.size(); i++) {
        int cur = 0;
        while(w[i] % div == 0) {
          w[i] /= div;
          cur++;
        }
        amt += cur * t[i];
        if(w[i] == 1) {
          swap(w[i], w.back());
          swap(t[i], t.back());
          w.pop_back();
          t.pop_back();
          i--;
        }
      }
      while(amt--) v.pb(div);
    }
    else {
      int amt = 0;
      while(w.back() % div == 0) {
        w.back() /= div;
        amt++;
      }
      amt *= t.back();
      if(w.back() == 1) {
        w.pop_back();
        t.pop_back();
      }

      w.pb(div);
      t.pb(amt);
    }
  }

  // the divisors will not be sorted, so you need to sort it afterwards
  sort(v.begin(), v.end());
}

map<ll, ll> pf;

void proc(ll x) {
  vector<ll> v;
  fator(x, v);

  for(auto p : v) {
    pf[p]++;
  }
}

ll b, n;
ll a[N], dp[N][M];
vector<pair<ll, ll>> prime;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld", &n);
  if(n == 1) return printf("1\n"), 0;
  proc(n);

  ll ans = 1;
  for(auto p : pf) ans *= (p.nd + 1);

  printf("%lld\n", ans);

  return 0;
}

