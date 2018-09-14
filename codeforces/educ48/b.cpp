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

const int N = 1e3+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

ll memo[N];
int n, m, q;
string s, t;

bool cp(int i, int j) {
  if(j-i+1 != (int) t.size()) return false;
  for(int k=i; k<=j; k++) if(s[k] != t[k-i]) return false;
  return true;
}

ll dp(int i) {
  if(~memo[i]) return memo[i];
  if(i < (int) t.size() - 1) return 0;

  memo[i] = dp(i-1);

  int sz = (int) t.size();
  if(cp(i-sz+1, i)) memo[i]++;

  return memo[i];
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  memset(memo, -1, sizeof memo);

  cin >> n >> m >> q;
  cin >> s >> t;

  for(int i=0; i<q; i++) {
    int l, r; cin >> l >> r;
    l--, r--;
    cout << max(0ll, dp(r) - dp(l+m-2)) << endl;
  }

	return 0;
}

