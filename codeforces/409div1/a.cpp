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
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ld p, a[N], b[N];
int n;

bool check(ld m) {
  ld need = 0;
  for(int i=0; i<n; i++) {
    need += min((ld)0, b[i] - m*a[i]);
  }
  return abs(need) <= p*m;
}

int main(){
  scanf("%d %Lf", &n, &p);

  for(int i=0; i<n; i++) scanf("%Lf %Lf", &a[i], &b[i]);

  ld sum = 0;
  for(int i=0; i<n; i++) sum += a[i];

  if(p >= sum) return printf("-1\n"), 0;

  ld l=0, r=1e18;
  for(int i=0; i<100; i++) {
    ld m = (l+r)/2;
    if(check(m)) l = m;
    else r = m;
  }

  printf("%.9Lf\n", l);

	return 0;
}

