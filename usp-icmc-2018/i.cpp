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

int tin[N], tout[N], st[N], cnt;
vector<int> adj[N];

void dfs(int u) {
  tin[u] = ++cnt;
  for(int v : adj[u]) dfs(v);
  tout[u] = ++cnt;
}

int n, q;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &q);
  
  for(int i=0; i<n; i++) {
    int u; scanf("%d", &u);

    if(~u) adj[u].push_back(i);
    else st[i] = true;
  }

  for(int i=0; i<n; i++) if(st[i]) dfs(i);

  for(int i=0; i<q; i++) {
    int u, v; scanf("%d %d", &u, &v);

    if(tin[v] <= tin[u] and tout[v] >= tout[u]) printf("Yes\n");
    else printf("No\n");
  }

	return 0;
}

