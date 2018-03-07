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

const int N = 1e2+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int memo[N][N][30];
map<int, vector<int>> adj[N];

int dp(int mypos, int yrpos, int k) {
  if(~memo[mypos][yrpos][k]) return memo[mypos][yrpos][k];

  set<int> grundy;
  for(auto it : adj[mypos]) if(it.first >= k) {
    for(auto v : it.second) {
      grundy.insert(dp(yrpos, v, it.first));
    }
  }

  int mex = 0;
  while(grundy.count(mex)) mex++;

  return memo[mypos][yrpos][k] = mex;
}

int n, m;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++) {
    int u, v; char c;
    scanf("%d %d %c", &u, &v, &c);

    adj[u][c-'a'].push_back(v);
  }

  memset(memo, -1, sizeof memo);

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      printf("%c", dp(i, j, 0) ? 'A' : 'B');
    }
    printf("\n");
  }

  return 0;
}

