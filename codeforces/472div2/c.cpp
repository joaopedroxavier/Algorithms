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

int e[N];
int n, u;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &u);
  for(int i=0; i<n; i++) {
    scanf("%d", &e[i]);
  }

  ld ans = 0;
  bool found = false;
  for(int i=0; i<n-2; i++) {
    int j = i+1;
    int k = upper_bound(e, e+n, e[i] + u) - e;
    if(k > 0) k--;
    if(k <= j) continue;
    found = true;

    ld eff = e[k] - e[j];
    ld effb = e[k] - e[i];
    ans = max(ans, eff / effb);
  }

  if(!found) printf("-1\n");
  else printf("%.12Lf\n", ans);
	return 0;
}

