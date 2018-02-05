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
const int N=1e4+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll a[N], b[N];
ll need, offer;
int n;

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%lld", &a[i]);
  for(int i=0; i<n; i++) scanf("%lld", &b[i]);

  int p = 0;
  while(a[p] <= b[p] and p < n) p++;

  for(int i=0; i<n; i++) {
    if(p == n) return printf("Yes\n"), 0;
    /*
    printf("There is a problem with index %d...\n", p);
    printf("%lld %lld\n", a[i], b[i]);
    */
    if(a[i] <= b[i]) {
      ll dif = b[i] - a[i];
      ll diff = dif/2;

      while(b[p] < a[p] and diff and p < n) {
        ll dif2 = a[p] - b[p];
        //printf("the current difference is %lld\n", dif2);
        b[p] = b[p] + min(diff, dif2);
        diff -= min(diff, dif2);
        while(a[p] <= b[p] and p < n) p++;
      }
      a[i] = b[i];
    }
  }

  printf("%s\n", p == n ? "Yes" : "No");

  return 0;
}

