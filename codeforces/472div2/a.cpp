#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

string s;
ll n;
bool dp[N][3], dp2[N][3];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  cin >> s;

  for(int i=0; i<n; i++) {
    if(s[i] == '?') {
      if(i == 0)
        dp[i][0] = dp[i][1] = dp[i][2] = true;
      else {
        dp[i][0] = dp[i-1][1] or dp[i-1][2];
        dp[i][1] = dp[i-1][0] or dp[i-1][2];
        dp[i][2] = dp[i-1][0] or dp[i-1][1];
        dp2[i][0] = dp2[i-1][1] or dp2[i-1][2] or (dp[i-1][1] and dp[i-1][2]);
        dp2[i][1] = dp2[i-1][0] or dp2[i-1][2] or (dp[i-1][0] and dp[i-1][2]);
        dp2[i][2] = dp2[i-1][1] or dp2[i-1][0] or (dp[i-1][1] and dp[i-1][0]);
      }
    }
    else {
      if(s[i] == 'M') {
        if(i != 0) {
          dp[i][0] = dp[i-1][1] or dp[i-1][2];
          dp2[i][0] = dp2[i-1][1] or dp2[i-1][2] or (dp[i-1][1] and dp[i-1][2]);
        }
        else dp[i][0] = 1;
      }
      if(s[i] == 'Y') {
        if(i != 0) {
          dp[i][1] = dp[i-1][0] + dp[i-1][2];
          dp2[i][1] = dp2[i-1][0] or dp2[i-1][2] or (dp[i-1][0] and dp[i-1][2]);
        }
        else dp[i][1] = 1;
      }
      if(s[i] == 'C') {
        if(i != 0) {
          dp[i][2] = dp[i-1][1] + dp[i-1][0];
          dp2[i][2] = dp2[i-1][1] or dp2[i-1][0] or (dp[i-1][1] and dp[i-1][0]);
        }
        else dp[i][2] = 1;
      }
    }
  }

  bool condition = dp2[n-1][0] or dp2[n-1][1] or dp2[n-1][2];
  condition = condition or (dp[n-1][0] and dp[n-1][1]);
  condition = condition or (dp[n-1][1] and dp[n-1][2]);
  condition = condition or (dp[n-1][2] and dp[n-1][0]);

  cout << (condition ? "Yes" : "No") << endl;

  return 0;
}

