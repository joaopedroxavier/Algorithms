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

int n, m, k, cost[N];
int src, des;
vi adj[N], wt[N];

bool build_edge(ii p1, ii p2){
  return abs(p1.fst - p2.fst) <= 2 or abs(p1.snd - p2.snd) <= 2;
}

bool thats_a_very_particular_case(ii p1, ii p2){
  return abs(p1.fst - p2.fst) <= 1 or abs(p1.snd - p2.snd) <= 1;
}

int is_adj(ii p1, ii p2){
  return (abs(p1.fst - p2.fst) + abs(p1.snd - p2.snd) == 1);
}

map<ii, int> idx;
map<int, ii> node;
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
    idx[mp(x,y)] = i+1;
    node[i+1] = mp(x,y);
  }
  if(!des){
    idx[mp(n,m)] = ++k;
    node[k] = mp(n,m);
    flag = true;
  }
  for(int i=1;i<k;++i){
    for(int j=i+1;j<=k;++j){
      if(build_edge(node[i], node[j])){
        if(flag and node[j] == mp(n,m)){
          if(thats_a_very_particular_case(node[i], node[j])){
            adj[i].pb(j), adj[j].pb(i);
            wt[i].pb(1), wt[j].pb(1);
          }
        }
        else{
          adj[i].pb(j), adj[j].pb(i);
          wt[i].pb(!is_adj(node[i], node[j])), wt[j].pb(!is_adj(node[i], node[j]));
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
  priority_queue<ii> pq;
  pq.push(mp(0,idx[mp(1,1)]));
  cost[idx[mp(1,1)]] = 0;
  while(!pq.empty()){
    int u = pq.top().snd;
    int w = -pq.top().fst;
    pq.pop();
    for(int i=0;i<(int)adj[u].size();++i){
      int v = adj[u][i];
      if(cost[v] > w + wt[u][i]){
//        if(wt[u][i] == 1) cerr << "Need to turn the lights on from node " << u << " to node " << v << endl;
        cost[v] = w + wt[u][i];
        pq.push(mp(-cost[v],v));
      }
    }
  }
  cout << ((cost[idx[mp(n,m)]] < INF) ? cost[idx[mp(n,m)]] : -1) << endl;
	return 0;
}

