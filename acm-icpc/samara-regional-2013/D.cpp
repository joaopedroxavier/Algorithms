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
const int N=2e5+5;
const int MOD=1e9+9;
const int INF=0x3f3f3f3f;

ll fact[N];
ll binom[N], inv[N], finv[N], pot[N];
ll ans, n;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n;
  
  inv[1] = 1, finv[1] = 1;
  pot[1] = 2, fact[1] = 1;
 
  for(int i=2;i<=n;i++){
    fact[i] = fact[i-1]*i % MOD;
    pot[i] = pot[i-1]*2 % MOD;
    inv[i] = (MOD - (MOD/i)*inv[MOD%i]%MOD)%MOD;
    finv[i] = finv[i-1]*inv[i] % MOD;
  }

  for(int i=1;i<n;i++) binom[i] = (fact[n]*finv[i] % MOD)*finv[n-i] % MOD;
  
  for(int i=1;i<n;i++) ans = (ans + binom[i]*(pot[n-i] - 1) % MOD) % MOD;

  cout << ans << endl;
	return 0;
}
