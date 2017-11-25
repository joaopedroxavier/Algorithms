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
const int INF=0x3f3f3f3f;

string s;
int dp[N];

int main(){
  cin >> s;
  int n = s.size();
  int ans = 0;
  for(int i = n-1; i>=0; i--) {
    dp[i] = dp[i+1] + (s[i] == '0');
    if(s[i] == '1') ans = max(ans, dp[i]);
  }

  printf("%s\n", ans >= 6 ? "yes" : "no");

	return 0;
}

