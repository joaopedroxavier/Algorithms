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

const int N = 5e3+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, m;
int s[N], p[N], r[N], rec[N], ord[N];
bool used[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);

  for(int i=1; i<=n; i++) scanf("%d", &s[i]), ord[i-1] = i;
  for(int i=1; i<=m; i++) scanf("%d", &p[i]);
  for(int i=1; i<=m; i++) scanf("%d", &r[i]);
  //for(int i=0; i<m; i++) ord1[i] = ord2[i] = i;

  sort(ord, ord+n, [](int i, int j) { return s[i] > s[j]; });

  r[0] = INF;
  for(int i=0; i<n; i++) {
    int sz = s[ord[i]];
    int cheapest = 0;
    for(int j=1; j<=m; j++) {
      if(sz <= p[j] and !used[j]) {
        if(r[j] < r[cheapest]) cheapest = j;
      }
    }
    if(cheapest == 0) return printf("impossible\n"), 0;
    rec[ord[i]] = cheapest; used[cheapest] = true;
  }

  for(int i=1; i<=n; i++) printf("%d ", rec[i]);
  printf("\n");
	return 0;
}
