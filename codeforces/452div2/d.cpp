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

ll largestnines(ll n) {
  ll ans = 0;
  while(ans < n){
    ans *= 10;
    ans += 9;
  }
  while(n + n - 1 < ans) ans /= 10; 
  return ans;
}

pair<ll, ll> bounds(ll n, ll a) {
  if(n < a) {
    return mp(a-n, n);
  } else {
    return mp(1, a-1);
  }
}

int main(){
  scanf("%lld", &n);
  if(n <= 4){ return printf("%lld\n", (n*(n-1))/2 ), 0; }

  ll ans = largestnines(n);
  ll inc = ans + 1;
  ll sum = 0;
  for(ll i=0; true; i++) {
    pair<ll, ll> b = bounds(n, ans+i*inc);
    sum += (b.second - b.first + 1) / 2;
    if(ans + (i+1)*inc > n + n - 1){
      break;
    }
  }
  printf("%lld\n", sum);

  return 0;
}

