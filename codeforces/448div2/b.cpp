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

ll n, x, k;
ll ans, a[N];

int main(){
  scanf("%lld %lld %lld", &n, &x, &k);

  for(int i=0; i<n; i++) {
    scanf("%lld", &a[i]);
  }

  sort(a, a+n);

  for(int i=0; i<n; i++) {
    ll d = a[i] / x;
    if(d < k) continue;
    ll c1 = upper_bound(a, a+n, (d-k)*x) - a;
    ll c2 = upper_bound(a, a+n, (d-k+1)*x) - a;
    ll c3 = upper_bound(a, a+n, a[i]) - a;
    c2 = min(c2, c3);
    ans += c2 - c1;
  }

  printf("%lld\n", ans);

	return 0;
}

