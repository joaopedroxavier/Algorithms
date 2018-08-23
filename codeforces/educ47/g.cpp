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

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, m, cnt[6], ps[N][64];
int used[N], can[N][6];
string s;

string getmask(int m) {
  string ans;
  for(int j=5; j>=0; j--) if(m & (1<<j)) {
    ans.push_back('a'+j);
  }
  return ans;
}

bool check(int i, char c) {
  if(!cnt[c-'a'] or !can[i][c-'a']) return false;

  cnt[c-'a']--; bool ans = true;

  //printf("check %d %c: ", i, c);
  for(int m=0; m<64; m++) {
    int cnta = 0, cntb = 0;

    for(int j=0; j<6; j++) if(m & (1<<j)) {
      cnta += cnt[j];
    }
    cntb = ps[n][m] - ps[i][m];
    //printf("mask: %s, cntb: %d, cnta: %d\n", getmask(m).c_str(), cntb, cnta);
    ans = ans and cntb >= cnta;
  }
  //printf("%s\n", ans ? "y" : "n");
  //printf("\n");

  cnt[c-'a']++; return ans;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s; n = (int) s.size();
  cin >> m;

  for(int i=0; i<m; i++) {
    int pos; string t;
    cin >> pos >> t;

    used[pos] = true;
    for(char c : t) {
      can[pos][c-'a'] = true;
    }
  }

  for(int i=1; i<=n; i++) if(!used[i]) {
    used[i] = true;
    for(int j=0; j<6; j++) can[i][j] = true;
  }

  for(int mask=0; mask<64; mask++) {
    for(int j=1; j<=n; j++) {
      for(int k=0; k<6; k++) if(mask & (1<<k)) {
        ps[j][mask] = ps[j][mask] or can[j][k];
      }
    }
  }

  for(int i=1; i<=n; i++) for(int k=0; k<64; k++) ps[i][k] += ps[i-1][k];

  /*
  for(int i=1; i<=n; i++) {
    printf("%d: ", i);
    for(int j=0; j<6; j++) if(can[i][j]) printf("%c", 'a'+j);
    printf("\n");
  }
  */

  for(int i=1; i<=n; i++) {
    cnt[s[i-1]-'a']++;
  }

  /*
  for(int j=0; j<64; j++) {
    printf("%s: ", getmask(j).c_str());
    for(int i=1; i<=n; i++) printf("%d ", ps[i][j]);
    printf("\n");
  }
  */

  for(int i=1; i<=n; i++) {
    bool cont = false;
    for(char c = 'a'; c <= 'f'; c++) if(check(i, c)) {
      cont = true;
      cnt[c-'a']--;
      s[i-1] = c;
      break;
    }
    if(!cont) return printf("Impossible\n"), 0;
  }

  cout << s << endl;

	return 0;
}

