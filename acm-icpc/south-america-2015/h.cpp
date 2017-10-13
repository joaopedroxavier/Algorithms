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
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m, ans;
int h[N][N], grid[N][N], vis[N][N], aux[N][N];
int minh[N], maxh[N], yeah[N];

int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};
int bx, by;
int max_x, max_y, max_z;
set<int> heights;

bool check(int x, int y){ return x > 0 and x <= bx and y > 0 and y <= by; }

void dfs(int x, int y){
  vis[x][y] = 1;
  for(int i=0;i<4;i++){
    int xn = x + dx[i];
    int yn = y + dy[i];
    if(!vis[xn][yn] and grid[xn][yn] and check(xn, yn)) dfs(xn, yn);
  }
}

int main(){
  scanf("%d %d", &n, &m);
  max_x = n, max_y = m;
  for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) scanf("%d", &h[i][j]), max_z = max(max_z, h[i][j]), heights.insert(h[i][j]);

  int id = 1;
  for(int i : heights){
    for(int x=1; x<=n; x++) for(int y=1; y<=m; y++) if(h[x][y] == i) aux[x][y] = id; 
    id++;
  }
  for(int x=1; x<=n; x++) for(int y=1; y<=m; y++) h[x][y] = aux[x][y];
  max_z = heights.size();

  //cima
  
  bx = max_x; by = max_y;
  for(int z=1; z<=max_z; z++){
    memset(grid, 0, sizeof grid);
    memset(vis, 0, sizeof vis);

    vector<ii> pts;
    for(int x=1; x<=max_x; x++) for(int y=1; y<=max_y; y++) if(h[x][y] == z) grid[x][y] = 1, pts.pb(mp(x, y));

    for(ii p : pts){
      int x = p.first, y = p.second;
      if(!vis[x][y]) ans++, dfs(x,y);
    }
  }

  //frente

  bx = max_x; by = max_z;
  for(int z=1; z<=max_y; z++){
    memset(yeah, 0, sizeof yeah);

    for(int x=1; x<=max_x; x++) maxh[x] = h[x][z], minh[x] = h[x][z+1] + 1;

    int p=1;
    while(maxh[p] < minh[p] and p <= max_x) p++;
    if(p <= max_x) ans++, yeah[p] = true;
    for(int x=p+1; x<=max_x; x++){
      if(maxh[x] >= minh[x]){
        yeah[x] = true;
        if(!yeah[x-1]) ans++;
        else if(minh[x] > maxh[x-1] or maxh[x] < minh[x-1]) ans++;
      }
      else yeah[x] = false;
    }
  }

  //tras

  for(int z=1; z<=max_y; z++){
    memset(yeah, 0, sizeof yeah);

    for(int x=1; x<=max_x; x++) maxh[x] = h[x][z], minh[x] = h[x][z-1] + 1;

    int p=1;
    while(maxh[p] < minh[p] and p <= max_x) p++;
    if(p <= max_x) ans++, yeah[p] = true;
    for(int x=p+1; x<=max_x; x++){
      if(maxh[x] >= minh[x]){
        yeah[x] = true;
        if(!yeah[x-1]) ans++;
        else if(minh[x] > maxh[x-1] or maxh[x] < minh[x-1]) ans++;
      }
      else yeah[x] = false;
    }
  }

  //esq

  for(int z=1; z<=max_x; z++){
    memset(yeah, 0, sizeof yeah);

    for(int x=1; x<=max_y; x++) maxh[x] = h[z][x], minh[x] = h[z+1][x] + 1;

    int p=1;
    while(maxh[p] < minh[p] and p <= max_y) p++;
    if(p <= max_y) ans++, yeah[p] = true;
    for(int x=p+1; x<=max_y; x++){
      if(maxh[x] >= minh[x]){
        yeah[x] = true;
        if(!yeah[x-1]) ans++;
        else if(minh[x] > maxh[x-1] or maxh[x] < minh[x-1]) ans++;
      }
      else yeah[x] = false;
    }
  }

  //dir

  for(int z=1; z<=max_x; z++){
    memset(grid, 0, sizeof grid);
    memset(vis, 0, sizeof vis);
    memset(yeah, 0, sizeof yeah);

    for(int x=1; x<=max_y; x++) maxh[x] = h[z][x], minh[x] = h[z-1][x] + 1;

    int p=1;
    while(maxh[p] < minh[p] and p <= max_y) p++;
    if(p <= max_y) ans++, yeah[p] = true;
    for(int x=p+1; x<=max_y; x++){
      if(maxh[x] >= minh[x]){
        yeah[x] = true;
        if(!yeah[x-1]) ans++;
        else if(minh[x] > maxh[x-1] or maxh[x] < minh[x-1]) ans++;
      }
      else yeah[x] = false;
    }
  }

  printf("%d\n", ans+1);

  return 0;
}

