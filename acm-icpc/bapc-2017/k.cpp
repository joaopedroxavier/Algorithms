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

const int N = 1e3+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, vis[N];
char adj[N][N];
vector<int> ord;

void dfs(int u) {
  vis[u] = 1;
  ord.push_back(u);
  for(int i=0; i<n; i++) if(adj[u][i] == '1' and !vis[i]) {
    dfs(i);
  }
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
    scanf(" %c", &adj[i][j]);
  }

  dfs(0);
  for(int i=1; i<n; i++) if(!vis[i]) return printf("impossible\n"), 0;

  reverse(ord.begin(), ord.end());
  for(int i : ord) printf("%d ", i);
  printf("\n");
	return 0;
}

