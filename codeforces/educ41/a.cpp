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

int n, m, a[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++) {
    int u; scanf("%d", &u);
    a[u]++;
  }
  int ans = INF;
  for(int i=1; i<=n; i++) ans = min(ans, a[i]);
  printf("%d\n", ans);
	return 0;
}

