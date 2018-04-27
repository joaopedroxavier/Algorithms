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

int n, dp[N];
string s;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  cin >> s;

  dp[0] = 1;
  for(int i=1; i<(int)s.size(); i++) {
    if(s[i] != s[i-1]) {
      dp[i] = min(1 + dp[i-1], 1 + dp[i-2]);
    } else {
      dp[i] = dp[i-1] + 1;
    }
  }

  cout << dp[(int)s.size() - 1] << endl;

	return 0;
}

