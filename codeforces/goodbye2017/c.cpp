#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=5e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, r, x[N];
ld top[N], ans[N];

int main(){
  scanf("%d %d", &n, &r);
  for(int i=0; i<n; i++) scanf("%d", &x[i]);

  for(int i=0; i<n; i++) {
    ld h = r;
    for(int j=-2*r; j<=2*r; j++) {
      int p = x[i]+j;
      if(p and top[p] > r-EPS) {
        double dist = j;
        double rad = r;
        ld ang = acos(dist/(rad*2));
        h = max(h, 2*rad * sin(ang) + top[p]);
      }
    }
    ans[i] = h;
    top[x[i]] = h;
  }

  for(int i=0; i<n; i++) printf("%.12Lf ", ans[i]);
  printf("\n");

	return 0;
}

