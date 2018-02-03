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

int n, v[N];
map<int, vi> m;
map<int, int> sz;

int main(){
  scanf("%d", &n);

  for(int i=1; i<=n; i++) {
    scanf("%d", &v[i]);
    m[v[i]].pb(i);
  }

  set<int> idxs;
  idxs.insert(0);
  idxs.insert(n+1);
  for(auto it : m) {
    set<int> new_idxs;
    for(auto i : it.second) {
      int s = 0;
      auto p = idxs.lower_bound(i);
      p--;
      s += i - *p;
      p = idxs.lower_bound(i);
      s += *p - i;
      sz[it.first] = max(sz[it.first], s-1);
      new_idxs.insert(i);
    }
    for(auto i : new_idxs) idxs.insert(i);
  }

  auto it = prev(sz.end());
  for(int i=1; i<=n; i++) {
    while(it->second < i) it = prev(it);
    printf("%d ", it->first);
  }
  printf("\n");

  return 0;
}

