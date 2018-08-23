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

string s;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  cin >> s;

  int amt = 0;
  for(char c : s) if(c == '1') amt++;
  bool pr = false;
  for(char c : s) {
    if(c == '1') continue;
    if(c == '2' and !pr) {
      pr = true;
      while(amt--) cout << '1';
    }
    cout << c;
  }
  if(!pr) while(amt--) cout << '1';
  cout << endl;
	return 0;
}

