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

int n, k;
ll dp[N];

ll slv(int m){
  if(m <= 1) return 0;
  if(dp[m] != -1) return dp[m];
  dp[m] = INF;
  for(int i=max(1, k-(n-m));i<=min(k, m);i++){
    ll ans = max(slv(i), slv(m-i)+1);
    dp[m] = min(dp[m], ans);
  }
  return dp[m];
}

int main(){
  scanf("%d %d", &n, &k);
  for(int i=0;i<=n;i++) dp[i] = -1;
  printf("%lld\n", (slv(n) == INF) ? -1 : slv(n));
	return 0;
}
