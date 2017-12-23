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

ll n, k, m, t[N], p[N];

int main(){
  scanf("%lld %lld %lld", &n, &k, &m);

  for(int i=0; i<k; i++) scanf("%lld", &t[i]);

  sort(t, t+k);

  p[0] = t[0];
  for(int i=1; i<k; i++) p[i] = p[i-1] + t[i];

  ll ans = 0;
  for(ll i=0; i<=n; i++) if(m >= (p[k-1]*i)){
    ll s = p[k-1] * i;
    ll cnt = (k+1) * i;
    for(int j=0; j<k-1; j++) {
      for(int k=1; k<=n-i; k++) if(m >= s + t[j]) {
        s += t[j];
        cnt++;
      }
    }
    ans = max(ans, cnt);
  }

  printf("%lld\n", ans);

	return 0;
}

