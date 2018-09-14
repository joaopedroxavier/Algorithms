/
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

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;


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

int d[] = {0, 1, 2, -1, -1, 5, 9, -1, 8, 6};

bool upsidedown(string &s) {
  bool ans = true;
  for(char &c : s) {
    if(~d[c-'0']) {
      c = '0' + d[c-'0'];
    }
    else return false;
  }
  reverse(s.begin(), s.end());
  return ans;
}

ll toll(string s) {
  ll ans = 0;
  for(char c : s) {
    ans = 10ll*ans + c-'0';
  }
  return ans;
}

string tostring(ll x) {
  string s;
  while(x) {
    s.push_back('0'+x%10);
    x/=10;
  }
  reverse(s.begin(), s.end());
  return s;
}

ll n;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld", &n);
  if(!isprime(n)) return printf("no\n"), 0;

  string s = tostring(n);
  if(!upsidedown(s)) return printf("no\n"), 0;
  n = toll(s);
  if(!isprime(n)) return printf("no\n"), 0;
  printf("yes\n");

  return 0;
}

