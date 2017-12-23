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
const int N=5e2+5;
const int M=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m, k, q;
int x[M], y[M], t[M];
int cnt[N][N];

bool check(int tt) {
  memset(cnt, 0, sizeof(cnt));
  for(int i=1; i <= q; i++) if(t[i] <= tt){
    cnt[x[i]][y[i]]++;
  }
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      cnt[i][j] += cnt[i][j-1] + cnt[i-1][j] - cnt[i-1][j-1];
    }
  }
  for(int i=k; i<=n; i++) {
    for(int j=k; j<=m; j++) {
      int sum = cnt[i][j] - cnt[i-k][j] - cnt[i][j-k] + cnt[i-k][j-k];
      if(sum == k*k) return true;
    }
  }
  return false;
}

int main(){
  scanf("%d %d %d %d", &n, &m, &k, &q);

  for(int i=1; i<=q; i++) {
    scanf("%d %d %d", &x[i], &y[i], &t[i]);
  }

  int l = 0, r = INF, ans = -1;

  while(l <= r) {
    int md = (l+r)/2;
    if(check(md)) ans = md, r = md-1;
    else l = md+1;
  }

  printf("%d\n", ans);

	return 0;
}

