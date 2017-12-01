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
const ll MOD= 998244353;
const int INF=0x3f3f3f3f;

ll binom[N][N];
ll fact[N];
ll a, b, c;
ll ans1, ans2, ans3;

int main(){
  scanf("%lld %lld %lld", &a, &b, &c);
  
  fact[0] = 1;
  for(int i=1; i<N; i++) fact[i] = (fact[i-1] * i) % MOD;

  binom[0][0] = 1;
  for(int i=1; i<N; i++) {
    for(int j=0; j<=i; j++) {
      if(j == 0 or j == i) binom[i][j] = 1;
      else binom[i][j] = (binom[i-1][j-1] + binom[i-1][j]) % MOD;
    }
  }

  for(int i=0; i<=min(a,b); i++) {
    ll term = (binom[a][i] * binom[b][i]) % MOD;
    term = (term * fact[i]) % MOD;
    ans1 = (ans1 + term) % MOD;
  }

  for(int i=0; i<=min(b,c); i++) {
    ll term = (binom[c][i] * binom[b][i]) % MOD;
    term = (term * fact[i]) % MOD;
    ans2 = (ans2 + term) % MOD;
  }

  for(int i=0; i<=min(a,c); i++) {
    ll term = (binom[a][i] * binom[c][i]) % MOD;
    term = (term * fact[i]) % MOD;
    ans3 = (ans3 + term) % MOD;
  }

  ll ans = (ans1 * ans2) % MOD;
  ans = (ans * ans3) % MOD;
  printf("%lld\n", ans);

	return 0;
}

