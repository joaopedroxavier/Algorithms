#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

// 0 = right
// 1 = up
// 2 = left
// 3 = down

int n, dir[N], ans[N], turn[N];
int cur[4];

int main() {
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);

  int d = 0;
  dir[0] = 0;
  for(int i=0; i<n; i++) {
    int l; scanf("%d %d", &l, &turn[i]);
    if(i == 0) continue;

    dir[i] = (dir[i-1] + turn[i-1] + 4) % 4;
  }

  for(int i=n-1; i>=0; i--) {
    int d = (dir[i] + 2) % 4;
    ans[i] = cur[(d+2)%4] + 1;

    cur[d] += cur[(d+2)%4] + 1;
    cur[(d+2)%4] = 0;
  }

  for(int i=0; i<n; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
