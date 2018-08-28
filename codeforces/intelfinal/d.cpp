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

int n, m;
string s;
int used[N], bit[N];
set<int> st;

bool test(char c) {
  int cnt = 0;

  for(int i=0; i<m; i++) if(s[i] <= c) cnt++;
  bool comp = cnt > 0;

  for(int i=m; i<n; i++) {
    if(s[i-m] <= c) cnt--;
    if(s[i] <= c) cnt++;

    comp = comp and cnt > 0;
  }

  return comp;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> m >> s;
  n = (int) s.size();

  string answer;

  char last = 0;
  for(char c = 'a'; c <= 'z'; c++) {
    if(!test(c)) {
      for(int i=0; i<n; i++) if(s[i] == c) answer.push_back(c);
    }
    else { last = c; break; }
  }

  int cnt = 0, pos = -1;
  for(int i=0; i<m; i++) {
    if(s[i] < last) cnt++;
    if(s[i] == last) pos = i;
  }
  if(cnt == 0) {
    used[pos] = 1;
    answer.push_back(last);
    cnt++;
  }

  for(int i=m; i<n; i++) {
    if(s[i-m] < last) cnt--;
    if(s[i] == last) pos = i;
    if(s[i-m] == last and used[i-m]) cnt--;
    if(s[i] < last) cnt++;

    if(cnt == 0) {
      answer.push_back(last);
      used[pos] = 1;
      cnt++;
    }
  }

  cout << answer << endl;

  return 0;
}

