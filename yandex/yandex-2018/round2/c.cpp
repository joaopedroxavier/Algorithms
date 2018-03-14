#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

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

int n, m, ds, cs, da, ca;
multiset<int> health;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d %d %d %d %d", &n, &m, &ds, &cs, &da, &ca);
  for(int i=0; i<n; i++) {
    int h;
    scanf("%d", &h);
    health.insert(h);
  }

  int ans = 0;
  for(int i=0; i<100; i++) if(m - i*ca >= 0) {
    int mana = m - i*ca;
    multiset<int> cpy;
    int dead = 0;

    for(int j : health) {
      int h = j - i*da;
      if(h > 0) cpy.insert(h);
      else dead++;
    }

    while(mana >= cs) {
      if(cpy.empty()) break;
      int h = *cpy.begin();
      mana -= cs;
      h -= ds;
      cpy.erase(cpy.begin());
      if(h <= 0) {
        dead++;
      } else {
        cpy.insert(h);
      }
    }
    
    ans = max(ans, dead);
  }

  printf("%d\n", ans);
  return 0;
}

