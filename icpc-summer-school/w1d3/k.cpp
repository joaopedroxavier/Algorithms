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
const int N=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int memo[N][N], v[N];
int n, m;

int dp(int l, int r) {
  if(~memo[l][r]) return memo[l][r];
  if(r-l <= 1) return memo[l][r] = 0;

  memo[l][r] = INF;
  for(int i=l+1; i<r; i++) {
    int cost = v[i] != v[l] and v[i] != v[r];
    memo[l][r] = min(memo[l][r], dp(l, i) + dp(i, r) + cost);
  }

  return memo[l][r];
}

int main(){
  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++) scanf("%d", v + i);
  memset(memo, -1, sizeof memo);

  printf("%d\n", dp(0, n+1) - 1);

	return 0;
}

