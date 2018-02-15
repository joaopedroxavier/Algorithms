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
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n;
ll g[N];
ll pref[N][20];

ll calcg(ll i) {
  if(i < 10) return i;
  if(~g[i]) return g[i];
  ll f = 1;
  while(i) {
    f *= (i%10 == 0 ? 1 : i%10);
    i /= 10;
  }
  return g[i] = calcg(f);
}

int main(){
  scanf("%d", &n);

  memset(g, -1, sizeof g);
  for(int i=1; i<N; i++) {
    ll gg = calcg(i);
    pref[i][gg] = 1;
  }

  for(int i=0; i<10; i++) {
    for(int j=1; j<N; j++) pref[j][i] += pref[j-1][i];
  }

  for(int i=0; i<n; i++) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    printf("%lld\n", pref[r][k] - pref[l-1][k]);
  }

	return 0;
}

