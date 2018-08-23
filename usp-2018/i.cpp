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

int n, k;

void even_move() {
  printf("A B\n");
  printf("B A\n");
  k -= 2;
}

void odd_move() {
  printf("A B\n");
  printf("B C\n");
  printf("C A\n");
  k -= 3;
}

void hanoi(char a, char b, char c, int n) {
  if(n == 0) return;
  hanoi(a, c, b, n-1);
  printf("%c %c\n", a, c);
  hanoi(b, a, c, n-1);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &k);

  if(k < (1 << n) - 1) return printf("N\n"), 0;
  
  if(k & 1) {
    printf("Y\n");

    while(k > (1 << n) - 1) even_move();

    hanoi('A', 'B', 'C', n);
  }
  else {
    if(k == (1 << n)) return printf("N\n"), 0;
    printf("Y\n");

    odd_move();
    while(k > (1 << n) - 1) even_move();

    hanoi('A', 'B', 'C', n);
  }
	return 0;
}

