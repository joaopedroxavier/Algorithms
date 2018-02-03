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
const int N=5e3+5;
const int P=29;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll hsh[N], hshr[N];
bool pal[N][N];
ll dp[N][N];
ll ans[N];

void buildHash(string s){
  int n = s.size();
  for(int i=1;i<=n;++i){
    for(int j=1;j<=n-i+1;++j){
      if(i == 1) pal[j][j] = 1;
      else if(i == 2) pal[j][j+1] = (s[j-1] == s[j]);
      else pal[j][j+i-1] = (s[j-1] == s[j+i-2] and pal[j+1][j+i-2]);
    }
  }
}

bool check(string s, int i, int j, int k){
  if(dp[i][j] >= k) return true;
  if(j < i) return false;
  return pal[i][j] and check(s, i, (i+j-1)/2, k-1) and check(s, 1+(i+j)/2, j, k-1);
}

int main(){
	ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  buildHash(s);
  for(int i=1;i<=n;++i) dp[i][i] = 1, ans[0]++, ans[2]--;
  for(int i=2;i<=n;++i){
    for(int j=1;j<=n-i+1;++j){
      int l = j, r = j+i-1;
      dp[l][r] = ((pal[l][r]) ? 1+min(dp[l][(l+r-1)/2], dp[1+(l+r)/2][r]) : 0);
      ans[0]++, ans[dp[l][r]+1]--;
    }
  }
  for(int i=1;i<=n;++i){
    ans[i] += ans[i-1];
    cout << ans[i] << ' ';
  }
  cout << endl;

	return 0;
}

