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

int n, m;
int v[N][2];
set<int> s1, s2;
vector<int> v1, v2;

int sum(int mask, int m, int fl) {
  ll ans = 0;
  for(int i=0; i<=19; i++) if((1<<i) & mask) {
    ans = (ans + v[i][fl]) % m;
  }
  return ans % m;
}

int main(){
  scanf("%d %d", &n, &m);

  for(int i=0; i<n/2; i++) scanf("%d", &v[i][0]), v[i][0] %= m;
  for(int i=n/2; i<n; i++) scanf("%d", &v[i-n/2][1]), v[i-n/2][1] %= m;

  for(int i=0; i<(1<<19); i++) s1.insert(sum(i, m, 0));
  for(int i=0; i<(1<<19); i++) s2.insert(sum(i, m, 1));

  for(auto it : s1) v1.pb(it);
  for(auto it : s2) v2.pb(it);

  int ans = 0;
  for(auto it : v1) {
    auto cp = prev(upper_bound(v2.begin(), v2.end(), m-it-1));
    ans = max(ans, it + *cp);
  }

  printf("%d\n", ans);

	return 0;
}

