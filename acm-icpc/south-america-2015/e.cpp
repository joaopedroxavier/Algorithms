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
const int N=2e2+5;
const int M=1e4+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int d, p, r, b, sum, x;
int cost[N];
int group[N], cost_group[N], gain[N], sack[N][M];
vi adj[N];

void dfs(int u){
  group[u] = x;
  
  (u <= d) ? gain[x]-- : gain[x]++; 
  sum += cost[u];

  for(int v : adj[u]) if(!group[v]) dfs(v);
}

int main(){
  scanf("%d %d %d %d", &d, &p, &r, &b);

  for(int i=1; i<=d; i++) scanf("%d", &cost[i]);
  for(int i=1; i<=p; i++) scanf("%d", &cost[d+i]);

  for(int i=1; i<=r; i++){
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].pb(v+d), adj[v+d].pb(u);
  }

  for(int i=1; i<=d+p; i++) if(!group[i]){
    x++, sum = 0;
    dfs(i);
    cost_group[x] = sum;
  }

  for(int i=1; i<=x; i++){
    for(int j=0; j<=b; j++){
      sack[i][j] = sack[i-1][j];
      if(cost_group[i] <= j) sack[i][j] = max(sack[i-1][j], sack[i-1][j - cost_group[i]] + gain[i]); 
    }
  }

  /*
  for(int i=0; i<=x; i++){
    for(int j=0; j<=b; j++) printf("%d", sack[i][j]);
    printf("\n");
  }
  */

  printf("%d ", d + sack[x][b]);

  memset(sack, 0, sizeof sack);
  for(int i=1; i<=x; i++){
    for(int j=0; j<=b; j++){
      sack[i][j] = sack[i-1][j];
      if(cost_group[i] <= j) sack[i][j] = max(sack[i-1][j], sack[i-1][j - cost_group[i]] - gain[i]); 
    }
  }

  /*
  for(int i=0; i<=x; i++){
    for(int j=0; j<=b; j++) printf("%d", sack[i][j]);
    printf("\n");
  }
  */

  printf("%d\n", p + sack[x][b]);

	return 0;
}

