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

int n, x;
int p = 1<<17;

int main(){
  scanf("%d %d", &n, &x);
  if(n == 2 and x == 0) return printf("NO\n"), 0;
  if(n == 2) return printf("YES\n%d %d\n", 0, x), 0;
  if(n == 1) return printf("YES\n%d\n", x), 0;

  printf("YES\n");

  int ans = 0;
  for(int i=1; i<=n-3; i++) printf("%d ", i), ans = ans ^ i;

  if(ans == x) printf("%d %d %d\n", p, 2*p, p ^ (2*p));
  else printf("%d %d %d\n", 0, p, p ^ x ^ ans);

	return 0;
}
