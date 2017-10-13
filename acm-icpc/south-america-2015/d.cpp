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
const int N=1e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m, ans, sum[N];
int grid[N][N];

int main(){
  scanf("%d %d", &n, &m);

  for(int i=1; i<=m; i++) for(int j=0; j<=n; j++) scanf("%d", &grid[i][j]), sum[i] += (j > 1) * grid[i][j];

  vi v = {1, 10, 100, 1000, 10000};

  for(int i=1; i<=m; i++){
    int best = 0;
    for(int c : v) if(c + sum[i] <= grid[i][0]) best = c;
    ans += best - (sum[i] + grid[i][1] <= grid[i][0]) * grid[i][1];
  }
  
  printf("%d\n", ans);

	return 0;
}

