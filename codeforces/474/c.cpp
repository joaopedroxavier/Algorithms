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

ll n, d;
vector<ll> ans;

void solve(ll m, ll least) {
  if(!m or ans.size() > 10000) return;
  ll p = 1;
  while((1ll<<p)-1 <= m) p++;
  p--;

  for(ll i=least; i<least+p; i++) {
    ans.push_back(least);
  }

  least+=d;
  solve(m-((1ll<<p)-1), least);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld", &n, &d);

  solve(n, 1);
  if(ans.size() > 10000) return printf("-1\n"), 0;

  printf("%d\n", (int) ans.size());
  for(ll i : ans) printf("%lld ", i);
  printf("\n");
	return 0;
}

