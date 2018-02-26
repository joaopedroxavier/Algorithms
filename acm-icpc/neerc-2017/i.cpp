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
const int N=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

vector<int> xzes, yzes;
int n, x[N], y[N], lenx[N], leny[N];
int maxx[N], maxy[N];
int minx[N], miny[N];

int main(){
  freopen("intel.in", "r", stdin);
  freopen("intel.out", "w", stdout);

  scanf("%d", &n);
  memset(minx, 63, sizeof minx);
  memset(miny, 63, sizeof miny);

  for(int i=0; i<n; i++) {
    scanf("%d %d", &x[i], &y[i]);

    xzes.pb(x[i]), yzes.pb(y[i]);
  }

  sort(xzes.begin(), xzes.end());
  auto it = unique(xzes.begin(), xzes.end());
  xzes.resize(it - xzes.begin());

  sort(yzes.begin(), yzes.end());
  auto jt = unique(yzes.begin(), yzes.end());
  yzes.resize(jt - yzes.begin());

  for(int i=0; i<n; i++) {
    x[i] = lower_bound(xzes.begin(), xzes.end(), x[i]) - xzes.begin();
    y[i] = lower_bound(yzes.begin(), yzes.end(), y[i]) - yzes.begin();
  }

  for(int i=0; i < (int) xzes.size() - 1; i++) {
    lenx[i] = xzes[i+1] - xzes[i];
  }

  for(int i=0; i < (int) yzes.size() - 1; i++) {
    leny[i] = yzes[i+1] - yzes[i];
  }

  for(int i=0; i<n; i++) {
    if(x[i] == x[(i+1)%n]) {
      //vertical
      int lo = min(y[i], y[(i+1)%n]);
      int hi = max(y[i], y[(i+1)%n]);

      for(int k=lo; k<hi; k++) {
        maxx[k] = max(maxx[k], x[i]);
        minx[k] = min(minx[k], x[i]);
      }
    }
    if(y[i] == y[(i+1)%n]) {
      //horizontal
      int lo = min(x[i], x[(i+1)%n]);
      int hi = max(x[i], x[(i+1)%n]);

      for(int k=lo; k<hi; k++) {
        maxy[k] = max(maxy[k], y[i]);
        miny[k] = min(miny[k], y[i]);
      }
    }
  }

  ll ans = 0;
  for(int i=0; i<n; i++) {
    //printf("from %d %d to %d %d:\n", x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
    if(x[i] == x[(i+1)%n]) {
      //vertical
      int lo = min(y[i], y[(i+1)%n]);
      int hi = max(y[i], y[(i+1)%n]);

      //printf("it's vertical from %d to %d with value %d and i'll sum ", lo, hi, x[i]);
      for(int k=lo; k<hi; k++) {
        if(x[i] < maxx[k] and x[i] > minx[k]) ans += leny[k]; // printf("%d ", leny[k]);
      }
      //printf("\n");
    }
    if(y[i] == y[(i+1)%n]) {
      //horizontal
      int lo = min(x[i], x[(i+1)%n]);
      int hi = max(x[i], x[(i+1)%n]);

      //printf("it's horizontal and i'll sum ");
      for(int k=lo; k<hi; k++) {
        if(y[i] < maxy[k] and y[i] > miny[k]) ans += lenx[k]; // printf("%d ", lenx[k]);
      }
      //printf("\n");
    }
  }

  printf("%lld\n", ans);


	return 0;
}

