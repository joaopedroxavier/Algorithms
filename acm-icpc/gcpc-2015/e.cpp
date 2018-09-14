//
// 내가 나인 게 싫은 날
// 영영 사라지고 싶은 날
// 문을 하나 만들자 너의 맘 속에다
// 그 문을 열고 들어가면
// 이 곳이 기다릴 거야
// 믿어도 괜찮아 널 위로해줄 magic shop
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

struct Edge {
  int u, v, w;
  bool operator<(Edge e) const { 
    if(w != e.w) return w < e.w;
    return u == e.u ? v < e.v : u < e.u;
  }
};

int dist[N][3], src[2];
vector<Edge> adj[N];

void dij(int u) {
  priority_queue<pair<ll, int>> pq;
  dist[src[u]][u] = 0;

  pq.push({0, src[u]});
  while(!pq.empty()) {
    int a = pq.top().nd;
    int d = -pq.top().st;

    pq.pop();

    for(Edge e : adj[a]) {
      int b = e.v;
      if(dist[b][u] > d + e.w) {
        dist[b][u] = d + e.w;
        pq.push({-dist[b][u], b});
      }
    }
  }
}

set<Edge> usedE;
set<int> usedV;
Edge par[N];
map<Edge, int> freq;
int n, m, k;

void get_edges() {
  priority_queue<pair<ll, int>> pq;
  dist[1][2] = 0;

  pq.push({0, 1});
  while(!pq.empty()) {
    int a = pq.top().nd;
    int d = -pq.top().st;

    pq.pop();

    for(Edge e : adj[a]) {
      int b = e.v;
      if(usedV.count(b) and dist[b][2] > d + e.w) {
        dist[b][2] = d + e.w;
        par[b] = e;
        pq.push({-dist[b][2], b});
      }
    }
  }

  int p = n;
  while(p != 1) {
    Edge e = par[p];
    usedE.insert({e.u, e.v, e.w});
    usedE.insert({e.v, e.u, e.w});
    p = e.u;
  }
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  
  scanf("%d %d %d", &n, &m, &k);

  for(int i=0; i<k; i++) {
    int u; scanf("%d", &u);
    usedV.insert(u);
  }

  vector<Edge> edges;
  for(int i=0; i<m; i++) {
    int u, v, w; scanf("%d %d %d", &u, &v, &w);

    Edge str = {u, v, w};
    Edge rev = {v, u, w};

    adj[u].push_back(str);
    adj[v].push_back(rev);

    edges.push_back(str);
    edges.push_back(rev);

    freq[str]++;
    freq[rev]++;
  }

  memset(dist, 63, sizeof dist);
  src[0] = 1; src[1] = n;

  dij(0);
  dij(1);

  int ans = dist[n][0];

  get_edges();

  for(auto e : usedE) if(freq[e] > 1) return printf("yes\n"), 0;

  for(Edge e : edges) if(!usedE.count(e)) {
    int u = e.u, v = e.v, w = e.w;
    int cand = dist[u][0] + w + dist[v][1];
    if(ans == cand) return printf("yes\n"), 0;
  }

  printf("no\n");

	return 0;
}

