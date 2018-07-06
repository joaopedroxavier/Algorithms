//
// Elohim Essaim, Elohim Essaim, I implore you...
//
#include <bits/stdc++.h>

using namespace std;

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

int n, t;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &t);
  while(t--) {
    vector<int> v;
    int n; scanf("%d", &n);

    for(int i=0; i<n; i++) {
      int u; scanf("%d", &u);
      v.push_back(u);
    }

    sort(v.begin(), v.end());
    int ans = INF;
    for(int i=0; i<=100; i++) {
      int cost = 0;
      if(i >= v[0]) cost += 2*(i-v[0]);
      if(i <= v[n-1]) cost += 2*(v[n-1]-i);

      ans = min(ans, cost);
    }

    printf("%d\n", ans);
  }
	return 0;
}

