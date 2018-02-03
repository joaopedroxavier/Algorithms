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

int n, m;
int grid[N][N];
ll ans;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> grid[i][j];

  for(int i=0;i<n;i++){
    ll sum1 = 0, sum2 = 0;
    for(int j=0;j<m;j++) sum1 += (grid[i][j] == 0), sum2 += (grid[i][j] == 1);
    ans += (((ll)1)<<sum1) + (ll)(((ll)1)<<sum2) - 2;
  }

  for(int j=0;j<m;j++){
    ll sum1 = 0, sum2 = 0;
    for(int i=0;i<n;i++) sum1 += (grid[i][j] == 0), sum2 += (grid[i][j] == 1);
    ans += (((ll)1)<<sum1) + (ll)(((ll)1)<<sum2) - 2;
  }

  ll n1 = 0, n0 = 0;
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) (grid[i][j] == 1) ? n1++ : n0++;

  cout << ans - n1 - n0 << endl;
	return 0;
}

