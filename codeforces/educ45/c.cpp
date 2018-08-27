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

map<int, vector<int>> cnt;

bool check(string &s) {
  int qt = 0, mi = 0;
  for(char c : s) {
    if(c == '(') {
      qt++;
    }
    else {
      qt--;
    }
    mi = min(mi, qt);
  }
  cnt[qt].push_back(mi);
  return true;
}

int n;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) {
    string s; cin >> s;
    check(s);
  }

  for(auto &p : cnt) sort(p.nd.begin(), p.nd.end());

  ll ans = 0;
  for(auto p : cnt) {
    int qt = p.st;
    for(int v : p.nd) {
      if(v >= 0 and cnt.count(-qt)) {
        ll term = cnt[-qt].end() - lower_bound(cnt[-qt].begin(), cnt[-qt].end(), -qt);
        ans += term;
      }
    }
  }

  printf("%lld\n", ans);
	return 0;
}

