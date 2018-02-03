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

ll n, k;
ll d[] = {1, 0, 1, 2, 9};
ll binom[N][N];
ll ans;

int main(){
  scanf("%lld %lld", &n, &k);

  ans += d[0];
  if(k >= 1) ans += d[1]*n;
  if(k >= 2) ans += d[2]*(n*(n-1))/2;
  if(k >= 3) ans += d[3]*(n*(n-1)*(n-2))/6;
  if(k >= 4) ans += d[4]*(n*(n-1)*(n-2)*(n-3))/24;

  printf("%lld\n", ans);

	return 0;
}

