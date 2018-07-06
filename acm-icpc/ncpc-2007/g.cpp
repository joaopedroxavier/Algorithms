//
// Elohim Essaim, Elohim Essaim, I implore you...
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

int t, n, w[N], h[N];
vector<ii> doll;
ii segt[4*N];

void update(int p, int l, int r, int x, int v) {
  if(l > x or r < x) { return; }
  if(l == r) { 
    segt[p].st += v;
    segt[p].nd = x;
    return;
  }

  int m = (l+r)/2;
  update(2*p, l, m, x, v);
  update(2*p+1, m+1, r, x, v);

  segt[p].st = segt[2*p].st + segt[2*p+1].st;
  segt[p].nd = segt[2*p+1].st ? segt[2*p+1].nd : segt[2*p].nd;
}

ii query(int p, int l, int r, int i, int j) {
  if(r < i or l > j) return {0, 0};
  if(l >= i and r <= j) return segt[p];

  int m = (l+r)/2;
  ii q1 = query(2*p, l, m, i, j);
  ii q2 = query(2*p+1, m+1, r, i, j);

  ii ans;
  ans.st = q1.st + q2.st;
  ans.nd = q2.st ? q2.nd : q1.nd;

  return ans;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &t);
  while(t--) {
    memset(w, 0, sizeof w);
    memset(h, 0, sizeof h);
    doll.clear();
    for(int i=0; i<4*N; i++) segt[i] = {0, 0};

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
      scanf("%d %d", &w[i], &h[i]);
      doll.push_back({w[i], h[i]});
    }

    sort(doll.begin(), doll.end(), [](ii a, ii b) { return a.st == b.st ? a.nd > b.nd : a.st < b.st; });
    
    int ans = 0;
    for(ii dol : doll) {
      int ht = dol.nd;
      update(1, 1, 100000, ht, 1);
      ii qry = query(1, 1, 100000, 1, ht-1);
      if(qry.st != 0) {
        ans++;
        update(1, 1, 100000, qry.nd, -1);
      }
    }

    printf("%d\n", n - ans);
  }

  return 0;
}

