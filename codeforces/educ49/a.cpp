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

bool fix(string &s) {
  int n = s.size();
  for(int i=0; i<n; i++) {
    char c = s[i], d = s[n-i-1];
    if(abs(c-d) != 0 and abs(c-d) != 2) return false;
  }
  return true;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;

  while(t--) {
    int n; string s;
    cin >> n >> s;
    cout << ((fix(s) ? "YES" : "NO")) << endl;
  }
	return 0;
}

