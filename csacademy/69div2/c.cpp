#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define add(x,y) (x+y >= MOD ? x+y-MOD : x+y)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll, ll> pll;

const long double EPS = 1e-9;
const int N=3e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

string s;
int n; pll dp[N][N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  n = (int) s.size();

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) dp[i][j] = {-1, 0};
  }

  if(s[0] == ')') dp[0][1] = {1, 1};
  else dp[0][0] = dp[0][1] = {0, 1};

  for(int i=1; i<n; i++) {
    dp[i][0] = dp[i-1][1];
    if(s[i] == '(') dp[i][0].first++;

    for(int j=1; j<n; j++) {
      ll m1 = dp[i-1][j+1].first, m2 = dp[i-1][j-1].first;

      if(m1 == -1 and m2 == -1) continue;
      if(m1 == -1) m1 = INF;
      if(m2 == -1) m2 = INF;

      if(s[i] == '(') {
        if(m1+1 <= m2) dp[i][j] = dp[i-1][j+1], dp[i][j].first++;
        else dp[i][j] = dp[i-1][j-1];

        if(m1+1 == m2) dp[i][j].second = add(dp[i][j].second, dp[i-1][j-1].second);
      }
      if(s[i] == ')') {
        if(m2+1 <= m1) dp[i][j] = dp[i-1][j-1], dp[i][j].first++;
        else dp[i][j] = dp[i-1][j+1];

        if(m2+1 == m1) dp[i][j].second = add(dp[i][j].second, dp[i-1][j+1].second);
      }
    }
  }

  pll ans = dp[n-1][0];
  printf("%lld %lld\n", ans.first, ans.second);

  return 0;
}

