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

vector<int> z_f(string &s) {
  int n = s.size();
  vector<int> z(n);
  int x = 0, y = 0;
  for(int i=1; i<n; i++) {
    z[i] = max(0, min(z[i-x], y-i+1));
    while(i + z[i] < n and s[z[i]] == s[i+z[i]]) {
      x = i; y = i+z[i]; z[i]++;
    }
  }
  return z;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; string s;
  cin >> n >> s;
  string cpy = s + s;
  s = cpy;

  vector<int> z = z_f(s);

  for(int i=1; i<n; i++) {
    if(z[i] >= n) continue;
    int j = z[i], k = (i + z[i]) % n;
    if(s[j] > s[k]) return cout << "No" << endl, 0;
  }
  cout << "Yes" << endl;
	return 0;
}

