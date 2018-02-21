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
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int c, p, x, l;
int d[N], miss[N], lft[N];
vector<int> adj[N];

int main(){
  scanf("%d %d %d %d", &c, &p, &x, &l);

  for(int i=0; i<p; i++) {
    int u, v;
    scanf("%d %d", &u, &v);

    d[u]++, d[v]++;
    adj[u].pb(v), adj[v].pb(u);
  }

  queue<int> leaving;
  leaving.push(l);
  lft[l] = 1;

  while(!leaving.empty()) {
    int u = leaving.front();
    leaving.pop();

    for(int v : adj[u]) {
      miss[v]++;
      if(miss[v] >= (d[v]+1)/2 and !lft[v]) {
        lft[v] = 1;
        leaving.push(v);
      }
    }
  }

  printf("%s\n", lft[x] ? "leave" : "stay");

	return 0;
}

