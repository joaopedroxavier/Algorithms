#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define fst first
#define snd second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;

const long double EPS = 1e-9;
const int N=1e4+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m, k, cost[N][N];
int dx[] = {+0, +0, +1, -1};
int dy[] = {+1, -1, +0, +0};
int src, des;
vector<ii> adj[N][N], lit;
vi wt[N][N];

bool build_edge(ii p1, ii p2){
  return abs(p1.fst - p2.fst) <= 2 or abs(p1.snd - p2.snd) <= 2;
}

bool thats_a_very_particular_case(ii p1, ii p2){
  return abs(p1.fst - p2.fst) <= 1 or abs(p1.snd - p2.snd) <= 1;
}

int is_adj(ii p1, ii p2){
  return (abs(p1.fst - p2.fst) + abs(p1.snd - p2.snd) == 1);
}

bool flag;

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  for(int i=0;i<k;++i){
    int x, y;
    cin >> x >> y;
    if(x == n and y == m){
      des = i+1;
    }
    lit.pb(mp(x,y));
  }
  if(!des){
    k++;
    lit.pb(mp(n,m));
    flag = true;
  }
  for(int i=1;i<k;++i){
    for(int j=i+1;j<=k;++j){
      if(build_edge(lit[i], lit[j])){
        int x1 = lit[i].fst, y1 = lit[i].snd;
        int x2 = lit[j].fst, y2 = lit[j].snd;
        if(flag and lit[j] == mp(n,m)){
          if(thats_a_very_particular_case(lit[i], lit[j])){
            adj[x1][y1].pb(mp(x2,y2)), adj[x2][y2].pb(mp(x1,y1));
            wt[x1][y1].pb(1), wt[x2][y2].pb(1);
          }
        }
        else{
          adj[x1][y1].pb(mp(x2,y2)), adj[x2][y2].pb(mp(x1,y1));
          wt[x1][y1].pb(!is_adj(lit[i], lit[j])), wt[x2][y2].pb(!is_adj(lit[i], lit[j]));
        }
      }
    }
  }

  //  for(auto it=node.begin();it!=node.end();++it) cerr << "node[" << it->first << "]: " << (it->second).fst _ (it->second).snd << endl;

  //  for(int i=1;i<=k;++i){
  //    cerr << "node " << i << " is adjacent to: ";
  //    for(int j : adj[i]) cerr << j << ' ';
  //    cerr << endl;
  //  }

  memset(cost, 63, sizeof(cost));
  priority_queue<iii> pq;
  pq.push(mp(0,mp(1,1)));
  cost[1][1] = 0;
  while(!pq.empty()){
    int x = pq.top().snd.fst;
    int y = pq.top().snd.snd;
    int w = -pq.top().fst;
    pq.pop();
    for(int i=0;i<(int)adj[x][y].size();++i){
      int x1 = adj[x][y][i].fst;
      int y1 = adj[x][y][i].snd;
      if(cost[x1][y1] > w + wt[x][y][i]){
        //        if(wt[u][i] == 1) cerr << "Need to turn the lights on from node " << u << " to node " << v << endl;
        cost[x1][y1] = w + wt[x][y][i];
        pq.push(mp(-cost[x1][y1],mp(x1,y1)));
      }
    }
  }
  cout << ((cost[n][m] < INF) ? cost[n][m] : -1) << endl;
  return 0;
}

