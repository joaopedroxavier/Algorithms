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

int t;
int n, k, p[N], a[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  
  scanf("%d", &t);
  while(t--) {
    memset(p, 0, sizeof p);
    memset(a, 63, sizeof a);

    scanf("%d %d", &n, &k);
    vector<int> pos;
    for(int i=0; i<k; i++) {
      int u; scanf("%d", &u);
      p[u] = 1;
    }

    int l=0;
    for(int i=1; i<=n; i++) {
      if(p[i]) l = i;
      if(l) a[i] = i-l+1;
    }

    int r=n+1;
    for(int i=n; i>0; i--) {
      if(p[i]) r = i;
      if(r != n+1) a[i] = min(a[i], r-i+1);
    }

    int ans = 0;
    for(int i=1; i<=n; i++) ans = max(ans, a[i]);

    printf("%d\n", ans);
  }

	return 0;
}

