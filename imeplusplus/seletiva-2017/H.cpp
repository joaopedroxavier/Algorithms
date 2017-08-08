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

int sum[N], dp[N];
int ans[N][20];
int p;

int main(){
  scanf("%d", &p);
  for(ll i=2;i<N;++i){
    if(!sum[i]){
      for(ll j=2*i;j<N;j+=i){
        sum[j] += i;
      }
    }
  }

  for(int i=1;i<N;++i) dp[i] = 1 + dp[sum[i]];
  for(int i=1;i<N;++i){
    for(int j=1;j<15;++j){
      ans[i][j] = ans[i-1][j] + (dp[i] == j);
    }
  }

  for(int q=0;q<p;++q){
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    printf("%d\n", (k >= 15) ? 0 : ans[b][k] - ans[a-1][k]);
  }
  return 0;
}

