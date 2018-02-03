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

int a[N], b[N];
int t[N], l[N], r[N];
int n, q, m;

int main(){
  scanf("%d %d %d", &n, &q, &m);
  for(int i=1; i<=n; i++) scanf("%d", &a[i]);
  for(int i=1; i<=q; i++) scanf("%d %d %d", &t[i], &l[i], &r[i]);
  for(int i=1; i<=m; i++) scanf("%d", &b[i]);

  for(int i=1; i<=m; i++) {
    int p = b[i];
    for(int j=q; j>0; j--) {
      if(p >= l[j] and p <= r[j]) {
        if(t[j] == 2) {
          p = r[j] - p + l[j];
        }
        else {
          if(p == l[j]) p = r[j];
          else p--;
        }
      }
    }
    printf("%d ", a[p]);
  }
  printf("\n");

  return 0;
}

