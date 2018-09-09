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

int t, k;
int l1, r1, p1, d1;
int l2, r2, p2, d2;

void saeed() {
  if(d1 == -1) {
    p1--;
    if(p1 == l1) d1 = -d1;
  }
  else if(d1 == 1) {
    p1++;
    if(p1 == r1) d1 = -d1;
  }
}

void folan() {
  if(d2 == -1) {
    p2--;
    if(p2 == l2) d2 = -d2;
  }
  else if(d2 == 1) {
    p2++;
    if(p2 == r2) d2 = -d2;
  }
}

int ans;

void step() {
  saeed();
  folan();
  if(p1 == p2) ans++;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &t);

  while(t--) {
    ans = 0;
    scanf("%d %d %d %d", &l1, &r1, &p1, &d1);
    scanf("%d %d %d %d", &l2, &r2, &p2, &d2);
    scanf("%d", &k);

    if(d1 == 0) d1 = -1;
    if(d2 == 0) d2 = -1;

    if(p1 == r1 and d1 == 1) d1 = -d1;
    if(p2 == r2 and d2 == 1) d2 = -d2;

    if(p1 == l1 and d1 == -1) d1 = -d1;
    if(p2 == l2 and d2 == -1) d2 = -d2;

    for(int i=0; i<k; i++) step();

    printf("%d\n", ans);
  }

	return 0;
}

