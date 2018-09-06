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

const int N = 4e5+5;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

bool ad[N];
ll val[N];

vector<ll> dknow;
set<ll> buys, sells;
ll bestbuy = -1, bestsell = LINF;
ll ans = 1;
int n;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for(int i=0; i<n; i++) {
    string s;
    cin >> s >> val[i];

    if(ans == 0) continue;

    if(s == "ADD") {
      if(val[i] < bestbuy)  buys.insert(val[i]);
      else if(val[i] > bestsell)  sells.insert(val[i]);
      else  dknow.push_back(val[i]);
    }
    else {
      if(val[i] < bestbuy or val[i] > bestsell) {
        ans = 0;
      }
      else if(val[i] == bestbuy)  buys.erase(val[i]);
      else if(val[i] == bestsell) sells.erase(val[i]);
      else {
        ans = (ans * 2ll) % MOD;
      }
      for(ll j : dknow) {
        if(j < val[i]) {
          buys.insert(j);
        }
        else if(j > val[i]) {
          sells.insert(j);
        }
      }
      dknow.clear();
    }

    if(!buys.empty()) bestbuy = *prev(buys.end());
    else bestbuy = -1;

    if(!sells.empty()) bestsell = *(sells.begin());
    else bestsell = LINF;
  }

  ll more = dknow.size() + 1;
  ans = (ans * more) % MOD;
  printf("%lld\n", ans);

  return 0;
}

