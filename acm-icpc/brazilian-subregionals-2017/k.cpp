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
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

ll A, B, K;
ll n;

ll mod[] = {1, 10, 100, 1000, 10000};

struct T {
  ll x, y;

  T(): x(0), y(0) {}
  T(ll x, ll y): x(x), y(y) {}

  T operator*(T t) const { 
    ll termx = x * t.x + B * y * t.y;
    ll termy = x * t.y + y * t.x;
    termx = termx % mod[K];
    termy = termy % mod[K];
    return T(termx, termy);
  }
};

T fexp(T b, ll e) {
  T ans = T(1, 0);
  while(e) {
    if(e & 1) ans = ans * b;
    b = b * b;
    e >>= 1;
  }
  return ans;
}

int kth(int x) {
  return (x % mod[K]) / mod[K-1];
}

int is_sqr(ll x) {
  for(ll i=1; i*i<=x; i++) if(i*i == x) return i;
  return 0;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld %lld %lld", &A, &B, &n, &K);

  if(is_sqr(B)) {
    T ans = fexp(T(2*A, 0), n);
    printf("%d\n", kth(ans.x));
    return 0;
  }

  T ans = fexp(T(A, 1), n);

  if(A > sqrt(B)) {
    printf("%d\n", kth(2*ans.x + mod[K] - 1));
  }
  else {
    printf("%d\n", n & 1 ? kth(2*ans.x) : kth(2*ans.x + mod[K] - 1));
  }
  return 0;
}

