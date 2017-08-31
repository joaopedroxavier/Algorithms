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
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int tmp[N], aux[N];
int bet1[N], bet2[N], bet3[N], inv[N];
ll n, ans;

ll count_swt(int l, int r){
  ll x = 0;
  if(l >= r) return 0;
  x += count_swt(l, (l+r)/2);
  x += count_swt(1+(l+r)/2, r);
  int p1 = l, p2 = 1+(l+r)/2;
  for(int i=l;i<=r;i++){
    if(p2 > r) aux[i] = tmp[p1], p1++;
    else if(p1 > (l+r)/2) aux[i] = tmp[p2], p2++;
    else if(tmp[p1] < tmp[p2]) aux[i] = tmp[p1], p1++;
    else x += 1+(l+r)/2 - p1, aux[i] = tmp[p2], p2++;
  }
  for(int i=l;i<=r;i++) tmp[i] = aux[i];
  return x;
}

int main(){
  scanf("%lld", &n);
  for(int i=1;i<=n;i++) scanf("%d", &bet1[i]);
  for(int i=1;i<=n;i++) scanf("%d", &bet2[i]);
  for(int i=1;i<=n;i++) scanf("%d", &bet3[i]);

  for(int i=1;i<=n;i++) inv[bet1[i]] = i;
  for(int i=1;i<=n;i++) tmp[i] = inv[bet2[i]];
  ans += count_swt(1, n);

  for(int i=1;i<=n;i++) inv[bet2[i]] = i;
  for(int i=1;i<=n;i++) tmp[i] = inv[bet3[i]];
  ans += count_swt(1, n);

  for(int i=1;i<=n;i++) inv[bet3[i]] = i;
  for(int i=1;i<=n;i++) tmp[i] = inv[bet1[i]];
  ans += count_swt(1, n);

  printf("%lld\n", n*(n-1)/2 - ans/2);
  return 0;
}

