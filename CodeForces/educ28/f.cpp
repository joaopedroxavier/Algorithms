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
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll n, a[N], f[N];
vector<int> pos[N];

int main(){
  scanf("%lld", &n);
  for(int i=1; i<N; i++) pos[i].pb(0);

  for(int i=1; i<=n; i++) {
    scanf("%lld", &a[i]);
    pos[a[i]].pb(i);
  }

  double ans = 0;
  for(int i=1; i<=n; i++) {
    auto it = lower_bound(pos[a[i]].begin(), pos[a[i]].end(), i);
    ll f = *(it-1);
    ans += (i-f)*(n-i+1)*2 - 1;
  }

  double pairs = (n*n);

  ans /= pairs;
  printf("%.6f\n", ans);

	return 0;
}

