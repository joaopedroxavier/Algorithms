#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n;
int last[N], most[N], vis[N], v[N];

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    int u;
    scanf("%d", &u);
    v[i] = u;
    vis[u] = 1;
    if(last[u]) most[u] = max(most[u], i - last[u]);
    last[u] = i;
  }

  int ans = INF, best = v[0];
  for(int i=0; i<N; i++) if(vis[i]) {
    if(last[i] < ans) ans = last[i], best = i;
  }

  printf("%d\n", best);

	return 0;
}

