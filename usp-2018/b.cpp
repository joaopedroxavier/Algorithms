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

const int N = 2e3+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, l[N], cnt[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);

  for(int i=0; i<n; i++) scanf("%d", &l[i]);

  for(int i=2; i<=n; i++) if(n % i == 0) {
    memset(cnt, 0, sizeof cnt);
    for(int j=0; j<n; j++) cnt[l[j] % i]++;

    set<int> s;
    for(int j=0; j<i; j++) s.insert(cnt[j]);
    if(s.size() == 1) return printf("%d\n", i), 0;
  }

  printf("-1\n");

	return 0;
}

