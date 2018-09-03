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

const int N = 1e7+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

bitset<30> tr;
int n, t, aint, x, y;
ll first[N];

inline ll add(ll a, ll b) { return a + b > x ? a + b - x : a + b; }

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  
  scanf("%d %d %d %d %d", &n, &t, &aint, &x, &y);

  for(int i=0; i<t; i++) {
    int u; scanf("%d", &u);
    tr[u] = 1;
  }

  bitset<30> a(aint);
  bitset<30> p(aint);

  ll sum = 0;
  ll cycle = 1;

  first[0] = 1;
  do {
    sum = (sum + p.to_ullong()) % x;
    cycle++;

    if(!first[sum]) first[sum] = cycle;
    if(first[sum] and (cycle - first[sum]) >= y) {
      return printf("%lld %lld\n", first[sum]-1, cycle-2), 0;
    }

    bool k = (p & tr).count() & 1;
    p >>= 1;
    p[n-1] = k;
  } while(1);

  return 0;
}

