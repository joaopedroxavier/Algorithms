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
const ll INF=0x3f3f3f3f3f3f3f3f;

ll n, r, p, dp[N];

ll solve(ll m){
  ll ans = INF;
  if(m == 1 or m == 0) return 0;
  if(dp[m] != -1) return dp[m];
  for(ll i=2;i*i<=m;i++){
    ll q = (m % i) ? m/i + 1 : m/i;
    ans = min(ans, solve(q) + (i-1)*p + r);
  }
  for(ll i=1;i*i<=m;i++){
    ll q = (m % i) ? m/i : m/i - 1;
    ans = min(ans, solve(i) + (q)*p + r);
  }
  return dp[m] = ans;
}

int main(){
  scanf("%lld %lld %lld", &n, &r, &p);
  memset(dp, -1, sizeof dp);
  printf("%lld\n", solve(n));
	return 0;
}

