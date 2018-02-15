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

ll n, a, b, ka, kb;

bool find() {
  for(ll i=0; i<=n and n-i*a >= 0; i++) if((n - i*a) % b == 0) {
    ka = i; kb = (n - i*a) / b;
    return true;
  }
  return false;
}

int main(){
  scanf("%lld %lld %lld", &n, &a, &b);

  if(!find()) return printf("-1\n"), 0;

  for(ll i=0; i<ka; i++) {
    for(ll j=0; j<a; j++) {
      printf("%lld ", i*a+1+(j+1)%a);
    }
  }
  for(ll i=0; i<kb; i++) {
    for(ll j=0; j<b; j++) {
      printf("%lld ", ka*a + i*b+1+(j+1)%b);
    }
  }
  printf("\n");

	return 0;
}

