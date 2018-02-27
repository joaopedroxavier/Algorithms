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
const int MOD=123456789;
const int INF=0x3f3f3f3f;

ll dp[N], pref[N];
int l, s;

int main() {
  scanf("%d %d", &l, &s);

  dp[0] = 1;
  pref[0] = 1;
  for(int i=1; i<l; i++) {
    dp[i] = (pref[i-1] - (max(0, i-s) == 0 ? 0 : pref[max(0,i-s) - 1]) + MOD) % MOD;
    pref[i] = (pref[i-1] + dp[i]) % MOD;
  }

  ll ans = 0;
  for(ll i=1; i<=s; i++) {
    ans = (ans + (dp[l-i]*i) % MOD) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}

