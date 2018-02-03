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
const int M=1e9+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n; 
ii d[N];
set<int> vis;

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    d[i].first = v; d[i].second = u;
  }

  int ans = 0;
  for(int i=0; i<n; i++) {
    for(int j=d[i].second; j<M; j+=d[i].first) {
      if(!vis.empty() and j < *prev(vis.end())) { continue; }
      if(!vis.count(j)) {
        vis.insert(j);
        ans = max(ans, j);
        break;
      }
    }
  }

  printf("%d\n", ans);

	return 0;
}

