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

ll amounts[26], amountt[26], qm;
ll used[26];
string s, t;

bool check(ll m) {
  ll need = 0;
  for(int i=0; i<26; i++) {
    need += max(0ll, amountt[i] * m - amounts[i]);
  }
  return qm >= need;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s >> t;

  for(char c : s) {
    if(c != '?') {
      c -= 'a';
      amounts[c]++;
    }
    else {
      qm++;
    }
  }

  for(char c : t) {
    c -= 'a';
    amountt[c]++;
  }

  ll l=0, r=(ll)s.size();

  while(l < r) {
    ll m = (l+r+1)/2;
    if(check(m)) l=m;
    else r=m-1;
  }

  for(int i=0; i<26; i++) {
    used[i] = max(amountt[i] * l, amounts[i]);
  }

  int n = (int) s.size();
  string ans;
  for(int i=0; i<n; i++) ans.push_back('a');
  int p=0;

  for(int i=0; i<n; i++) {
    char c = s[i];
    if(c != '?') {
      ans[i] = s[i];
      used[c-'a']--;
    }
  }

  for(int i=0; i<n; i++) {
    char c = s[i];
    while(p < 26 and !used[p]) p++;
    if(c == '?') {
      if(p < 26 and used[p]) {
        ans[i] = 'a' + p;
        used[p]--;
      }
      else ans[i] = 'a';
    }
  }

  cout << ans << endl;

  return 0;
}

