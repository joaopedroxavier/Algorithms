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

int n, k;
int a[N], esq[N], dir[N], mi = INF, ma = -INF;

int main(){
  scanf("%d %d", &n, &k);

  for(int i=0; i<n; i++) {
    scanf("%d", &a[i]);
    mi = min(mi, a[i]);
    ma = max(ma, a[i]);
  }

  if(k == 1) return printf("%d\n", mi), 0;
  if(k > 2) return printf("%d\n", ma), 0;

  int ans = -INF;
  esq[0] = INF, dir[n] = INF;
  for(int i=1; i<n; i++) {
    esq[i] = min(esq[i-1], a[i-1]);
  }
  for(int i=n-1; i>0; i--) {
    dir[i] = min(dir[i+1], a[i]);
  }

  /*
  for(int i=1; i<n; i++) printf("%d ", esq[i]);
  printf("\n");
  for(int i=1; i<n; i++) printf("%d ", dir[i]);
  printf("\n");
  */

  for(int i=1; i<n; i++) ans = max(ans, max(esq[i], dir[i]));

  printf("%d\n", ans);


	return 0;
}

