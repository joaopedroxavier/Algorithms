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

ll n, m;
ll v[N], aux[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld", &n, &m);

  ll sum = 0;
  if(n == 1) {
    for(int i=0; i<m; i++) {
      ll x, d; scanf("%lld %lld", &x, &d);
      sum += x;
    }
  }
  else if(n == 2) {
    for(int i=0; i<m; i++) {
      ll x, d; scanf("%lld %lld", &x, &d);
      sum += 2*x + d;
    }
  }
  else {
    for(int i=0; i<m; i++) {
      ll x, d; scanf("%lld %lld", &x, &d);
      sum += x * n;
      ll nn = n-1;
      if(d > 0) {
        sum += d * (nn * (nn+1)) / 2;
      }
      else {
        if(n & 1) {
          ll nn = n/2;
          sum += d * (nn * (nn+1));
        }
        else {
          ll nn = n/2;
          sum += d * (nn * (nn+1))/2;
          nn--;
          sum += d * (nn * (nn+1))/2;
        }
      }
    }
  }
  ld ans = sum;
  ans = ans / n;
  printf("%.12Lf\n", ans);
  return 0;
}

