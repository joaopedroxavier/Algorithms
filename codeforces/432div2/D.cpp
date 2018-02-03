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
const int N=5e5+5;
const int M=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll n, x, y, v[N], sieve[M];
ll ans = INF;
vector<ll> primes;

int main(){
  scanf("%lld %lld %lld", &n, &x, &y);
  for(int i=0;i<n;i++) scanf("%lld", &v[i]);
  for(ll i=2;i*i<=M;i++) if(!sieve[i]){
    for(ll j=2*i;j<M;j+=i){
      sieve[j] = 1;
    }
  }
  for(ll i=2;i<100;i++) if(!sieve[i]) primes.pb(i);
  for(int p : primes){
    ll sum = 0;
    //printf("primo %d: \n", p);
    for(int i=0;i<n;i++){
      if(!(v[i] % p)) continue;
      //printf("%lld : Eu teria que somar %lld para tornar multiplo\n", v[i], (((v[i]/p)+1)*p - v[i]));
      sum += min(x, ((v[i]/p + 1) * p - v[i]) * y);
    }
    //printf("%lld\n", sum);
    ans = min(ans, sum);
  }
  printf("%lld\n", ans);


	return 0;
}

