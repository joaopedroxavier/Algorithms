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

int a[N], b[N];
map<int, vector<int>> posa, posb;
int n, m;
int maxa, maxb;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  
  scanf("%d %d", &n, &m);

  for(int i=0; i<n; i++) {
    scanf("%d", &a[i]);
    maxa = max(maxa, a[i]);
    posa[a[i]].push_back(i);
  }
  for(int j=0; j<m; j++) {
    scanf("%d", &b[j]);
    maxb = max(maxb, b[j]);
    posb[b[j]].push_back(j);
  }

  ll sum = 0;
  if(posa[maxa].size() > 1) {
    int i = 0, j = 0;
    for(; a[i] != maxa; i++) {
      ll p = a[i], q = b[j];
      sum += p * ((ll) 1e9) * 1ll + q;
    }
    for(; b[j] != maxb; j++) {
      ll p = a[i], q = b[j];
      sum += p * ((ll) 1e9) * 1ll + q;
    }
    for(; i != posa[maxa].back(); i++) {
      ll p = a[i], q = b[j];
      sum += p * ((ll) 1e9) * 1ll + q;
    }
    for(; j < m; j++) {
      ll p = a[i], q = b[j];
      sum += p * ((ll) 1e9) * 1ll + q;
    }
    for(i=i+1, j=j-1; i < n; i++) {
      ll p = a[i], q = b[j];
      sum += p * ((ll) 1e9) * 1ll + q;
    }
    printf("%lld\n", sum);
  }
  else {
    int i = 0, j = 0;
    for(; a[i] != maxa; i++) {
      ll p = a[i], q = b[j];
      sum += p * ((ll) 1e9) * 1ll + q;
    }
    for(; j < m; j++) {
      ll p = a[i], q = b[j];
      sum += p * ((ll) 1e9) * 1ll + q;
    }
    for(i=i+1, j=j-1; i < n; i++) {
      ll p = a[i], q = b[j];
      sum += p * ((ll) 1e9) * 1ll + q;
    }
    printf("%lld\n", sum);
  }

	return 0;
}

