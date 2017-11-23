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

int n, ct;
ll y[N], ig[N];
set<ll> c[3];

void build(int l, int r){
  ll k = y[r]-y[l];
//  printf("%d %d %d: \n", ct, l, r);
  for(int i=1;i<=n;i++){
    if(i == l or i == r){ ig[i] = 1; continue; }
    if( (y[i]-y[l]) * (((r - l) % 2) ? 1 : 2) == k * (i-l)) ig[i] = 1;
  }
  for(int i=1;i<=n;i++) if(!ig[i]){
    c[ct].insert(k*(i-l) - (y[i] - y[l]) * (((r-l)%2) ? 1 : 2));
//    printf("%d %lld\n", i, k*(i-l) - (y[i] - y[l]) * (((r-l)%2) ? 1 : 2));
  }
  ct++;
}

int main(){
  scanf("%d", &n);
  for(int i=1;i<=n;i++) scanf("%lld", &y[i]);
  build(1, 2);
  memset(ig, 0, sizeof ig);
  build(2, 3);
  memset(ig, 0, sizeof ig);
  build(1, 3);
  /*
  for(int i=0;i<3;i++){
    printf("%d: ", i);
    for(auto it : c[i]) printf("%lld ", it);
    printf("\n");
  }
  */
  printf("%s\n", (c[0].size() != 1 and c[1].size() != 1 and c[2].size() != 1) ? "No" : "Yes");
	return 0;
}

