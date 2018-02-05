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
const int N=5e4+5;
const int M=2e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int binom[N][M], stir[N][M];
int m;

int main(){
  scanf("%d", &m);

  binom[0][0] = 1, stir[0][0] = 1;
  for(int i=1; i<N; i++) {
    binom[i][0] = 1;
    stir[i][0] = 0;
    for(int j=1; j<min(i+1, M); j++) {
      binom[i][j] = (binom[i-1][j-1] + binom[i-1][j]) % MOD;
      stir[i][j] = (((ll)(i-1)*(ll)stir[i-1][j]) % MOD + stir[i-1][j-1]) % MOD;
    }
  }

  for(int i=0; i<m; i++) {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    ll term1 = stir[n-1][a+b-2];
    ll term2 = binom[a+b-2][a-1];

    printf("%lld\n", (term1 * term2) % MOD);
  }

	return 0;
}

