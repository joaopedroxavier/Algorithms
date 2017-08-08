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

ll esq[N], dir[N], s[N], h[N], x[N];
ll n, a, t;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> t;
  while(t--){
    cin >> a >> n;
    memset(h, 0, sizeof(h));

    for(int i=1;i<=n;++i) cin >> x[i];
    for(int i=0;i<=n;++i) cin >> h[i];

    for(int i=1;i<=n+1;++i){
      if(h[i-1] >= h[esq[i-1]]) esq[i] = i-1;
      else esq[i] = esq[i-1];
    }
    dir[n+1] = n+1;
    for(int i=n;i>=0;--i){
      if(h[i+1] >= h[dir[i+1]]) dir[i] = i+1;
      else dir[i] = dir[i+1];
    }
    for(int i=1;i<=n;++i) s[i] = s[i-1] + x[i];

    int p1 = esq[n+1], p2 = esq[n+1];
    ll ans = 0;
    while(p1 > 0){
      int p = esq[p1];
      ans += a*h[p]*(s[p1]-s[p]);
      p1 = p;
    }
    while(p2 < n){
      int p = dir[p2];
      ans += a*h[p]*(s[p]-s[p2]);
      p2 = p;
    }
    cout << ans << endl;
  }
	return 0;
}

