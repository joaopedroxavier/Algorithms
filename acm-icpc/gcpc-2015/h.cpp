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

const int N = 4e2+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

bool prog[N], vis[N];

map<string, int> id;

int n;
vector<int> adj[N];

void dfs(int u) {
  if(vis[u]) return;
  vis[u] = 1;
  for(int v : adj[u]) dfs(v);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  int cnt = 0;
  for(int i=1; i<=n; i++) {
    int k; string s;
    cin >> s >> k;
    if(!id.count(s)) id[s] = ++cnt;

    for(int j=0; j<k; j++) {
      string t; cin >> t;
      if(!id.count(t)) id[t] = ++cnt;

      adj[id[t]].push_back(id[s]);
    }
  }

  for(auto p : id) {
    auto t = p.st.find("::");
    prog[p.nd] = p.st.substr(t+2) == "PROGRAM";
  }

  for(int i=1; i<=n; i++) if(prog[i]) {
    dfs(i);
  }

  int ans = 0;
  for(int i=1; i<=n; i++) ans += !vis[i];

  printf("%d\n", ans);

  return 0;
}

