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

const int N = 5e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, a[N], ans[N], last[N];

int steps(int l, int r) {
  if(a[l] == a[r]) return (r-l+1)/2;
  else return (r-l+1)/2 - 1;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &a[i]);

  for(int i=0; i<n; i++) {
    ans[i] = 1;

    if(i and ans[i-1] > 1) ans[i] = ans[i-1] - 1;
    else {
      int p = i;
      while(p+1 < n and a[p+1] == (a[p] ^ 1)) ans[i]++, p++;
    }
  }

  int res = 0;
  for(int i=0; i<n; i++) {
    if(ans[i] > 1) {
      int l = i, r = i + ans[i] - 1;

      int st = steps(l, r);
      res = max(res, st);

      last[l] = a[l], last[r] = a[r];
      if(a[l] != a[r]) {
        for(int k=1; k<=st; k++) {
          last[l+k] = last[l];
        }
        for(int k=1; k<=st; k++) {
          last[r-k] = last[r];
        }
      }
      else {
        for(int k=l+1; k<r; k++) last[k] = last[l];
      }

      i = r;
    }
    else {
      last[i] = a[i];
    }
  }

  printf("%d\n", res);
  for(int i=0; i<n; i++) printf("%d ", last[i]);
  printf("\n");

  return 0;
}

