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

ll cc[N], p[N], ct;
multiset<ll> qt;
ll n, x;

void dfs(int u, int x) {
  ct++;
  cc[u] = x;
  if(!cc[p[u]]) dfs(p[u], x);
}

int main(){
  scanf("%lld", &n);
  for(int i=1; i<=n; i++) scanf("%lld", &p[i]);

  for(int i=1; i<=n; i++) if(!cc[i]) x++, ct=0, dfs(i, x), qt.insert(ct);

  ll ans = 0;
  for(auto i : qt) ans += i*i;

  auto best = prev(qt.end());
  auto sBest = prev(best);
  if(qt.size() > 1) ans += 2 * (*best) * (*sBest); 

  printf("%lld\n", ans);

	return 0;
}

