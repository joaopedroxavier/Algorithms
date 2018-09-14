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

ll val(ll xi, ll yi, ll n) {
  if((xi + yi) % 2 == 0) {
    ll ab = ((xi-1)/2) * n;
    ll ex;
    if(xi & 1) {
      ex = (yi+1)/2;
    }
    else {
      ex = (n+1)/2 + yi/2;
    }
    return ab+ex;
  }
  else {
    ll ab = (n*n+1)/2 + ((xi-1)/2) * n;
    ll ex;
    if(xi & 1) {
      ex = yi/2;
    }
    else {
      ex = n/2 + (yi+1)/2;
    }
    return ab+ex;
  }
}
int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ll n, q; scanf("%lld %lld", &n, &q);

  /*
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) printf("%lld ", val(i,j,n));
    printf("\n");
  }
  */

  while(q--) {
    int xi, yi; scanf("%d %d", &xi, &yi);
    printf("%lld\n", val(xi,yi,n));
  }

  return 0;
}

