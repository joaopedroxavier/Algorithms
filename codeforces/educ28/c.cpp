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
const int N=5e3+5;
const int MOD=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll n, a[N], p[N], st[4*N];
ll dp[N][N];

ll sum(int i) { 
  if(i == 0) return -INF;
  return p[n] - p[i-1] - p[i-1];
}

void build(int p, int l, int r) {
  if(r == l) { st[p] = l; return; }

  int m = (l+r)/2;
  build(2*p, l, m);
  build(2*p+1, m+1, r);

  if( sum(st[2*p]) >= sum(st[2*p+1]) ) st[p] = st[2*p];
  else st[p] = st[2*p+1];
}

int query(int p, int l, int r, int i, int j) {
  if(l > j or r < i) return 0;
  if(l >= i and r <= j) return st[p];

  int m = (l+r)/2;
  int ql = query(2*p, l, m, i, j);
  int qr = query(2*p+1, m+1, r, i, j);

  if( sum(ql) >= sum(qr) ) return ql;
  else return qr;
}

int main(){
  scanf("%lld", &n);

  for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
  for(int i=1; i<=n; i++) p[i] = p[i-1] + a[i];

  for(int i=1; i<=n+1; i++) dp[i][i] = i;
  for(int i=1; i<=n+1; i++) {
    for(int j=i+1; j<=n+1; j++) {
      if(sum(j) >= sum(dp[i][j-1])) dp[i][j] = j;
      else dp[i][j] = dp[i][j-1];
    }
  }

  //build(1, 1, n+1);

  ll delim0, delim1, delim2;
  ll m = -INF;
  for(int i=1; i<=n+1; i++) {
    for(int j=i; j<=n+1; j++) {
      ll s = ((ll)2)*p[i-1] - ((ll)2)*(p[n] - p[j-1]) + sum(dp[i][j]); //(sum(query(1, 1, n+1, i, j)));
      if(s >= m) delim0 = i, delim2 = j, delim1 = dp[i][j], m = s; // delim1 = query(1, 1, n+1, i, j), m = s;
    }
  }

  printf("%lld %lld %lld\n", delim0-1, delim1-1, delim2-1);

	return 0;
}

