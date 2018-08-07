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

int x[N], y[N];
map<ii, int> idx;
vector<int> adj[N];

int manhattan_dist(int i, int px, int py) { return abs(x[i] - px) + abs(y[i] - py); }

void proc(int i) {
  for(int px = x[i]+1; px <= x[i]+5; px++) {
    for(int py = y[i]-5; py <= y[i]+5; py++) {
      if(manhattan_dist(i, px, py) <= 5) {
        if(idx.count(mp(px, py))) {
          int u = idx[mp(px, py)];
          adj[i].push_back(u);
        }
      }
    }
  }
}

int n, l;

struct answer {
  int res;
  bool cont;
};

answer dp[N];

answer best(int u) {
  if(dp[u].res) return dp[u];

  if(adj[u].empty()) {
    if(u == n+1) return {0, true};
    else return {0, false};
  }

  answer ret = {0, false};
  for(int v : adj[u]) {
    answer bv = best(v);
    if(bv.cont) {
      ret.cont = true;
      ret.res = max(ret.res, bv.res);
    }
  }
  ret.res++; 

  return dp[u] = ret;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &l);
  for(int i=1; i<=n; i++) {
    int u, v; scanf("%d %d", &u, &v);
    x[i] = u, y[i] = v;
    idx[mp(x[i], y[i])] = i;
  }
  x[n+1] = l, y[n+1] = 0;
  idx[mp(x[n+1], y[n+1])] = n+1;

  x[0] = 0, y[0] = 0;
  for(int i=0; i<=n; i++) proc(i);

  answer ans = best(0);

  printf("%d\n", ans.res - 1);
	return 0;
}

