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
const int N=3e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

priority_queue<pair<ll,ll>> s;
ll n, k;
ll v[N], ans[N];
ll cost;

int main(){
  scanf("%lld %lld", &n, &k);
  for(int i=1; i<=n; i++) scanf("%lld", &v[i]);

  for(int i=1; i<=k; i++) s.push(mp(v[i], i));

  for(int i=1; i<=n; i++) {
    if(k+i <= n) s.push(mp(v[k+i], (k+i)));
    ll m = s.top().second;
    s.pop();
    ans[m] = i;
    cost += v[m] * (k+i-m);
  }

  printf("%lld\n", cost);
  for(int i=1; i<=n; i++) {
    printf("%lld ", ans[i]+k);
  }
  printf("\n");

	return 0;
}

