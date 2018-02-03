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
const int N=5e6+5;
const int MOD=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll f[N], d[N];
ll t, l, r, sum;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> t >> l >> r;
  memset(f, 63, sizeof(f));
  for(int i=0;i<N;++i) d[i] = i;
  for(ll i=2;i*i<N;++i){
    if(f[i] == INF){
      f[i] = i*(i-1)/2;
      for(ll j = i*i;j<N;j+=i){
        d[j] = min(d[j], i);
      }
    }  
  }

  f[1] = 0;
  for(int i=2;i<N;++i) f[i] = f[i/d[i]] + i*(d[i]-1)/2 % MOD;
  
  ll p=1;
  for(ll i=0;i<=r-l;++i){
    sum = (sum + (p*f[l+i] % MOD)) % MOD;
    p = p*t % MOD;
  }
  cout << sum << endl;

	return 0;
}

