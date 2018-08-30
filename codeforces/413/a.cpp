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

int n, t, k, d;

int time1() { return t * ((n+k-1)/k); }
int time2() { 
  int prod = (d / t) * k;
  int numb = n - prod;
  return d + t * (numb+2*k-1)/(2*k);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d %d %d", &n, &t, &k, &d);

  int t1 = INF;
  int amt = n;
  for(int i=1; i<N; i++) {
    if(i % t == 0) {
      amt = max(0, amt - k);
    }
    if(amt == 0) {
      t1 = min(t1, i);
      break;
    }
  }

  amt = n;
  int t2 = INF;
  for(int i=1; i<N; i++) {
    if(i % t == 0) {
      amt = max(0, amt - k);
    }
    if(i > d and (i - d) % t == 0) {
      amt = max(0, amt - k);
    }
    if(amt == 0) {
      t2 = min(t2, i);
      break;
    }
  }

  printf("%s\n", t2 < t1 ? "YES" : "NO");


	return 0;
}

