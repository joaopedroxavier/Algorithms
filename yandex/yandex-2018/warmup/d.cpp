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

ll n;

ll phi(ll n) {
  ll ans = n;
  for(ll i=2; i*i<=n; i++) if(n%i == 0) {
    ans -= ans/i;
    while(n % i == 0) n /= i;
  }
  if(n > 1) ans -= ans/n;
  return ans;
}

int main(){
  scanf("%lld", &n);
  printf("%lld\n", n == 1 ? 2 : phi(n));

	return 0;
}

