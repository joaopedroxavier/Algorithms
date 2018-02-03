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
const int N=1e5+5;
const int MOD=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;

bool cmp(string a, string b) {
  for(int i=0; i<(int)a.size(); i++) if(a[i] != b[i]) {
    return a[i] < b[i];
  }
  return true;
}

string rev(string s) { reverse(s.begin(), s.end()); return s; }

string s[N], r[N];
ll n, c[N], dp[N][2];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=1; i<=n; i++) cin >> c[i];
  for(int i=1; i<=n; i++) cin >> s[i];

  memset(dp, 63, sizeof dp);

  for(int i=1; i<=n; i++) r[i] = rev(s[i]);

  for(int i=1; i<=n; i++) {
    if(i == 1){ dp[i][0] = 0; dp[i][1] = c[i]; }
    else{
      bool lex1 = cmp(s[i-1], s[i]) and dp[i-1][0] < INF;
      if(lex1) dp[i][0] = min(dp[i][0], dp[i-1][0]);

      bool lex2 = cmp(r[i-1], s[i]) and dp[i-1][1] < INF; 
      if(lex2) dp[i][0] = min(dp[i][0], dp[i-1][1]);

      bool lex3 = cmp(s[i-1], r[i]) and dp[i-1][0] < INF; 
      if(lex3) dp[i][1] = min(dp[i][1], dp[i-1][0] + c[i]);

      bool lex4 = cmp(r[i-1], r[i]) and dp[i-1][1] < INF; 
      if(lex4) dp[i][1] = min(dp[i][1], dp[i-1][1] + c[i]);

      if(!(lex1 or lex2 or lex3 or lex4)) return printf("-1\n"), 0;
    }
  }

  printf("%lld\n", min(dp[n][0], dp[n][1]));

	return 0;
}

