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
const int N=2e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n;
int a[N], g[N][N];

int gcd(int a, int b){ return b ? gcd(b, a%b) : a; }

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%d", &a[i]);

  for(int l=1; l<=n; l++) for(int r=l; r<=n; r++) {
    if (l == r) g[l][r] = a[l];
    else {
      g[l][r] = gcd(g[l][r-1], a[r]);
    }
  }

  if(g[1][n] > 1) return printf("-1\n"), 0;

  int c = 0;
  for(int i=1; i<=n; i++) c += (g[i][i] == 1);
  if(c) return printf("%d\n", n-c), 0;

  for(int s=0; s<=n; s++) {
    for(int i=1; i<=n-s; i++) if(g[i][i+s] == 1) return printf("%d\n", n + s - 1), 0;
  }
	return 0;
}

