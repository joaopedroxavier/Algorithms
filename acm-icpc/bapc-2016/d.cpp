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
const int N=4e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, t[N], dp[N];

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) scanf("%d", &t[i]);

  dp[0] = 0;

  for(int i=1; i<=n; i++) {
    dp[i] = INF;
    for(int k=1; k<=i; k++) {
      dp[i] = min(dp[i], dp[i-k] + max(t[i] - t[i-k+1] - 1800 + 20, 20*k) + 120);
    }
  }

  printf("%d\n", dp[n]);

	return 0;
}

