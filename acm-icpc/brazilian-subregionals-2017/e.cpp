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

int n, v[N];
int d[] = {2, 2, 1, 2, 2, 2, 1};
string note[] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};

bool check(int st) {
  set<int> scale;

  for(int i=0; i<7; i++) {
    scale.insert(st);
    st = (st + d[i % 7]) % 12;
  }

  for(int i=0; i<n; i++) if(!scale.count(v[i])) return false;

  return true;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &v[i]);
    v[i]--;
    v[i] = v[i] % 12;
  }

  int ans = -1;
  for(int i=0; i<12; i++) if(check(i)) {
    if(ans == -1) ans = i;
  }

  printf("%s\n", (~ans) ? note[ans].c_str() : "desafinado");

	return 0;
}

