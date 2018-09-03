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

int st[4*N][9], lz[4*N], cpy[9], f[N];

void build(int p, int l, int r) {
  if(l == r) { st[p][1] = 1; return; }

  int m = (l+r)/2;
  build(2*p, l, m);
  build(2*p+1, m+1, r);

  for(int i=0; i<9; i++) st[p][i] = st[2*p][i] + st[2*p+1][i];
}

void push(int p, int l, int r) {
  if(lz[p]) {
    int k = lz[p];

    for(int i=0; i<9; i++) cpy[i] = st[p][i];
    for(int i=0; i<9; i++) {
      int j = (i+k)%9;
      st[p][j] = cpy[i];
    }

    if(l != r) lz[2*p] += k, lz[2*p+1] += k;
    lz[p] = 0;
  }
}

void update(int p, int l, int r, int i, int j, int k) {
  push(p, l, r);

  if(r < i or l > j) return;
  if(l >= i and r <= j) {
    lz[p] += k;
    push(p, l, r);
    return;
  }

  int m = (l+r)/2;
  update(2*p, l, m, i, j, k);
  update(2*p+1, m+1, r, i, j, k);

  for(int x=0; x<9; x++) {
    st[p][x] = st[2*p][x] + st[2*p+1][x];
  }
}

int qry[9];

void query(int p, int l, int r, int i, int j) {
  push(p, l, r);

  if(r < i or l > j) return;
  if(l >= i and r <= j) {
    for(int k=0; k<9; k++) qry[k] += st[p][k];
    return;
  }

  int m = (l+r)/2;
  query(2*p, l, m, i, j);
  query(2*p+1, m+1, r, i, j);
}

int n, q;

void print() {
  for(int i=1; i<=n; i++) {
    memset(qry, 0, sizeof qry);
    query(1, 1, n, i, i);

    int best = 0;
    for(int k=0; k<9; k++) {
      printf("%d ", qry[k]); 
      if(qry[k] >= qry[best]) best = k;
    }
    printf("\n");
  }
}


int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &q);
  build(1, 1, n);

  for(int i=0; i<q; i++) {
    int l, r; scanf("%d %d", &l, &r);
    l++; r++;

    memset(qry, 0, sizeof qry);
    query(1, 1, n, l, r);

    int best = 0;
    for(int k=0; k<9; k++) if(qry[k] >= qry[best]) best = k;

    update(1, 1, n, l, r, best);
  }

  for(int i=1; i<=n; i++) {
    memset(qry, 0, sizeof qry);
    query(1, 1, n, i, i);

    int best = 0;
    for(int k=0; k<9; k++) {
      if(qry[k] >= qry[best]) best = k;
    }

    printf("%d\n", best);
  }
  return 0;
}

