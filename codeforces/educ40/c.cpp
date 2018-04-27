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

ll x, y = -1;
int n;
ll v[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%lld", &v[i]);
    v[i]--;
    if(i > 0) {
      if(abs(v[i] - v[i-1]) < 1) return printf("NO\n"), 0;
      if(abs(v[i] - v[i-1]) != 1) {
        if(y != -1) {
          if(abs(v[i] - v[i-1]) != y) return printf("NO\n"), 0;
        } else {
          y = abs(v[i] - v[i-1]);
        }
      }
    }
  }

  if(y == -1) return printf("YES\n1 1000000000\n"), 0;

  for(int i=1; i<n; i++) {
    if(abs(v[i] - v[i-1]) == 1) {
      if((v[i]) / y != (v[i-1]) / y) return printf("NO\n"), 0;
    }
    x = max(x, (v[i]) / y);
  }
  x = max(x, v[0] / y);

  printf("YES\n%lld %lld\n", x+1, y);
	return 0;
}

