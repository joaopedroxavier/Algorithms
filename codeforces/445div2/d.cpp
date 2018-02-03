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
const int M=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, vis[27];
bool bad = false;
string st[N];
set<int> forw[27], backw[27];
bool app[27];

void dfs(int u) {
  if(vis[u]) { bad = true; return; }
  vis[u] = 1;
  if(!forw[u].empty()) {
    int v = *forw[u].begin();
    dfs(v);
  }
}

void dfsprint(int u) {
  vis[u] = 1;
  printf("%c", 'a' + u - 1);
  if(!forw[u].empty()) {
    int v = *forw[u].begin();
    dfsprint(v);
  }
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> st[i];
  }

  for(int i=0; i<n; i++) {
    int sz = (int) st[i].size();

    app[st[i][0] - 'a' + 1] = 1;
    if(sz > 1) {

      forw[st[i][0] - 'a'+1].insert(st[i][1] - 'a' + 1);
      for(int j=1; j<sz-1; j++) {
        app[st[i][j] - 'a' + 1] = 1;
        forw[st[i][j] - 'a'+1].insert(st[i][j+1] - 'a' + 1);
        backw[st[i][j] - 'a'+1].insert(st[i][j-1] - 'a' + 1);
      }
      backw[st[i][sz-1] - 'a'+1].insert(st[i][sz-2] - 'a' + 1);

    }
    app[st[i][sz-1] - 'a' + 1] = 1;
  }

  for(int i=1; i<=26; i++) if(forw[i].size() > 1 or backw[i].size() > 1) return printf("NO\n"), 0;

  for(int i=1; i<=26; i++) if(backw[i].empty()) dfs(i); 
  for(int i=1; i<=26; i++) if(!vis[i]) dfs(i);
  if(bad) return printf("NO\n"), 0;

  memset(vis, 0, sizeof vis);

  for(int i=1; i<=26; i++) if(backw[i].empty() and app[i]) dfsprint(i);
  printf("\n");
  return 0;
}

