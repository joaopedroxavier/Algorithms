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

int par[N], sz[N];

int find(int p) { return par[p] == p ? p : par[p] = find(par[p]); }

bool unite(int a, int b) {
  a = find(a), b = find(b);
  if(a == b) return false;

  if(sz[a] > sz[b]) swap(a, b);
  sz[b] += sz[a], par[a] = b;

  return true;
}

int n, m;
vector<ii> ed;
vector<int> qry, ans;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &m);

  for(int i=0; i<m; i++) {
    int u, v; scanf("%d %d", &u, &v);
    ed.push_back({u,v});
  }

  for(int i=0; i<m; i++) {
    int q; scanf("%d", &q);
    qry.push_back(q);
  }

  reverse(qry.begin(), qry.end());
  for(int i=1; i<=n; i++) par[i] = i;

  for(int i=0; i<m; i++) {
    int q = qry[i] - 1;
    ii e = ed[q];
    ans.push_back(n);
    if(unite(e.st, e.nd)) n--;
  }

  reverse(ans.begin(), ans.end());
  for(int i : ans) printf("%d\n", i);

	return 0;
}

