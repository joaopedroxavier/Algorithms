//
//
//
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

ll n, f;
ll k[N], l[N];
ll profit[N], ord[N], vis[N], ans;

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n >> f;
  for(int i=0;i<n;++i){
    cin >> k[i] >> l[i];
    profit[i] = min(2*k[i], l[i]) - min(k[i], l[i]);
    ord[i] = i;
  }
  sort(ord, ord+n, [](int i, int j){ return profit[i] > profit[j]; });
  for(int i=0;i<f;++i){
    ans += min(k[ord[i]], l[ord[i]]) + profit[ord[i]];
    vis[ord[i]] = 1;
  }
  for(int i=0;i<n;++i) if(!vis[i]) ans += min(k[i], l[i]);
  cout << ans << endl;
  return 0;
}

