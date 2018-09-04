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
const int M = 2e3+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

char m[M][M];
int bck[M][M];
int t, h, v;
int x, vis[N], b[N], ans;
vector<int> adj[N];

bool match(int u) {
  if(vis[u] == x) return 0;
  vis[u] = x;
  for(int v : adj[u]) {
    if(!b[v] or match(b[v])) return b[v] = u;
  }
  return 0;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> t;
  while(t--) {
    memset(m, 0, sizeof m);
    memset(b, 0, sizeof b);
    memset(bck, 0, sizeof bck);
    memset(vis, 0, sizeof vis);

    for(int i=0; i<N; i++) adj[i].clear();

    cin >> h >> v;

    for(int i=1; i<=h; i++) {
      int x, y; string s;
      cin >> x >> y >> s;
      for(int j = 0; j < (int) s.size(); j++) {
        m[y][x+j] = s[j];
        bck[y][x+j] = i;
      }
    }

    for(int i=h+1; i<=h+v; i++) {
      int x, y; string s;
      cin >> x >> y >> s;
      for(int j = 0; j < (int) s.size(); j++) {
        char c = s[j];
        if(m[y+j][x] and m[y+j][x] != c) {
          int k = bck[y+j][x];

          adj[i].push_back(k);
          adj[k].push_back(i);
        }
      }
    }

    ans = 0; x = 0;
    for(int i=1; i<=h; i++) {
      x++; ans += match(i);
    }

    printf("%d\n", h+v-ans);
  }
	return 0;
}

