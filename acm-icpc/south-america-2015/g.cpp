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
const long double INF=1e18;

long double A[N][N], B[N][N], dist[N];
vi adj[N];
int n, m;

long double sh_path(long double t){
  for(int i=1; i<=n; i++) dist[i] = INF;

  priority_queue<pair<long double, int>> dij;
  dij.push(mp(0, 1));
  dist[1] = 0;

  while(!dij.empty()){
    long double d = -dij.top().first;
    int u = dij.top().second;
    dij.pop();

    for(int v : adj[u]){
      if(dist[v] > d + A[u][v] * t + B[u][v]){
        dist[v] = d + A[u][v] * t + B[u][v];
        dij.push(mp(-dist[v], v));
      }
    }
  }

  return dist[n];
}

long double ter_search(long double l, long double r){
  for(int i=0; i<100;i++){
    //printf("%Lf %Lf\n", l, r);
    long double m1 = (2*l + 1*r) / 3;
    long double m2 = (1*l + 2*r) / 3;
    if(sh_path(m1) < sh_path(m2)) l = m1;
    else r = m2;
  }
  return sh_path(l);
}

int main(){
  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) A[i][j] = -1, B[i][j] = -1;

  for(int i=0; i<m; i++){
    int u, v; long double a, b;
    scanf("%d %d %Lf %Lf", &u, &v, &a, &b);
    adj[u].pb(v), adj[v].pb(u);
    A[u][v] = A[v][u] = a;
    B[u][v] = B[v][u] = b;
  }

  printf("%.5Lf\n", ter_search(0, 24*60));

	return 0;
}

