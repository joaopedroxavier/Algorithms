#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, esq[N], dir[N], p[N], rec[N], pos[N];
int lm[N];
int st[4*N];

void build(int p, int l, int r) {
  if(l == r) { st[p] = INF; return; }

  int m = (l+r)/2;
  build(2*p, l, m);
  build(2*p+1, m+1, r);

  st[p] = min(st[2*p], st[2*p+1]);
}

void update(int p, int l, int r, int i, int x) {
  if(l == r) { st[p] = x; return; }

  int m = (l+r)/2;
  if(i <= m) update(2*p, l, m, i, x);
  else update(2*p+1, m+1, r, i, x);

  st[p] = min(st[2*p], st[2*p+1]);
}

int query(int p, int l, int r, int i, int j) {
  if(r < i or l > j) return INF;
  if(l >= i and r <= j) return st[p];

  int m = (l+r)/2;
  return min(query(2*p, l, m, i, j), query(2*p+1, m+1, r, i, j));
}

int main(){
  scanf("%d", &n);

  for(int i=1; i<=n; i++) { scanf("%d", &p[i]); pos[p[i]] = i; }

  for(int i=2; i<=n; i++) {
    if(p[i-1] > p[esq[i-1]]) {
      esq[i] = i-1;
      rec[i] = rec[i-1] + 1;
      lm[i-1] = 1;
    }
    else {
      esq[i] = esq[i-1];
      rec[i] = rec[i-1];
    }
  }

  int mx = 0, recs = 0;
  for(int i=1; i<=n; i++) {
    if(p[i] > mx) { mx = p[i]; recs++; }
  }

  build(1, 1, n);
  dir[n] = n+1;
  update(1, 1, n, p[n], n);
  for(int i=n-1; i>0; i--) {
    if(p[i] == n) dir[i] = n+1;
    else {
      int q = query(1, 1, n, p[i]+1, n);
      if(q == INF) dir[i] = n+1;
      else dir[i] = q;
    }
    update(1, 1, n, p[i], i);
  }

  int pt = pos[n];
  int ans = recs;
  int res = pos[1];
  rec[n+1] = recs;
  int cnt2 = 0;
  while(pt > 0) {
    int cnt = 0;
    if(pt != pos[n]) cnt2++;
    int m = p[esq[pt]];
    for(int i=pt+1; i<dir[pt]; i++) {
      if(p[i] > m){ cnt++; m = p[i]; }
    }
    if(cnt + rec[pt] + cnt2 >= ans) {
      res = pt;
      ans = cnt + rec[pt] + cnt2;
    }
    pt = esq[pt];
  }

  int sm = INF;
  for(int i=1; i<=n; i++) if(!lm[i]) sm = min(sm, p[i]);

  if(recs == n) printf("1\n");
  else printf("%d\n", ans <= recs ? sm : p[res]);

  return 0;
}

