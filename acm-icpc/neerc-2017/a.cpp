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
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, memo[N];
int cost[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int dp(int n) {
  if(n < 0) return -INF;
  if(~memo[n]) return memo[n];

  int ans = -INF;
  for(int i=0; i<10; i++) {
    ans = max(ans, dp(n - cost[i]) + i);
  }

  memo[n] = ans;
  return memo[n];
}

int main(){
  freopen("auxiliary.in", "r", stdin);
  freopen("auxiliary.out", "w", stdout);

  scanf("%d", &n);
  memset(memo, -1, sizeof memo);
  memo[0] = 0;

  printf("%d\n", dp(n));
	return 0;
}

