#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 2e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, q;
vector<ll> st, pref;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &q);
  for(int i=0; i<n; i++) {
    ll u; scanf("%lld", &u);
    st.push_back(u);
  }

  pref.push_back(st[0]);
  for(int i=1; i<n; i++) pref.push_back(pref.back() + st[i]);

  ll cusum = 0;
  for(int i=0; i<q; i++) {
    ll u; scanf("%lld", &u);
    cusum += u;

    if(cusum >= pref.back()) {
      cusum = 0;
      printf("%d\n", n);
    } else {
      int it = upper_bound(pref.begin(), pref.end(), cusum) - pref.begin();
      printf("%d\n", n - it);
    }
  }
  
	return 0;
}

