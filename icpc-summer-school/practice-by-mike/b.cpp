#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int dx[] = {-1, +1, +0, +0};
int dy[] = {+0, +0, -1, +1};
int n, m, x, vis[N], b[N], ans;
set<ii> er;

vector<int> white, black, adj[N];

bool check(int i, int j) { return i >= 0 and i < n and j >= 0 and j < n; }

void create(int i, int j) {
  int p = i*n + j + 1;

  if(abs(j-i) & 1) black.push_back(p);
  else white.push_back(p);

  for(int k=0; k<4; k++) {
    int in = i + dx[k];
    int jn = j + dy[k];

    if(check(in, jn) and !er.count({in, jn})) {
      int q = in * n + jn + 1;
      adj[p].push_back(q);
    }
  }
}

pair<int, int> recover(int p) { return make_pair((p-1)/n, (p-1)%n); }

bool match(int u) {
  if(vis[u] == x) return 0;
  vis[u] = x;
  for(int v : adj[u]) {
    if(!b[v] or match(b[v])) return b[v] = u;
  }
  return 0;
}

int main(){
  scanf("%d %d", &n, &m);

  for(int i=0; i<m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);

    er.insert(mp(u-1,v-1));
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) if(!er.count(mp(i,j))) {
      create(i,j);
    }
  }
  if(white.size() != black.size()) return printf("No\n"), 0;

  /*
  for(int i : white) {
    printf("white: %d %d\n", recover(i).first, recover(i).second);
    printf("linking with: ");
    for(int q : adj[i]) printf("%d %d, ", recover(q).first, recover(q).second);
    printf("\n");
  }
  for(int i : black) {
    printf("black: %d %d\n", recover(i).first, recover(i).second);
    printf("linking with: ");
    for(int q : adj[i]) printf("%d %d, ", recover(q).first, recover(q).second);
    printf("\n");
  }
  */

  for(int i : white) ++x, ans += match(i);
  if(ans != (int) white.size()) return printf("No\n"), 0;

  printf("Yes\n");
  vector<ii> hor, ver;
  for(int u : black) {
    int v = b[u];
    ii piece_u = recover(u), piece_v = recover(v);

    if(piece_u.first == piece_v.first) ver.push_back({piece_u.first, min(piece_u.second, piece_v.second)});
    if(piece_u.second == piece_v.second) hor.push_back({min(piece_u.first, piece_v.first), piece_u.second});
  }

  printf("%d\n", (int) hor.size());
  for(auto p : hor) printf("%d %d\n", p.first+1, p.second+1);
  printf("%d\n", (int) ver.size());
  for(auto p : ver) printf("%d %d\n", p.first+1, p.second+1);

  return 0;
}

