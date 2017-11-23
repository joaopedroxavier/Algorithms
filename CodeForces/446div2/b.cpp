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
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll alive[N], l[N];
ll n;

int main(){
  scanf("%lld", &n);
  for(int i=1; i<=n; i++) scanf("%lld", &l[i]), alive[i] = 1; 

  ll p = INF, q = n;
  while(q) {
    if(p <= q) alive[q] = 0;
    p = min(p, q - l[q]);
    q--;
  }

  ll ans=0;
  for(int i=1; i<=n; i++){ ans += alive[i]; }
  printf("%lld\n", ans);

	return 0;
}

