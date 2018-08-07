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

ll dist[N][3];
vector<int> adj[N], wt[N];
int n, m;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++) {
    int u, v, w; scanf("%d %d %d", &u, &v, &w);
    adj[u].push_back(v);
    adj[v].push_back(u);
    wt[u].push_back(w);
    wt[v].push_back(w);
  }

  memset(dist, 63, sizeof dist);
  priority_queue<pair<ll, pair<int, int>>> pq;
  pq.push({0, {0, 1}});

  while(!pq.empty()) {
    auto t = pq.top();
    ll d = -t.st;
    int p = t.nd.st;
    int u = t.nd.nd;

    pq.pop();
    if(u == n) continue;

    for(int i=0; i<(int)adj[u].size(); i++) {
      int np = (p + 1) % 3;
      int v = adj[u][i], w = wt[u][i];
      if(dist[v][np] > d + w) {
        dist[v][np] = d + w;
        pq.push({-dist[v][np], {np, v}});
      }
    }
  }

  vector<pair<int, string>> ord;
  ord.push_back({dist[n][0], "me"});
  ord.push_back({dist[n][1], "Gon"});
  ord.push_back({dist[n][2], "Killua"});

  sort(ord.begin(), ord.end());
  for(auto p : ord) printf("%s\n", p.nd.c_str());

	return 0;
}

