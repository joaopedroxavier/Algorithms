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

int n, m, cop[N], inc[N];
vi adj[N];

int main(){
  scanf("%d %d", &n, &m);

  for(int i=1; i<=n; i++) scanf("%d", &cop[i]);
  for(int i=1; i<=m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[v+1].pb(u+1);
    inc[u+1]++;
  }

  queue<int> topo;
  queue<int> wait;
  for(int i=1; i<=n; i++) {
    if(inc[i] == 0 and cop[i] == 0) topo.push(i);
    else if(inc[i] == 0 and cop[i] == 1) wait.push(i);
  }

  int ans = 0;
  while(!topo.empty() or !wait.empty()) {
    if(topo.empty()) {
      ans++;
      queue<int> newtopo;
      while(!wait.empty()) topo.push(wait.front()), wait.pop();
      while(!topo.empty()) {
        int u = topo.front();
        for(int v : adj[u]) {
          inc[v]--;
          if(inc[v] == 0 and cop[v] == 1) topo.push(v);
          else if(inc[v] == 0 and cop[v] == 0) newtopo.push(v);
        }
        topo.pop();
      }
      topo = newtopo;
    }
    else {
      int u = topo.front();
      for(int v : adj[u]) {
        inc[v]--;
        if(inc[v] == 0 and cop[v] == 0) topo.push(v);
        else if(inc[v] == 0 and cop[v] == 1) wait.push(v);
      }
      topo.pop();
    }
  }

  printf("%d\n", ans);

  return 0;
}

