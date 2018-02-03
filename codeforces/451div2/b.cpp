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

ll n, a, b;

int main(){
  scanf("%lld %lld %lld", &n, &a, &b);
  if(n == 0) return printf("YES\n0 0\n"), 0;

  for(ll i=0; i*a <= n; i++) {
    if((n - i*a) % b == 0) return printf("YES\n%lld %lld\n", i, (n-i*a)/b), 0;
  }

  printf("NO\n");

	return 0;
}

