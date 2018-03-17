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

const int N = 1e6+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, night[N];
int h[N], r[N], t[N];
int maxp;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  for(int i=0; i<N; i++) night[i] = 1;

  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d %d %d", &h[i], &r[i], &t[i]);
    maxp = max(maxp, h[i]);
    
    for(int j=0; j<N; j++) {
      int tim = j % h[i];
      if(r[i] < t[i]) {
        if(tim < t[i] and tim > r[i]) night[j] = false;
      }
      else {
        if(!(tim >= t[i] and tim <= r[i])) night[j] = false;
      }
    }
  }

  for(int i=0; i<1825*maxp; i++) {
    if(night[i]) return printf("%d\n", i), 0;
  }
  printf("impossible\n");
	return 0;
}

