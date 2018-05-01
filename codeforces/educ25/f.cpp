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

const int N = 8e3+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, dp[N], lp[N][N];//p[N][N], lp[N][N];
int test[N];
string s;

int numdigits(int k) {
  if(k == 0) return 0;
  int a = 1, ans = 0;
  while(a <= k) a *= 10, ans++;
  return ans;
}

vector<int> p[N];

vector<int> prefix_function(string s) {
  int n = (int) s.size();
  vector<int> pi(n, 0);

  for(int i=1; i<n; i++) {
    int j = pi[i-1];
    while(j > 0 and s[i] != s[j])
      j = pi[j-1];
    if(s[i] == s[j])
      j++;
    pi[i] = j;
  }

  return pi;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  n = s.size();

  for(int i=0; i<n; i++) {
    string t = s.substr(i);
    p[i] = prefix_function(t);
  }

  for(int i=0; i<n; i++) {
    lp[i][i] = 1;
    for(int j=i+1; j<n; j++) {
      int k = j-i;
      int t = k+1;
      if(t % (t - (p[i][k])) == 0) {
        lp[i][j] = t - p[i][k];
      } else {
        lp[i][j] = t;
      }
    }
  }

  dp[0] = 2;
  for(int i=1; i<n; i++) {
    dp[i] = INF;
    for(int j=0; j<i; j++) {
      dp[i] = min(dp[i], dp[j] + lp[j+1][i] + numdigits((i-j) / lp[j+1][i]));
    }
    dp[i] = min(dp[i], lp[0][i] + numdigits((i+1) / lp[0][i]));
  }

  cout << dp[n-1] << endl;

	return 0;
}

