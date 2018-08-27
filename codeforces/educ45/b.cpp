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

const int N = 1e6+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, k, a[N], cnt[N];
int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &k);
  for(int i=0; i<n; i++) scanf("%d", &a[i]), cnt[a[i]]++;
  sort(a, a+n);

  int ans = 1;
  for(int i=1; i<n; i++) {
    ans++;
    if(a[i] > a[i-1] and a[i] <= a[i-1] + k) {
      ans -= cnt[a[i-1]];
    }
  }
  printf("%d\n", ans);
	return 0;
}

