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

ii st[4*N];
int n, q, lf[N], rt[N];

void build(int p, int l, int r) {
  if(l == r) { st[p] = {lf[l], rt[l]}; return; }
  
  int m = (l+r)/2;
  build(2*p, l, m);
  build(2*p+1, m+1, r);

  st[p].st = max(st[2*p].st, st[2*p+1].st);
  st[p].nd = min(st[2*p].nd, st[2*p+1].nd);
}

void update(int p, int l, int r, int i) {
  if(l > i or r < i) return;
  if(l == r) { st[p] = {lf[l], rt[l]}; return; }
  
  int m = (l+r)/2;
  update(2*p, l, m, i);
  update(2*p+1, m+1, r, i);

  st[p].st = max(st[2*p].st, st[2*p+1].st);
  st[p].nd = min(st[2*p].nd, st[2*p+1].nd);
}

ii query(int p, int l, int r, int i, int j) {
  if(l > j or r < i) return {-INF, INF};
  if(l >= i and r <= j) return st[p];

  int m = (l+r)/2;
  ii ql = query(2*p, l, m, i, j);
  ii qr = query(2*p+1, m+1, r, i, j);

  int f = max(ql.st, qr.st);
  int s = min(ql.nd, qr.nd);

  return {f, s};
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &q);
  for(int i=1; i<=n; i++) {
    scanf("%d %d", &lf[i], &rt[i]);
  }
  build(1, 1, n);
  for(int j=0; j<q; j++) {
    char q; int i, l, r;
    scanf(" %c", &q);

    if(q == 'C') {
      scanf("%d %d %d", &i, &l, &r);
      lf[i] = l, rt[i] = r;
      update(1, 1, n, i);
    }
    else {
      scanf("%d %d", &l, &r);
      ii q = query(1, 1, n, l, r);
      printf("%d\n", max(0, q.nd - q.st + 1));
    }
  }

	return 0;
}

