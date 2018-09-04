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

int red, cur, oth;
set<int> nonred;

int maximum() {
  int rep = 8 * red;
  int str = 0;
  for(int i : nonred) str += i;
  return str + rep;
}

bool decided() { return cur - oth > maximum(); }

int t, n;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &t);

  while(t--) {
    red = 15; cur = 0; oth = 0;
    for(int i=2; i<=7; i++) nonred.insert(i);

    scanf("%d", &n);

    bool dec = false;
    for(int i=1; i<=n; i++) {
      int u; scanf("%d", &u);

      if(dec) continue;
     
      if(!u) swap(cur, oth);

      cur += u;
      if(u != 0 and u != 1 and red == 0) {
        nonred.erase(u);
      }
      if(u == 1) red--;

      if(nonred.empty() and cur == oth) {
        printf("%d\n", n);
        dec = true;
      }

      if(decided()) {
        printf("%d\n", i);
        dec = true;
      }
    }
  }

  return 0;
}

