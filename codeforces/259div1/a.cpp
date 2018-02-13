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

int n, m;
ld prob = 1;

ld fexp(ld b, int e) {
  ld ans = 1;

  while(e) {
    if(e&1) ans = ans * b;
    b = b*b;
    e /= 2;
  }

  return ans;
}

int main(){
  scanf("%d %d", &m, &n);

  ld ans = 0;
  ld md = m;
  for(int i=0; i<m; i++) {
    ld term1 = i;
    term1 = term1 / md;
    term1 = 1 - term1;
    term1 = fexp(term1, n);
    ld term2 = i+1;
    term2 = term2 / md;
    term2 = 1 - term2;
    term2 = fexp(term2, n);
    
    ld term = term1 - term2;
    term = term * (md-(ld)i);
    ans += term;
  }

  printf("%.12Lf\n", ans);

	return 0;
}

