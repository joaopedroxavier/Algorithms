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

int months_leap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int cur = 6;

bool leap(int i) {
  if(i == 0) return true;
  if(i % 100 == 0) return false;
  return i % 4 == 0;
}

string s, t;
map<string, int> week_day;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  cin >> s >> t;

  week_day["sunday"] = 0;
  week_day["monday"] = 1;
  week_day["tuesday"] = 2;
  week_day["wednesday"] = 3;
  week_day["thursday"] = 4;
  week_day["friday"] = 5;
  week_day["saturday"] = 6;

  for(int j=0; j<11; j++) {
    int nxt = (week_day[s] + months[j]) % 7;
    if(nxt == week_day[t]) return printf("YES\n"), 0;
  }

  printf("NO\n");

  return 0;
}

