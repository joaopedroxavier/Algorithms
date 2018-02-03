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

ll n;
vector<ll> ans;

bool check(ll x) {
  ll ans = 0, cpy = x;
  while(x) ans += x%10, x/=10;
  return ans + cpy == n;
}

int main(){
  scanf("%lld", &n);

  for(ll i=max((ll)0,n-100); i<=n; i++) if(check(i)) ans.pb(i);

  printf("%d\n", (int)ans.size());
  for(auto i : ans) printf("%lld\n", i);

	return 0;
}

