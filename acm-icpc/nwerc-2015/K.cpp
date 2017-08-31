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
const int N=5e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int r, s, m, d, n;
ll b[N], a[N][N], ans;
vi ds[N];

bool check(ll a, ll b){
  return b <= (ll)1e18/a+1;
}

int main(){
  scanf("%d %d %d %d %d", &r, &s, &m, &d, &n); 
  for(int i=1;i<=r;i++) scanf("%lld", &b[i]);

  for(int i=1;i<=s+m+d;i++){
    int k;
    scanf("%d", &k);
    for(int j=0;j<k;j++){
      int u;
      scanf("%d", &u);
      ds[i].pb(u);
    }
  }

  for(int i=1;i<=n;i++){
    int u, v;
    scanf("%d %d", &u, &v);
    a[u][v] = a[v][u] = -1;
  }

  for(int i=1;i<=s;i++){
    int t = ds[i].size();
    ll p = 1, sum = 0;
    set<int> usd;
    for(int l=0;l<t;l++){
      if(check(p, b[ds[i][l]]))
        p *= b[ds[i][l]], usd.insert(ds[i][l]);
      else return printf("too many\n"), 0;
    }
    for(int j=s+1;j<=s+m;j++){
      if(a[i][j] == -1) continue;
      int t2 = ds[j].size();
      ll p2 = 1, sum2 = 0;
      set<int> usd2;
      for(int l=0;l<t2;l++) if(!usd.count(ds[j][l])){
        if(check(p2, b[ds[j][l]]))
          p2 *= b[ds[j][l]], usd2.insert(ds[j][l]);
        else return printf("too many\n"), 0;
      }
      for(int k=s+m+1;k<=s+m+d;k++){
        if(a[i][k] == -1 or a[j][k] == -1) continue;
        int t3 = ds[k].size();
        ll p3 = 1;
        for(int l=0;l<t3;l++) if(!usd.count(ds[k][l]) and !usd2.count(ds[k][l])){
          if(check(p3, b[ds[k][l]]))
            p3 *= b[ds[k][l]];
          else return printf("too many\n"), 0;
        }
        sum2 += p3;
        if(sum2 > (ll)(1e18)) return printf("too many\n"), 0;
      }
      if(check(p2, sum2))
        sum += p2*sum2;
      else return printf("too many\n"), 0;
      if(sum > (ll)(1e18)) return printf("too many\n"), 0;
    }
    if(check(p, sum))
      ans += p*sum;
    else return printf("too many\n"), 0;
    if(ans > (ll)(1e18)) return printf("too many\n"), 0;
  }

  printf("%lld\n", ans);
  return 0;
}

