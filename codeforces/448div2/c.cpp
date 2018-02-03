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

ll n, p[N], pos[N], sieve[N];
int v[N];
vi primes;

int count(vector<int> v) {
  int ans = 0;
  for(int i : v){ ans <<= 1; ans += i; }
  return ans;
}

int main(){

  for(int i=2; i<=70; i++) if(!sieve[i]){
    primes.pb(i);
    pos[i] = primes.size() - 1;
    for(int j=2*i; j<N; j+=i) sieve[j] = i;
  }

  scanf("%lld", &n);

  p[0] = 1;
  for(int i=1; i<=n; i++) p[i] = (p[i-1] * 2) % MOD;
  for(int i=0; i<n; i++) {
    int u;
    scanf("%d", &u);
    while(u > 1 and sieve[u]) v[i] ^= (1 << pos[sieve[u]]), u /= sieve[u];
    if(u > 1) v[i] ^= (1 << pos[u]);
  }

  int pt=0;
  for(int j=0; j<20; j++) {
    for(int i=pt; i<n; i++) if(v[i] & (1 << j)){
      swap(v[i], v[pt]);
      for(int k=pt+1; k<n; k++) if(v[k] & (1 << j)) v[k] ^= v[pt];
      pt++;
      break;
    }
  }

  int b = 0;
  for(int i=0; i<n; i++) if(v[i]) b++;

  printf("%lld\n", p[n-b] - 1);

	return 0;
}

