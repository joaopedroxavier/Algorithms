//
//
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;
const long double PI = acos(-1);

struct circle{
  ld x;
  ld y;
  ld rad;
};

bool is_inside(circle a, circle b){
  bool cond1 = a.x - a.rad + EPS > b.x - b.rad;
  bool cond2 = a.x + a.rad - EPS < b.x + b.rad;
  bool cond3 = a.y - a.rad + EPS > b.y - b.rad;
  bool cond4 = a.y + a.rad - EPS < b.y + b.rad;
  return cond1 and cond2 and cond3 and cond4;
}

ld area(circle c){ return PI*c.rad*c.rad; }

int n;
circle dancer[N];
vi adj[N];
int vis[N]; 
ld sum;

void dfs(int u, int p){
  vis[u] = p;
  for(int v : adj[u]){
    if(!vis[v]) dfs(v, p+1);
  }
}

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;++i) scanf("%Lf %Lf %Lf", &dancer[i].x, &dancer[i].y, &dancer[i].rad);
  sort(dancer, dancer+n, [](circle a, circle b){ return a.rad > b.rad; });
  for(int i=0;i<n;++i){
    for(int j=i-1;j>=0;--j) if(is_inside(dancer[i], dancer[j])){
      adj[j].pb(i);
      break;
    }
  }

  for(int i=0;i<n;++i) if(!vis[i]){
    dfs(i, 1);
  }

  for(int i=0;i<n;++i){
    if(vis[i] != 1 and vis[i]%2) sum -= area(dancer[i]);
    else sum += area(dancer[i]);
  }

  printf("%.9lf\n", (double)sum);
  return 0;
}

