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
const int N=2e5+5;
const ll M=32000;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, a[N];
vector<ll> diff;
int z;

ll find(ll x) {
  ll l = 0, r = M-1;
  while(l < r) {
    ll m = (l+r)/2;
    if(m*m < x) l = m+1;
    else r = m;
  }
  return l*l;
}

ll lfind(ll x) {
  ll l = 0, r = M-1;
  while(l < r) {
    ll m = (l+r+1)/2;
    if(m*m > x) r = m-1;
    else l = m;
  }
  return l*l;
}

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    scanf("%d", &a[i]);
    if(a[i] == 0) z++;
  }

  int ann = 0, borya = 0;
  for(int i=0; i<n; i++) {
    ll p = find(a[i]), q = lfind(a[i]);
    ll d = min(abs(p-a[i]), abs(q-a[i]));
    if(d == 0) ann++;
    else {
      borya++;
      diff.pb(d);
    }
  }

  sort(diff.begin(), diff.end());

  if(ann >= borya) {
    ll ans = 0;
    while(ann > z and ann > borya){
      ans++, ann--, borya++;
    }
    while(ann > borya){
      ans+=2, ann--, borya++;
    }
    printf("%lld\n", ans);
  }
  else {
    ll ans = 0;
    for(int i=0; ann < borya; i++) {
      ans += diff[i];
      ann++, borya--;
    }
    printf("%lld\n", ans);
  }

	return 0;
}

