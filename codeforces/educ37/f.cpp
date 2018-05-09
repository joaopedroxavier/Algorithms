#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 3e5+5;
const int M = 1e6+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

ll d[M][10], a[N], sst[4*N], st[4*N][10], cur[4*N];
int n, m, sieve[M], lz[4*N];
vector<int> pf[M];

void build(int p, int l, int r) {
  if(l == r) { 
    for(int i=0; i<10; i++) {
      st[p][i] = d[a[l]][i];
    }
    sst[p] = st[p][0];
    return;
  }

  int m = (l+r)/2;
  build(2*p, l, m);
  build(2*p+1, m+1, r);

  for(int i=0; i<10; i++) {
    st[p][i] = st[2*p][i] + st[2*p+1][i];
  }
  sst[p] = st[p][0];
}

void push(int p, int l, int r) {
  if(lz[p]) {
    cur[p] = min(9ll, cur[p] + lz[p]);
    sst[p] = st[p][cur[p]];
    if(l != r) {
      lz[2*p] += lz[p];
      lz[2*p+1] += lz[p];
    }
    lz[p] = 0;
  }
}

ll query(int p, int l, int r, int i, int j) {
  push(p, l, r);
  if(r < i or l > j) return 0;
  if(l >= i and r <= j) {
    return sst[p];
  }

  int m = (l+r)/2;
  return query(2*p, l, m, i, j) + query(2*p+1, m+1, r, i, j);
}

void update(int p, int l, int r, int i, int j) {
  push(p, l, r);
  if(r < i or l > j) return;
  if(l >= i and r <= j) {
    lz[p]++;
    push(p, l, r);
    return;
  }

  int m = (l+r)/2;
  update(2*p, l, m, i, j);
  update(2*p+1, m+1, r, i, j);
  sst[p] = sst[2*p] + sst[2*p+1];
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++) scanf("%lld", &a[i]);

  for(int i=1; i<M; i++) {
    for(int j=i; j<M; j+=i) d[j][1]++;
  }

  d[1][1] = 1;

  for(int i=2; i<M; i++) {
    d[i][0] = i;
    for(int j=2; j<10; j++) {
      int t = d[i][0];
      d[i][j] = d[t][j-1];
    }
  }

  for(int i=0; i<10; i++) {
    d[1][i] = 1;
  }

  build(1, 1, n);
  for(int i=0; i<m; i++) {
    int t; scanf("%d", &t);
    if(t == 1) {
      int l, r; scanf("%d %d", &l, &r);
      update(1, 1, n, l, r);
    }
    else {
      int l, r; scanf("%d %d", &l, &r);
      printf("%lld\n", query(1, 1, n, l, r));
    }
  }

	return 0;
}

