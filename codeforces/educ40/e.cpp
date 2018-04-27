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

const int N = 2e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n; ld temp;
ld a[N], t[N], c[N];
ld currTemp = 0;
vector<int> low, hi;

bool eq(ld x, ld y) { return abs(x - y) < EPS; }

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %Lf", &n, &temp);

  ld ans = 0;
  for(int i=0; i<n; i++) {
    scanf("%Lf", &a[i]);
  }
  for(int i=0; i<n; i++) {
    scanf("%Lf", &t[i]);
    if(t[i] < temp - EPS) low.push_back(i);
    else if(eq(t[i], temp)) ans += a[i];
    else hi.push_back(i);
  }

  if((low.empty() or hi.empty()) and eq(ans, 0.0000000)) return printf("0.00000000\n"), 0;

  sort(low.begin(), low.end(), [](int i, int j) { return t[i] > t[j]; });
  sort(hi.begin(), hi.end(), [](int i, int j) { return t[i] < t[j]; });

  for(int i=0; i<(int)low.size(); i++) {
    t[low[i]] = temp - t[low[i]];
  }

  for(int i=0; i<(int)hi.size(); i++) {
    t[hi[i]] = t[hi[i]] - temp;
  }

  int l=0, h=0;
  ld sum1 = 0;
  for(h=0; h<(int)hi.size(); h++) {
    int idxh = hi[h];
    int idxl = low[l];
    if(l < (int)low.size()) {
      if(a[idxl] >= t[idxh] * a[idxh] / t[idxl]) {
        ld amount = t[idxh] * a[idxh] / t[idxl];
        a[idxl] -= amount;
        sum1 += a[idxh];
        sum1 += amount;
      } else {
        ld amount = t[idxl] * a[idxl] / t[idxh];
        a[idxh] -= amount;
        sum1 += amount;
        sum1 += a[idxl];
        l++;
        h--;
      }
    }
  }

  l = 0;
  ld sum2 = 0;
  for(l=0; l<(int)low.size(); l++) {
    int idxh = hi[h];
    int idxl = low[l];
    if(h < (int)hi.size()) {
      if(a[idxh] >= t[idxl] * a[idxl] / t[idxh]) {
        ld amount = t[idxl] * a[idxl] / t[idxh];
        a[idxh] -= amount;
        sum2 += a[idxl];
        sum2 += amount;
      } else {
        ld amount = t[idxh] * a[idxh] / t[idxl];
        a[idxl] -= amount;
        sum2 += amount;
        sum2 += a[idxh];
        h++;
        l--;
      }
    }
  }

  ans += max(sum1, sum2);

  printf("%.20Lf\n", ans);
	return 0;
}
