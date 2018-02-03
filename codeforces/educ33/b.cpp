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

bool test(ll p) {
  ll p1 = 2, p2 = 1;
  ll a = (p1-1) * p2;
  while(a <= p) {
    if(a == p) return true;
    p1 *= 2, p2 *= 2;
    a = (p1-1)*p2;
  }
  return false;
}

int main(){
  scanf("%lld", &n);

  ll ans = 1;
  for(ll i=1; i<=n; i++) if((n%i == 0) and test(i)) ans = i;

  printf("%lld\n", ans);
	return 0;
}

