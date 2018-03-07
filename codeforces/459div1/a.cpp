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

const int N = 5e3+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int more[N][N], lss[N][N];
int cnt[3][N];
string s;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  int n = (int) s.size();

  for(int i=0; i<n; i++) {
    if(s[i] == '(') cnt[0][i]++;
    if(s[i] == ')') cnt[1][i]++;
    if(s[i] == '?') cnt[2][i]++;
  }

  for(int i=1; i<n; i++) {
    cnt[0][i] += cnt[0][i-1];
    cnt[1][i] += cnt[1][i-1];
    cnt[2][i] += cnt[2][i-1];
  }

  for(int l=0; l<n; l++) {
    more[l][l] = (s[l] != ')');
    for(int r=l+1; r<n; r++) {
      int op = cnt[0][r] - (l ? cnt[0][l-1] : 0);
      int cl = cnt[1][r] - (l ? cnt[1][l-1] : 0);
      int qs = cnt[2][r] - (l ? cnt[2][l-1] : 0);

      more[l][r] = more[l][r-1] and (op + qs >= cl);
    }
  }

  for(int r=0; r<n; r++) {
    lss[r][r] = (s[r] != '(');
    for(int l=r-1; l >= 0; l--) {
      int op = cnt[0][r] - (l ? cnt[0][l-1] : 0);
      int cl = cnt[1][r] - (l ? cnt[1][l-1] : 0);
      int qs = cnt[2][r] - (l ? cnt[2][l-1] : 0);

      lss[l][r] = lss[l+1][r] and (cl + qs >= op);
    }
  }

  int ans = 0;
  for(int l=0; l<n; l++) {
    for(int r=l; r<n; r++) {
      ans += (more[l][r] and lss[l][r] and !((r-l+1)&1));
    }
  }

  printf("%d\n", ans);

  return 0;
}

