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
const int N=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int vis[N], b[N], x;
int r, c, p;
vector<int> black, white;
vector<int> adj[N];
map<ii, vector<int>> nodes;
char grid[N][N];

bool match(int u) {
  if(vis[u] == x) return 0;
  vis[u] = x;
  for(int v : adj[u]) {
    if(!b[v] or match(b[v])) return b[v] = u;
  }
  return 0;
}

void create(int i, int j) {
  nodes[mp(i,j)].pb(p++);
  if(grid[i][j] != 'o') nodes[mp(i,j)].pb(p++);
}

void fill(int i, int j) {
  int side = abs(i-j);

  for(int k : nodes[mp(i,j)]) {
    if(side & 1) white.pb(k);
    else black.pb(k);

    if(i < r-1) {
      for(int q : nodes[mp(i+1,j)]) {
        adj[k].pb(q);
      }
    }
    if(i > 0) {
      for(int q : nodes[mp(i-1,j)]) {
        adj[k].pb(q);
      }
    }
    if(j < c-1) {
      for(int q : nodes[mp(i,j+1)]) {
        adj[k].pb(q);
      }
    }
    if(j > 0) {
      for(int q : nodes[mp(i,j-1)]) {
        adj[k].pb(q);
      }
    }
  }
}

int main(){

  scanf("%d %d", &r, &c);

  for(int i=0; i<r; i++) 
    for(int j=0; j<c; j++) 
      scanf(" %c", &grid[i][j]);

  for(int i=0; i<r; i++)
    for(int j=0; j<c; j++) create(i,j);
  
  for(int i=0; i<r; i++) 
    for(int j=0; j<c; j++) fill(i,j);
  
  if(white.size() != black.size()) printf("N\n");
  else {
    int ans = 0; x = 0;
    for(int i : white) {
      x++;
      if(match(i)) ans++;
    }

    if(ans == (int) white.size()) printf("Y\n");
    else printf("N\n");
  }

  return 0;
}


