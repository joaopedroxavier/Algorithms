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

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

ll n, h[N];
ll l, r;
bool gu[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld", &n);

  ll ans = 0;
  ll ma = 0;
  stack<int> going;
  for(int i=0; i<n; i++) {
    going.push(i);
    scanf("%lld", &h[i]);
    if(h[i] + 1 > ma) {
      int diff = h[i] + 1 - ma;
      ma = h[i] + 1;
      for(int j=0; j<diff; j++) {
        int t = going.top();
        gu[t] = true;
        going.pop();
      }
    }
  }

  gu[0] = true;

  /*
  for(int i=0; i<n; i++) {
    printf("%d ", gu[i]);
  }
  printf("\n");
  */

  ll ht = 0;
  for(ll i=0; i<n; i++) {
    if(gu[i]) {
      ht++;
    }
    ans += ht - h[i] - 1;
  }

  printf("%lld\n", ans);
	return 0;
}

