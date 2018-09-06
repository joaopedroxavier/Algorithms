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

int n, dist[N], used[N];
set<int> adj[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);

  for(int i=1; i<n; i++) {
    int u, v; scanf("%d %d", &u, &v);
    adj[u].insert(v);
    adj[v].insert(u);
  }

  vector<int> ord;
  for(int i=1; i<=n; i++) {
    int u; scanf("%d", &u);
    ord.push_back(u);
  }

  int p = 0;
  queue<int> q;
  q.push(1); used[1] = 1;

  if(ord[0] != 1) return printf("No\n"), 0;
  p++;

  while(!q.empty()) {
    int u = q.front();
    q.pop();

    int cnt = 0;
    while(adj[u].count(ord[p])) {
      q.push(ord[p]);
      p++; cnt++;
    }

  }

  printf("%s\n", (p == (int) ord.size()) ? "Yes" : "No");

  return 0;
}

