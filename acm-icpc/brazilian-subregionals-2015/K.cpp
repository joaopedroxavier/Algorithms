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

int dp[N][N], ans;
int spec[N], m;
string s;

int solve(int i, int j){
  if(i>j) return 0;
  else if(dp[i][j]) return dp[i][j];
  else if(s[i-1] == s[j-1]) dp[i][j] = solve(i+1,j-1) + (spec[i]+spec[j])*10000 + 2;
  else dp[i][j] = max(solve(i+1,j), solve(i,j-1));
  return dp[i][j];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin >> s;
  int n = s.size();
  cin >> m;
  for(int i=0;i<m;++i){
    int u;
    cin >> u;
    spec[u] = 1;
  }

  for(int i=1;i<=n;++i) dp[i][i] = spec[i]*10000 + 1;

  for(int j=1;j<=n;++j){
    for(int i=j-1;i>=1;--i){
      if(s[i-1] == s[j-1]){
          dp[i][j] = max(max(dp[i+1][j], dp[i][j-1]), dp[i+1][j-1] + (spec[i] + spec[j])*10000 + 2);
      }
      else{
        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
      }
    }
  }

// int a = solve(1,n);

//  for(int i=1;i<=n;++i){
//    for(int j=1;j<=n;++j) cout << dp[i][j] << '\t';
//    cout << endl;
//  }

  cout << dp[1][n]%10000 << endl;

  return 0;
}

