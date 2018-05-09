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

int t;
int n, l[N], r[N], qt[N], ans[N];
vector<int> ad[N], rm[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &t);
  while(t--) {
    memset(qt, 0, sizeof qt);
    memset(ans, 0, sizeof ans);
    for(int i=0; i<N; i++) ad[i].clear(), rm[i].clear();
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
      scanf("%d %d", &l[i], &r[i]);

      ad[l[i]].push_back(i);
      rm[r[i]].push_back(i);
    }

    queue<int> q;
    for(int i=1; i<N; i++) {
      sort(ad[i].begin(), ad[i].end());
      sort(rm[i].begin(), rm[i].end());
    }

    for(int i=1; i<N; i++) {
      for(int j : ad[i]) q.push(j);
      while(!q.empty() and qt[q.front()]) q.pop();
      if(!q.empty()) {
        int u = q.front();
        q.pop();
        ans[u] = i;
        qt[u] = 1;
      }
      for(int j : rm[i]) qt[j] = 1;
    }

    for(int i=1; i<=n; i++) printf("%d ", ans[i]);
    printf("\n");
  }
	return 0;
}

