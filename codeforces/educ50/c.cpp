//
// 내가 나인 게 싫은 날
// 영영 사라지고 싶은 날
// 문을 하나 만들자 너의 맘 속에다
// 그 문을 열고 들어가면
// 이 곳이 기다릴 거야
// 믿어도 괜찮아 널 위로해줄 magic shop
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 30;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

ll memo[N][N][2];

ll dp(ll i, ll j, string &s, bool k) {
  if(~memo[i][j][k]) return memo[i][j][k];
  if(i == 0 or j == 0) return 1;

  int sz = s.size();

  memo[i][j][k] = 0;
  int t = k ? 9 : s[sz-i] - '0';

  for(int p=0; p<=t; p++) {
    if(!k) {
      if(p < s[sz-i] - '0') {
        if(p == 0) memo[i][j][k] += dp(i-1, j, s, 1);
        else memo[i][j][k] += dp(i-1, j-1, s, 1);
      }
      else {
        if(p == 0) memo[i][j][k] += dp(i-1, j, s, k);
        else memo[i][j][k] += dp(i-1, j-1, s, k);
      }
    }
    else {
      if(p == 0) memo[i][j][1] += dp(i-1, j, s, 1);
      else memo[i][j][1] += dp(i-1, j-1, s, 1);
    }
  }

  return memo[i][j][k];
}

string tostring(ll x) {
  string ans;
  while(x) {
    ans.push_back('0' + x % 10);
    x /= 10;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;

  while(t--) {
    ll l, r; cin >> l >> r;
    string ls = tostring(l-1);
    string rs = tostring(r);

    //cout << ls << " " << rs << endl;
    memset(memo, -1, sizeof memo);
    int nl = ls.size();
    ll ansl = dp(nl, 3, ls, 0);

    memset(memo, -1, sizeof memo);
    int nr = rs.size();
    ll ansr = dp(nr, 3, rs, 0);

    cout << ansr - ansl << endl;
  }
  return 0;
}

