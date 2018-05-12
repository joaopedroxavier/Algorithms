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

int group[256];
int n, k, g[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &k);
  memset(group, -1, sizeof group);

  for(int i=0; i<n; i++) {
    scanf("%d", &g[i]);
    int p = g[i], q = 0;
    if(group[g[i]] != -1) continue;
    while(p > 0 and q < k) {
      q++;
      if(q == k or (group[p-1] != -1 and group[p-1] <= g[i] - k)) break;
      p--;
    }
    for(int j=p; j<=g[i]; j++) group[j] = p;
  }

  for(int i=0; i<n; i++) printf("%d ", group[g[i]]);
  printf("\n");

	return 0;
}

