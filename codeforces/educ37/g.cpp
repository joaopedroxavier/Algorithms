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

const int N = 1e6+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

vector<int> pf[N];

int recover(vector<int> &v, int mask) {
  int ans = 1;
  for(int i=0; i<(int)v.size(); i++) if(mask & (1<<i)) {
    ans *= v[i];
  }
  return ans;
}

bool check(int m, int x, int p, int k) {
  int s = pf[p].size();

  int cnt1 = 0;
  int cnt2 = 0;
  for(int i=0; i<(1<<s); i++) {
    int nmb = recover(pf[p], i);
    int sgn = (__builtin_popcount(i) & 1) ? -1 : 1;

    cnt1 += sgn * (m / nmb);
    cnt2 += sgn * (x / nmb);
  }

  return cnt1-cnt2 >= k;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  for(int i=2; i<N; i++) if(pf[i].empty()) {
    pf[i].push_back(i);
    for(int j=2*i; j<N; j+=i) pf[j].push_back(i);
  }

  check(50, 0, 10, 5);

  int t; scanf("%d", &t);
  while(t--) {
    int x, p, k; scanf("%d %d %d", &x, &p, &k);
    int l=x, r=1e9;
    while(l < r) {
      int m=(l+r)/2;
      if(check(m, x, p, k)) r=m;
      else l=m+1;
    }
    printf("%d\n", l);
  }

	return 0;
}

