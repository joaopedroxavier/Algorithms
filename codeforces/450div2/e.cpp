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

int n, m, dp[N][2], sum[N];
ii st[4*N], ans[N];
char s[N];

void build(int p, int l, int r) {
  if(l == r) { st[p] = {0, 0}; return; }

  int m = (l+r)/2;
  build(2*p, l, m);
  build(2*p+1, m+1, r);
  
  st[p] = max(st[2*p], st[2*p+1]);
}

void update(int p, int l, int r, int i, ii x) {
  if(l == r) { st[p] = x; return; }

  int m = (l+r)/2;
  if(i <= m) update(2*p, l, m, i, x);
  else update(2*p+1, m+1, r, i, x);

  st[p] = max(st[2*p], st[2*p+1]);
}

ii query(int p, int l, int r, int i, int j) {
  if(l > j or r < i) return {0, 0};
  if(l >= i and r <= j) return st[p];

  int m = (l+r)/2;
  return max(query(2*p, l, m, i, j), query(2*p+1, m+1, r, i, j));
}

int main(){
  scanf("%d", &n);
  scanf("%s", s);
  scanf("%d", &m);

  if(m == 1) {
    int qms = 0;
    for(int i=0; i<n; i++) qms += (s[i] == '?');
    printf("%d\n", qms);
    return 0;
  }

  int last[] = {0, 0};
  for(int i=n; i>0; i-=2) {
    int c = s[i-1] - 'a';
    if(c == 1 or c == 0){ dp[i][c] = last[c] + 1; dp[i][c^1] = 0; }
    else { dp[i][0] = last[0] + 1; dp[i][1] = last[1] + 1; }
    last[0] = dp[i][0]; last[1] = dp[i][1];
  }

  last[0] = 0; last[1] = 0;
  for(int i=n-1; i>0; i-=2) {
    int c = s[i-1] - 'a';
    if(c == 1 or c == 0){ dp[i][c] = last[c] + 1; dp[i][c^1] = 0; }
    else { dp[i][0] = last[0] + 1; dp[i][1] = last[1] + 1; }
    last[0] = dp[i][0]; last[1] = dp[i][1];
  }

  sum[1] = (s[0] == '?');
  for(int i=2; i<=n; i++) sum[i] = sum[i-1] + (s[i-1] == '?');

  build(1, 1, n);
  for(int i=1; i+m-1<=n; i++) {
    if(dp[i][0] >= ((m+1)/2) and dp[i+1][1] >= (m/2)) {
      if(i) {
        ii best = query(1, 1, n, 1, i-1);
        ll cost = -best.second;
        ans[i+m-1] = { best.first + 1, -(cost + sum[i+m-1] - sum[i-1]) };
      }
      else {
        ans[i+m] = { 1, - (sum[i+m-1]) };
      }
      update(1, 1, n, i+m-1, ans[i+m-1]);
    }
  }

  ii best = query(1, 1, n, 1, n);
  printf("%d\n", - best.second);

  return 0;
}

