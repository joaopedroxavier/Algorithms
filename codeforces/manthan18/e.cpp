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

const int N = 2e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, m, k, d[N];
set<ii> s;
set<int> adj[N];
ii ed[N];

void upd(int u, int v) {
  s.erase({adj[u].size(), u});
  adj[u].erase(v);
  s.insert({adj[u].size(), u});
}

void proceed() {
  while(!s.empty() and (*s.begin()).st < k) {
    auto p = *s.begin();
    int u = p.nd;
    int d = p.st;

    for(int v : adj[u]) {
      upd(v, u);
    }

    adj[u].clear();
    s.erase({d, u});
  }
}

void print() {
  for(auto p : s) printf("(%d, %d) ", p.nd, p.st);
  printf("\n");
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d %d", &n, &m, &k);

  for(int i=0; i<m; i++) {
    int u, v; scanf("%d %d", &u, &v);
    ed[i] = {u, v};

    adj[u].insert(v);
    adj[v].insert(u);
  }

  for(int i=1; i<=n; i++) s.insert({adj[i].size(), i});

  //print();
  proceed();
  //print();

  vector<int> ans;
  for(int i=m-1; i>=0; i--) {
    ans.push_back(s.size());

    ii e = ed[i];
    int u = e.st, v = e.nd;

    if(s.count({adj[u].size(), u}) and s.count({adj[v].size(), v})) {
      upd(u, v);
      upd(v, u);
    }

    proceed();
    //print();
  }

  reverse(ans.begin(), ans.end());

  for(int i : ans) printf("%d\n", i);

  return 0;
}

