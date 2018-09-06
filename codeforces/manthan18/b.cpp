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

const int N = 2e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, s;
ll a[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &s);
  for(int i=0; i<n; i++) scanf("%lld", &a[i]);
  sort(a, a+n);

  int pos = n/2;
  ll cost = 0;

  if(a[pos] > s) {
    for(int i=0; i<n; i++) {
      if(i < pos and a[i] > s) {
        cost += abs(a[i] - s);
      }
    }
  }
  else {
    for(int i=0; i<n; i++) {
      if(i > pos and a[i] < s) {
        cost += abs(a[i] - s);
      }
    }
  }

  cost += abs(a[pos] - s);

  printf("%lld\n", cost);

  return 0;
}

